// -*- C++ -*-

//=============================================================================
/******************************************************************************
**  @file   DTSPageSysConfig.h
**
**  @description
**      界面-系统参数配置
******************************************************************************/
//=============================================================================

#ifndef __DTSPAGERUNCONFIG_H__
#define __DTSPAGERUNCONFIG_H__

#include "GDefine.h"
#include "ui_DTSPageRunConfig.h"

class DTSPageRunConfig : public QDialog
{
    Q_OBJECT

public:
    DTSPageRunConfig(const TRUNCONFIG& config = TRUNCONFIG(), QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~DTSPageRunConfig();

public slots:
    void Slot_PushButton_clicked_Create();
    void Slot_PushButton_clicked_Cancel();
    void Slot_PushButton_clicked_Select();
    void Slot_PushButton_clicked_UseDef();

private:
    void initUI();

private:
    Ui::DTSPageRunConfig    m_ui;
    TRUNCONFIG              m_tRunConfig;
};

#endif