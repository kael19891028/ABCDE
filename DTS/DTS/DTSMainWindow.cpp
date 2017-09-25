// -*- C++ -*-

//=============================================================================
/******************************************************************************
**  @file   DTSMainWindow.cpp
**
**  @description
**      界面-主界面
**
**  @history
**  001     2017/09/22      weiheng     创建该文档
******************************************************************************/
//=============================================================================

#include "DTSMainWindow.h"
#include "DTSPageSysConfig.h"
#include "DTSPageRunConfig.h"
#include "DTSPageSynConfig.h"
#include "DTSMessageBox.h"


DTSMainWindow::DTSMainWindow(const QString& strAppID, QWidget *parent)
    : QMainWindow(parent)
    , m_pSystemTray(this)
    , m_pTrayMenu((QWidget*)QApplication::desktop())
    , m_hSingleInstMutex(NULL)
    , m_wTaskWebService(new WTaskWebService(this))
    , m_wTaskUpload(new WTaskUpload(this))
    , m_WTaskSynch(new WTaskDownload(this))
{
    m_ui.setupUi(this);

    this->centralWidget();
    this->setWindowIcon(QIcon(STR_PICTURE_MAIN));


    m_pTrayMenu.addAction(m_ui.m_ActionSysConfig);
    m_pTrayMenu.addAction(m_ui.m_ActionRunConfig);
    m_pTrayMenu.addAction(m_ui.m_ActionSynConfig);
    m_pTrayMenu.addSeparator();
    m_pTrayMenu.addAction(m_ui.m_ActionShow);
    m_pTrayMenu.addAction(m_ui.m_ActionExit);

    m_pSystemTray.setIcon(QIcon(STR_PICTURE_MAIN_RUN));
    m_pSystemTray.setContextMenu(&m_pTrayMenu);


    QObject::connect(&m_pSystemTray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(Slot_QSystemTrayIcon_activated(QSystemTrayIcon::ActivationReason)));
    QObject::connect(m_ui.m_ActionExit, SIGNAL(triggered()), this, SLOT(Slot_Action_triggered_Exit()));
    QObject::connect(m_ui.m_ActionShow, SIGNAL(triggered()), this, SLOT(Slot_Action_triggered_Show()));
    QObject::connect(m_ui.m_ActionSysConfig, SIGNAL(triggered()), this, SLOT(Slot_Action_triggered_SysConfig()));
    QObject::connect(m_ui.m_ActionRunConfig, SIGNAL(triggered()), this, SLOT(Slot_Action_triggered_RunConfig()));
    QObject::connect(m_ui.m_ActionSynConfig, SIGNAL(triggered()), this, SLOT(Slot_Action_triggered_SynConfig()));
    QObject::connect(m_ui.m_pbExit, SIGNAL(clicked()), this, SLOT(Slot_Action_triggered_Exit()));
    QObject::connect(m_ui.m_pbSysConfig, SIGNAL(clicked()), this, SLOT(Slot_Action_triggered_SysConfig()));
    QObject::connect(m_ui.m_pbRunConfig, SIGNAL(clicked()), this, SLOT(Slot_Action_triggered_RunConfig()));
    QObject::connect(m_ui.m_pbSynConfig, SIGNAL(clicked()), this, SLOT(Slot_Action_triggered_SynConfig()));
    QObject::connect(qLogger, SIGNAL(sendMsg(const QString&)), this, SLOT(Slot_Custom_sendMsg(const QString&)), Qt::QueuedConnection);

    qConfig->SetAppID(strAppID);
}

