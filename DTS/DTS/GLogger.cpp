#include "GDefine.h"


QStringList GLogger::t_LogStr = QStringList() << STR_GLOGGER_DBG_CHS << STR_GLOGGER_INF_CHS << STR_GLOGGER_WAR_CHS << STR_GLOGGER_ERR_CHS;

GLogger& GLogger::Instance() {
    static GLogger inst;
    return inst;
}

void GLogger::OutputMessage(QtMsgType type, const QMessageLogContext &context, const QString& msg)
{
    QUInt32 curLevel = DEFAULT_APP_LG_DLVL;
    switch (type) 
    {
    case QtDebugMsg:
        curLevel = GLOGGER_DBG;
        break;
    case QtInfoMsg:
        curLevel = GLOGGER_INF;
        break;
    case QtWarningMsg:
        curLevel = GLOGGER_WAR;
        break;
    case QtCriticalMsg:
    default:
        curLevel = GLOGGER_ERR;
        break;
    }

    if (curLevel < qConfig->m_tRunConfig.LG_DLVL)
    {
        return;
    }

    QString message = QString("%1 %2 %3")
            .arg(QDateTime::currentDateTime().toString(STR_TIMEFORMAT_YYYY_MM_DD_HH_MM_SS_ZZZ))
            .arg(t_LogStr[curLevel])
            .arg(msg);

    qLogger->putq(message);
}


void GLogger::CheckDir()
{
    QDir dir(qConfig->m_tRunConfig.LG_PATH);
    dir.mkdir(STR_COMB_DIR_LOCAL);
}

void GLogger::RenameFile()
{
    QString strOldName = qConfig->m_tRunConfig.LG_PATH + qConfig->m_tRunConfig.LG_NAME;
    QString strNewName = strOldName + QDateTime::currentDateTime().toString(STR_TIMEFORMAT_YYYYMMDDHHMMSS);
    QFile::rename(strOldName, strNewName);

    QDir dir(qConfig->m_tRunConfig.LG_PATH);
    QStringList entryList = dir.entryList(QStringList() << qConfig->m_tRunConfig.LG_NAME + STR_CHAR_STAR);
    QInt32 num = entryList.size() - qConfig->m_tRunConfig.LG_MCNT;
    if (num > 0)
    {
        for (int i = 0; i < num; ++i)
        {
            QFile::remove(qConfig->m_tRunConfig.LG_PATH + entryList[i]);
        }
    }
}




GLogger::GLogger(QObject *parent)
    : QThread(parent)
{
    QObject::connect(this, SIGNAL(putMsg()), this, SLOT(Slot_putMsg()), Qt::DirectConnection);

    GLogger::CheckDir();

    m_fsWrite.open((qConfig->m_tRunConfig.LG_PATH + qConfig->m_tRunConfig.LG_NAME).toStdString(), std::ios::app | std::ios::out);
}

GLogger::~GLogger()
{
    if (this->isRunning())
    {
        this->terminate();
    }
}

GERROR GLogger::Initialize()
{
    qInstallMessageHandler(GLogger::OutputMessage);

    this->start();

    return GERROR_OK;
}



void GLogger::run()
{
    while (true)
    {
        exec();
    }
}

void GLogger::Slot_putMsg()
{
    QString strMsg;
    if (getq(strMsg))
    {
        writeLog(strMsg);

        emit sendMsg(strMsg);
    }
}

QBool GLogger::putq(QString strMsg)
{
    if (true)
    {
        QMutexLocker lock(&m_mx4queue);

        m_queue.push_back(strMsg);
    }

    emit putMsg();

    return true;
}

QBool GLogger::getq(QString& strMsg)
{
    QMutexLocker lock(&m_mx4queue);

    if (m_queue.size())
    {
        strMsg = m_queue.front();
        m_queue.pop_front();
        return true;
    }
    return false;
}

void GLogger::writeLog(const QString& strMsg)
{
    std::lock_guard<std::mutex> lock(m_mx4Write);

    // TODO: 公共参数多线程不安全
    if (m_fsWrite.is_open())
    {
        if (m_fsWrite.tellg() > qConfig->m_tRunConfig.LG_MSIZ * MB)
        {
            m_fsWrite.close();

            GLogger::RenameFile();

            m_fsWrite.open((qConfig->m_tRunConfig.LG_PATH + qConfig->m_tRunConfig.LG_NAME).toStdString(), std::ios::app | std::ios::out);
        }

        m_fsWrite << strMsg.toStdString() << std::endl;
        m_fsWrite.flush();
    }

}


