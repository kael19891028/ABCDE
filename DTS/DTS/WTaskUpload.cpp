// -*- C++ -*-

//=============================================================================
/******************************************************************************
**  @file   WTaskUpload.cpp
**
**  @description
**      任务-生产数据上传
**
**  @history
**  001     2017/09/22      weiheng     创建该文档
******************************************************************************/
//=============================================================================

#include "WTaskUpload.h"


WTaskUpload::WTaskUpload(QObject *parent)
    : QThread(parent)
    , m_bStop(true)
{
    m_cSQLDBWorkshop = QSqlDatabase::addDatabase(STR_SQL_CONNECT_TQODBC, STR_SQL_CONNECT_TQODBC_WS_DNLD);
}

WTaskUpload::~WTaskUpload()
{
    if (this->isRunning())
    {
        this->terminate();
    }
}

GERROR WTaskUpload::Initialize()
{
    qInfo() << STR_TASK_UPLOAD_INITIALIZE_BEGIN;

    QString dsn = STR_SQL_CONNECT_TQODBC_MSSQL_STR
        .arg(qConfig->m_tSysConfig.DB_Addr)
        .arg(qConfig->m_tSysConfig.DB_Port)
        .arg(qConfig->m_tSysConfig.DB_User)
        .arg(qConfig->m_tSysConfig.DB_Pass)
        .arg(qConfig->m_tSysConfig.DB_Name);

    m_cSQLDBWorkshop.setDatabaseName(dsn);

    qDebug() << STR_TASK_UPLOAD_INITIALIZE_SQLSTR.arg(dsn);

    if (!m_cSQLDBWorkshop.open())
    {
        qWarning() << STR_TASK_UPLOAD_INITIALIZE_OPEN;
        return GERROR_TASK_SQLOPEN;
    }

    qInfo() << STR_TASK_WEBSERVICE_INITIALIZE_END;
    return GERROR_OK;
}

GERROR WTaskUpload::Stop()
{
    QMutexLocker lock(&m_mutexRun);
    m_bStop = true;

    return GERROR_OK;
}

void WTaskUpload::run()
{
    qInfo() << STR_TASK_UPLOAD_RUN_BEGIN.arg((QUInt32)QThread::currentThreadId());

    QThread::sleep(qConfig->m_tRunConfig.TM_FDND);

    m_bStop = false;
    int nCount = 0;
    while (true)
    {
        if(true)
        {
            QMutexLocker lock(&m_mutexRun);
            if (m_bStop)
            {
                break;
            }
        } 

        if (++nCount % qConfig->m_tRunConfig.TM_UPLD == 0)
        {
            Task_Upload();
        }

        QThread::sleep(1);
    }

    qWarning() << STR_TASK_UPLOAD_RUN_END.arg((QUInt32)QThread::currentThreadId());
}

void WTaskUpload::Task_Upload()
{
    qDebug() << STR_TASK_UPLOAD_TASK_BEGIN;

    QSqlQuery query(m_cSQLDBWorkshop);

    for (TMAPNAMINGTBL_IT it = qNaming->m_tTBLDnld.begin(); it != qNaming->m_tTBLDnld.end(); ++it)
    {
        if (query.exec(qNaming->m_tSQL[it.value()]))
        {
            qDebug() << query.value(0).toInt();
        }
    }
}