GERROR DTSMainWindow::Initialize()
{
    qInfo() << STR_MAINWINDOW_INITIALIZE_BEGIN;
    /// 应用名必须在注册表中且不能被其他程序占用
    if (qConfig->m_tSysConfig.App_IID.isEmpty())
    {
        qCritical() << STR_MAINWINDOW_INITIALIZE_NOAPPID;
        return GERROR_APP_INVALID_NAME;
    }

    if (!qConfig->CheckAppID(qConfig->m_tSysConfig.App_IID))
    {
        qCritical() << STR_MAINWINDOW_INITIALIZE_NOTINREG;
        return GERROR_SYSTEM_REGEDIT_NOTFOUND;
    }
    qInfo() << STR_MAINWINDOW_INITIALIZE_APPIDIS.arg(qConfig->m_tSysConfig.App_IID);
    if (!CheckAppSingle())
    {
        qCritical() << STR_MAINWINDOW_INITIALIZE_APPALRDRUN;
        return GERROR_APP_ALREADY_RUN;
    }
    if (GERROR_OK != qConfig->ReadConfig())
    {
        qCritical() << STR_MAINWINDOW_INITIALIZE_RDCONFIGERR;
        return GERROR_SYSTEM_REGEDIT_NOTFOUND;
    }
    qInfo() << STR_MAINWINDOW_INITIALIZE_CREATEMUTEX;
    if (GERROR_OK != qNaming->Initialize(qConfig->m_tSysConfig.App_IID))
    {
        qCritical() << "Application read config failed";
        return GERROR_APP_TASKNS_ERROR;
    }

    /// 界面
    this->setWindowTitle(qConfig->m_tSysConfig.AppName);
    this->m_pSystemTray.setToolTip(qConfig->m_tSysConfig.AppName);

    
    /// 启动任务
    if (GERROR_OK != m_wTaskWebService->Initialize())
    {
        qCritical() << STR_MAINWINDOW_INITIALIZE_TASKWSERROR;
        return GERROR_APP_TASKWS_ERROR;
    }
    if (GERROR_OK != m_wTaskUpload->Initialize())
    {
        qCritical() << STR_MAINWINDOW_INITIALIZE_TASKULERROR;
        return GERROR_APP_TASKUL_ERROR;
    }
    if (GERROR_OK != m_WTaskSynch->Initialize())
    {
        qCritical() << STR_MAINWINDOW_INITIALIZE_TASKSNERROR;
        return GERROR_APP_TASKUL_ERROR;
    }

    m_wTaskWebService->start();
    m_wTaskUpload->start();
    m_WTaskSynch->start();

    qInfo() << STR_MAINWINDOW_INITIALIZE_END;
    return GERROR_OK;
}

GERROR DTSMainWindow::UnInitialize()
{
    m_wTaskWebService->Stop();
    m_wTaskUpload->Stop();
    m_WTaskSynch->Stop();

    if (m_hSingleInstMutex)
    {
        CloseHandle(m_hSingleInstMutex);
        m_hSingleInstMutex = NULL;
    }
    return GERROR_OK;
}

void DTSMainWindow::Slot_Action_triggered_Exit()
{
    qDebug() << "Slot_Action_triggered_Logout";
    
    DTSMessageBox msgBox(DTSMessageBox::EMBTYPE_QUITCONFIRM);
    if (msgBox.exec() == QMessageBox::Cancel)
    {
        return;
    }

    QApplication::quit();
}

void DTSMainWindow::Slot_Action_triggered_Show()
{
    qDebug() << "Slot_Action_triggered_Show";

    this->m_pSystemTray.hide();
    this->show();
}

void DTSMainWindow::Slot_Action_triggered_SysConfig()
{
    qDebug() << "Slot_Action_triggered_SysConfig";

    DTSPageSysConfig w(qConfig->m_tSysConfig);
    w.exec();
}

void DTSMainWindow::Slot_Action_triggered_RunConfig()
{
    qDebug() << "Slot_Action_triggered_RunConfig";

    DTSPageRunConfig w(qConfig->m_tRunConfig);
    w.exec();
}

void DTSMainWindow::Slot_Action_triggered_SynConfig()
{
    qDebug() << "Slot_Action_triggered_SyncConfig";

    DTSPageSynConfig w(qConfig->m_tSysConfig.App_IID);
    w.exec();
}

void DTSMainWindow::Slot_QSystemTrayIcon_activated(QSystemTrayIcon::ActivationReason reason)
{
    qDebug() << "Slot_QSystemTrayIcon_activated";

    switch (reason)
    {
    case QSystemTrayIcon::DoubleClick:
        Slot_Action_triggered_Show();
        break;
    case QSystemTrayIcon::Trigger:
    case QSystemTrayIcon::MiddleClick:
    case QSystemTrayIcon::Context:
        break;
    default:
        break;
    }
}

void DTSMainWindow::Slot_Custom_sendMsg(const QString& strMsg)
{
    m_ui.m_lteLog->appendPlainText(strMsg);
}

bool DTSMainWindow::event(QEvent *event)
{
    switch (event->type())
    {
    case QEvent::Close:
        this->hide();
        this->m_pSystemTray.show();
        event->ignore();
        return true;
    }
    return QWidget::event(event);
}

QBool DTSMainWindow::CheckAppSingle()
{
    HANDLE m_hSingleInstMutex = CreateMutex(NULL, TRUE, qConfig->m_tSysConfig.App_IID.toStdWString().c_str());
    if (m_hSingleInstMutex == NULL)
    {
        return false;
    }
    if (::GetLastError() == ERROR_ALREADY_EXISTS)
    {
        CloseHandle(m_hSingleInstMutex);
        m_hSingleInstMutex = NULL;
        return false;
    }
    return true;
}


