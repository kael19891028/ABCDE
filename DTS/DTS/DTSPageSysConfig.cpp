// -*- C++ -*-

//=============================================================================
/******************************************************************************
**  @file   DTSPageSysConfig.cpp
**
**  @description
**      界面-系统参数配置
**
**  @history
**  001     2017/09/22      weiheng     创建该文档
******************************************************************************/
//=============================================================================

#include "DTSPageSysConfig.h"
#include "DTSMessageBox.h"

DTSPageSysConfig::DTSPageSysConfig(const TSYSCONFIG& config, QWidget *parent, Qt::WindowFlags f)
    : QDialog(parent)
    , m_tSysConfig(config)
{
    m_ui.setupUi(this);
    this->setWindowTitle(STR_UI_MAINWINDOW_SYSCONFIG);
    this->setWindowIcon(QIcon(STR_PICTURE_ACTION_SYSCONFIG));
    this->setWindowFlags(Qt::WindowTitleHint | Qt::WindowCloseButtonHint);


    QObject::connect(m_ui.m_pbCreate, SIGNAL(clicked()), this, SLOT(Slot_PushButton_clicked_Create()));
    QObject::connect(m_ui.m_pbCancel, SIGNAL(clicked()), this, SLOT(Slot_PushButton_clicked_Cancel()));
    QObject::connect(m_ui.m_pbUseDef, SIGNAL(clicked()), this, SLOT(Slot_PushButton_clicked_UseDef()));
    QObject::connect(m_ui.m_pbTestWS, SIGNAL(clicked()), this, SLOT(Slot_PushButton_clicked_TestWS()));
    QObject::connect(m_ui.m_pbTestDB, SIGNAL(clicked()), this, SLOT(Slot_PushButton_clicked_TestDB()));
    QObject::connect(m_ui.m_leAppID, SIGNAL(editingFinished()), this, SLOT(Slot_LineEdit_editingFinished_App()));
    QObject::connect(m_ui.m_leAppName, SIGNAL(editingFinished()), this, SLOT(Slot_LineEdit_editingFinished_App()));

    initUI();
}

DTSPageSysConfig::~DTSPageSysConfig()
{
}

void DTSPageSysConfig::Slot_PushButton_clicked_Create()
{
    qDebug() << "Slot_PushButton_clicked_Create";

    if (m_ui.m_leAppID->text().isEmpty()
        || m_ui.m_leAppName->text().isEmpty()
        || m_ui.m_leWSAddr->text().isEmpty()
        || m_ui.m_leWSPort->text().isEmpty()
        || m_ui.m_leDBAddr->text().isEmpty()
        || m_ui.m_leDBPort->text().isEmpty()
        || m_ui.m_leDBUser->text().isEmpty()
        || m_ui.m_leDBPass->text().isEmpty()
        || m_ui.m_leDBName->text().isEmpty())
    {
        return;
    }

    m_tSysConfig.App_IID = m_ui.m_leAppID->text();
    m_tSysConfig.AppName = m_ui.m_leAppName->text();
    m_tSysConfig.WS_Addr = m_ui.m_leWSAddr->text();
    m_tSysConfig.WS_Port = m_ui.m_leWSPort->text().toInt();
    m_tSysConfig.DB_Addr = m_ui.m_leDBAddr->text();
    m_tSysConfig.DB_Port = m_ui.m_leDBPort->text().toInt();
    m_tSysConfig.DB_User = m_ui.m_leDBUser->text();
    m_tSysConfig.DB_Pass = m_ui.m_leDBPass->text();
    m_tSysConfig.DB_Name = m_ui.m_leDBName->text();

    if (STR_UI_SYSCONFIG_BUTTON_CREATE == m_ui.m_pbCreate->text())
    {
        if (qConfig->CheckAppID(m_tSysConfig.App_IID))
        {
            m_ui.m_lblCheckApp->setPixmap(QPixmap(STR_PICTURE_RES_ERROR));
            return;
        }
        qConfig->CreateApp(m_tSysConfig);

        DTSMessageBox msgBox(DTSMessageBox::EMBTYPE_CREATECONFIRM);
        msgBox.exec();
    }
    else
    {
        DTSMessageBox msgBox(DTSMessageBox::EMBTYPE_SAVECONFIRM);
        msgBox.exec();
    }

    this->close();
}

void DTSPageSysConfig::Slot_PushButton_clicked_Cancel()
{
    qDebug() << "Slot_PushButton_clicked_Cancel";

    this->close();
}

