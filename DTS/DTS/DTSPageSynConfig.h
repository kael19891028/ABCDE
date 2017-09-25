// -*- C++ -*-

//=============================================================================
/******************************************************************************
**  @file   DTSPageStartup.h
**
**  @description
**      ΩÁ√Ê-∆Ù∂Ø“≥
******************************************************************************/
//=============================================================================

#ifndef __DTSPAGESYNCONFIG_H__
#define __DTSPAGESYNCONFIG_H__

#include "GDefine.h"
#include "ui_DTSPageSynConfig.h"

class DTSPageSynConfig : public QDialog
{
    Q_OBJECT

public:
    DTSPageSynConfig(const QString& strAppID, QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~DTSPageSynConfig();

public slots:
    void Slot_PushButton_clicked_Save();
    void Slot_PushButton_clicked_Cancel();

private:
    void initUI();

private:
    Ui::DTSPageSynConfig    m_ui;
    QString                 m_strAppID;
};

#endif