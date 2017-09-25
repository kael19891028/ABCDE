// -*- C++ -*-

//=============================================================================
/******************************************************************************
**  @file   GConfig.h
**
**  @description
**      π´”√≈‰÷√¿‡
******************************************************************************/
//=============================================================================

#ifndef __GCONFIG_H__
#define __GCONFIG_H__

#include "GDefine.h"

class GConfig
{
public:
    static GConfig& Instance();

private:
    GConfig();
    ~GConfig();

public:
    GERROR Initialize();
    GERROR ReadConfig();

public:
    QBool CheckAppID(const QString& strAppID);
    void SetAppID(const QString& strAppID);
    void GetAllApp(TAPPLIST& config);

    void CreateApp(const TSYSCONFIG& config);
    void DeleteApp(const QString& strAppID);
    void SetRunConfig(const TRUNCONFIG& config);

public:
    TSYSCONFIG     m_tSysConfig;
    TRUNCONFIG     m_tRunConfig;

private:
    QSettings   m_Settings;
};

#endif
