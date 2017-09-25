// -*- C++ -*-

//=============================================================================
/******************************************************************************
**  @file   DTSPageRunConfig.h
**
**  @description
**      界面-运行参数配置
******************************************************************************/
//=============================================================================

#ifndef __DTSPAGESYSCONFIG_H__
#define __DTSPAGESYSCONFIG_H__

#include "GDefine.h"
#include "ui_DTSPageSysConfig.h"

class DTSPageSysConfig : public QDialog
{
    Q_OBJECT

public:
    DTSPageSysConfig(const TSYSCONFIG& config = TSYSCONFIG(), QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~DTSPageSysConfig();

public slots:
    void Slot_PushButton_clicked_Create();
    void Slot_PushButton_clicked_Cancel();
    void Slot_PushButton_clicked_UseDef();
    void Slot_PushButton_clicked_TestWS();
    void Slot_PushButton_clicked_TestDB();
    void Slot_LineEdit_editingFinished_App();

private:
    void initUI();

private:
    Ui::DTSPageSysConfig    m_ui;
    TSYSCONFIG              m_tSysConfig;
};

#endif