void DTSPageSysConfig::Slot_PushButton_clicked_UseDef()
{
    qDebug() << "Slot_PushButton_clicked_UseDef";

    QString strAppID = m_tSysConfig.App_IID;
    QString strAppName = m_tSysConfig.AppName;
    m_tSysConfig = TSYSCONFIG();
    m_tSysConfig.App_IID = strAppID;
    m_tSysConfig.AppName = strAppName;

    initUI();
}

void DTSPageSysConfig::Slot_PushButton_clicked_TestWS()
{
    qDebug() << "Slot_PushButton_clicked_TestWS";

    m_ui.m_lblCheckWS->setPixmap(QPixmap());

    QTcpServer server;
    QString strPic = server.listen(QHostAddress(m_ui.m_leWSAddr->text()), m_ui.m_leWSPort->text().toInt()) ? STR_PICTURE_RES_OK : STR_PICTURE_RES_ERROR;
    server.close();

    m_ui.m_lblCheckWS->setPixmap(QPixmap(strPic));
}

void DTSPageSysConfig::Slot_PushButton_clicked_TestDB()
{
    qDebug() << "Slot_PushButton_clicked_TestDB";

    m_ui.m_lblCheckDB->setPixmap(QPixmap());

    QSqlDatabase sql = QSqlDatabase::addDatabase(STR_SQL_CONNECT_TQODBC);

    QString dsn = STR_SQL_CONNECT_TQODBC_MSSQL_STR
        .arg(m_ui.m_leDBAddr->text())
        .arg(m_ui.m_leDBPort->text().toInt())
        .arg(m_ui.m_leDBUser->text())
        .arg(m_ui.m_leDBPass->text())
        .arg(m_ui.m_leDBName->text());
    sql.setDatabaseName(dsn);

    QString strPic = sql.open() ? STR_PICTURE_RES_OK : STR_PICTURE_RES_ERROR;
    sql.close();

    m_ui.m_lblCheckDB->setPixmap(QPixmap(strPic));
}

void DTSPageSysConfig::Slot_LineEdit_editingFinished_App()
{
    qDebug() << "Slot_LineEdit_editingFinished_App";

    m_ui.m_lblCheckApp->setPixmap(QPixmap());

    if (m_ui.m_leAppID->text().isEmpty()
        || m_ui.m_leAppName->text().isEmpty())
    {
        return;
    }

    QString strPic = STR_PICTURE_RES_OK;
    if (STR_UI_SYSCONFIG_BUTTON_CREATE == m_ui.m_pbCreate->text())
    {
        if (qConfig->CheckAppID(m_ui.m_leAppID->text()))
        {
            strPic = STR_PICTURE_RES_ERROR;
        }
    }
    m_ui.m_lblCheckApp->setPixmap(QPixmap(strPic));
}

void DTSPageSysConfig::initUI()
{
    if (m_tSysConfig.App_IID.isEmpty())
    {
        m_ui.m_pbCreate->setText(STR_UI_SYSCONFIG_BUTTON_CREATE);
        m_ui.m_leAppID->setText(STR_CHAR_EMPTY);
        m_ui.m_leAppID->setDisabled(false);
        m_ui.m_leAppName->setText(STR_CHAR_EMPTY);
        m_ui.m_lblTipsWS->hide();
    }
    else
    {
        m_ui.m_pbCreate->setText(STR_UI_SYSCONFIG_BUTTON_SAVE);
        m_ui.m_leAppID->setText(m_tSysConfig.App_IID);
        m_ui.m_leAppID->setDisabled(true);
        m_ui.m_leAppName->setText(m_tSysConfig.AppName);
        m_ui.m_lblTipsWS->show();
    }
    m_ui.m_leWSAddr->setText(m_tSysConfig.WS_Addr);
    m_ui.m_leWSPort->setText(QString::number(m_tSysConfig.WS_Port));
    
    m_ui.m_leDBAddr->setText(m_tSysConfig.DB_Addr);
    m_ui.m_leDBPort->setText(QString::number(m_tSysConfig.DB_Port));
    m_ui.m_leDBUser->setText(m_tSysConfig.DB_User);
    m_ui.m_leDBPass->setText(m_tSysConfig.DB_Pass);
    m_ui.m_leDBName->setText(m_tSysConfig.DB_Name);

    m_ui.m_lblCheckApp->setPixmap(QPixmap());
    m_ui.m_lblCheckWS->setPixmap(QPixmap());
    m_ui.m_lblCheckDB->setPixmap(QPixmap());

}