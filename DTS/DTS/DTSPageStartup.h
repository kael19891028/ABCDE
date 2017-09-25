// -*- C++ -*-

//=============================================================================
/******************************************************************************
**  @file   DTSPageStartup.h
**
**  @description
**      ΩÁ√Ê-∆Ù∂Ø“≥
******************************************************************************/
//=============================================================================

#ifndef __DTSPAGESTARTUP_H__
#define __DTSPAGESTARTUP_H__

#include "GDefine.h"
#include "ui_DTSPageStartup.h"

class DTSPageStartup : public QDialog
{
    Q_OBJECT

public:
    DTSPageStartup(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~DTSPageStartup();

public:
    QString GetAppID();

public slots:
    void Slot_PushButton_Clicked_Start();
    void Slot_PushButton_Clicked_Create();
    void Slot_PushButton_Clicked_Delete();

private:
    void initUI();

private:
    Ui::DTSPageStartup  m_ui;
    QString             m_strAppID;
};

#endif