// -*- C++ -*-

//=============================================================================
/******************************************************************************
**  @file   DTSMainWindow.h
**
**  @description
**      界面-主界面
******************************************************************************/
//=============================================================================

#ifndef __DTSMAINWINDOW_H__
#define __DTSMAINWINDOW_H__


#include "GDefine.h"
#include "ui_DTSMainWindow.h"
#include <Windows.h>
#include "WTaskWebService.h"
#include "WTaskUpload.h"
#include "WTaskDownload.h"

class DTSMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    DTSMainWindow(const QString& appName, QWidget *parent = Q_NULLPTR);

public:
    GERROR Initialize();
    GERROR UnInitialize();

public slots:
    void Slot_Action_triggered_Exit();
    void Slot_Action_triggered_Show();
    void Slot_Action_triggered_SysConfig();
    void Slot_Action_triggered_RunConfig();
    void Slot_Action_triggered_SynConfig();
    void Slot_QSystemTrayIcon_activated(QSystemTrayIcon::ActivationReason reason);
    void Slot_Custom_sendMsg(const QString& strMsg);

protected:
    virtual bool event(QEvent *event);

private:
    QBool CheckAppSingle();

private:
    Ui::DTSMainWindow   m_ui;
    QSystemTrayIcon     m_pSystemTray;
    QMenu               m_pTrayMenu;
    HANDLE              m_hSingleInstMutex;
    QScopedPointer<WTaskWebService> m_wTaskWebService;
    QScopedPointer<WTaskUpload>     m_wTaskUpload;
    QScopedPointer<WTaskDownload>   m_WTaskSynch;
};

#endif

