// -*- C++ -*-

//=============================================================================
/******************************************************************************
**  @file   GConfig.cpp
**
**  @description
**      公用配置类
**
**  @history
**  001     2017/09/22      weiheng     创建该文档
******************************************************************************/
//=============================================================================

#include "GDefine.h"


GConfig& GConfig::Instance()
{
    static GConfig inst;

    return inst;
}

GConfig::GConfig()
{
    QSettings::setPath(QSettings::IniFormat, QSettings::UserScope, DEFALUT_APP_CG_PATH);
}

GConfig::~GConfig()
{
}

GERROR GConfig::Initialize()
{
    /// 检查状态
    if (m_Settings.status() != QSettings::NoError)
    {
        qCritical() << "Application cannot open regedit! Error=" << m_Settings.status();
        return GERROR_SYSTEM_REGEDIT_ERROR;
    }

    /// 删除非法项
    for each (const QString& key in m_Settings.childGroups())
    {
        if (m_Settings.value(STR_COMB_KEY_VALUE.arg(key).arg(STR_CONFIG_SYS_APPNAME)).isNull())
        {
            m_Settings.remove(key);
            m_Settings.sync();
        }
    }

    return GERROR_OK;
}

GERROR GConfig::ReadConfig()
{
    m_Settings.beginGroup(m_tSysConfig.App_IID);
    m_tSysConfig.AppName = m_Settings.value(STR_CONFIG_SYS_APPNAME, STR_CHAR_EMPTY).toString();
    m_tSysConfig.WS_Addr = m_Settings.value(STR_CONFIG_SYS_WS_ADDR, DEFAULT_APP_WS_ADDR).toString();
    m_tSysConfig.WS_Port = m_Settings.value(STR_CONFIG_SYS_WS_PORT, DEFAULT_APP_WS_PORT).toInt();
    m_tSysConfig.DB_Addr = m_Settings.value(STR_CONFIG_SYS_DB_ADDR, DEFAULT_APP_DB_ADDR).toString();
    m_tSysConfig.DB_Port = m_Settings.value(STR_CONFIG_SYS_DB_PORT, DEFAULT_APP_DB_PORT).toInt();
    m_tSysConfig.DB_User = m_Settings.value(STR_CONFIG_SYS_DB_USER, DEFAULT_APP_DB_USER).toString();
    m_tSysConfig.DB_Pass = m_Settings.value(STR_CONFIG_SYS_DB_PASS, DEFAULT_APP_DB_PASS).toString();
    m_tSysConfig.DB_Name = m_Settings.value(STR_CONFIG_SYS_DB_NAME, DEFAULT_APP_DB_NAME).toString();

    m_tRunConfig.App_IID = m_tSysConfig.App_IID;
    m_tRunConfig.LG_ENAB = m_Settings.value(STR_CONFIG_RUN_LG_ENAB, DEFAULT_APP_LG_ENAB).toBool();
    m_tRunConfig.LG_PATH = m_Settings.value(STR_CONFIG_RUN_LG_PATH, DEFAULT_APP_LG_PATH).toString();
    m_tRunConfig.LG_NAME = m_Settings.value(STR_CONFIG_RUN_LG_NAME, DEFAULT_APP_LG_NAME).toString();
    m_tRunConfig.LG_MCNT = m_Settings.value(STR_CONFIG_RUN_LG_MCNT, DEFAULT_APP_LG_MCNT).toInt();
    m_tRunConfig.LG_MSIZ = m_Settings.value(STR_CONFIG_RUN_LG_MSIZ, DEFAULT_APP_LG_MSIZ).toInt();
    m_tRunConfig.LG_DLVL = m_Settings.value(STR_CONFIG_RUN_LG_DLVL, DEFAULT_APP_LG_DLVL).toInt();
    m_tRunConfig.TM_UPLD = m_Settings.value(STR_CONFIG_RUN_TM_UPLD, DEFAULT_APP_TM_UPLD).toInt();
    m_tRunConfig.TM_FUPD = m_Settings.value(STR_CONFIG_RUN_TM_FUPD, DEFAULT_APP_TM_FUPD).toInt();
    m_tRunConfig.TM_DNLD = m_Settings.value(STR_CONFIG_RUN_TM_SYNC, DEFAULT_APP_TM_SYNC).toInt();
    m_tRunConfig.TM_FDND = m_Settings.value(STR_CONFIG_RUN_TM_FSYN, DEFAULT_APP_TM_FSYN).toInt();
    m_Settings.endGroup();

    return GERROR_OK;
}

QBool GConfig::CheckAppID(const QString& strAppID)
{
    return m_Settings.childGroups().contains(strAppID);
}

void GConfig::SetAppID(const QString& strAppID)
{
    m_tSysConfig.App_IID = strAppID;
}

void GConfig::GetAllApp(TAPPLIST& config)
{
    config.clear();

    for each (const QString& key in m_Settings.childGroups())
    {
        QString var = m_Settings.value(STR_COMB_KEY_VALUE.arg(key).arg(STR_CONFIG_SYS_APPNAME)).toString();
        if (!var.isEmpty())
        {
            config.insert(key, var);
        }
    }
}

void GConfig::CreateApp(const TSYSCONFIG& config)
{
    m_Settings.beginGroup(config.App_IID);
    m_Settings.setValue(STR_CONFIG_SYS_APPNAME, config.AppName);
    m_Settings.setValue(STR_CONFIG_SYS_WS_ADDR, config.WS_Addr);
    m_Settings.setValue(STR_CONFIG_SYS_WS_PORT, config.WS_Port);
    m_Settings.setValue(STR_CONFIG_SYS_DB_ADDR, config.DB_Addr);
    m_Settings.setValue(STR_CONFIG_SYS_DB_PORT, config.DB_Port);
    m_Settings.setValue(STR_CONFIG_SYS_DB_USER, config.DB_User);
    m_Settings.setValue(STR_CONFIG_SYS_DB_PASS, config.DB_Pass);
    m_Settings.setValue(STR_CONFIG_SYS_DB_NAME, config.DB_Name);
    m_Settings.endGroup();
    m_Settings.sync();

    QDir dir(config.App_IID);
    if (!dir.exists())
    {
        dir.mkdir(STR_COMB_DIR_LOCAL);
    }
    QFile fileNamingSQL(DEFAULT_APP_NS_FILE);
    fileNamingSQL.copy(STR_COMB_KEY_VALUE.arg(config.App_IID).arg(DEFAULT_APP_NS_FILE));

    QFile fileNamingTBL(DEFAULT_APP_NT_FILE);
    fileNamingTBL.copy(STR_COMB_KEY_VALUE.arg(config.App_IID).arg(DEFAULT_APP_NT_FILE));
}

void GConfig::DeleteApp(const QString& strAppID)
{
    m_Settings.remove(strAppID);
    m_Settings.sync();

    QDir dir(strAppID);
    if (dir.exists())
    {
        dir.removeRecursively();
    }
}

void GConfig::SetRunConfig(const TRUNCONFIG& config)
{
    m_Settings.beginGroup(config.App_IID);
    m_Settings.setValue(STR_CONFIG_RUN_LG_ENAB, config.LG_ENAB);
    m_Settings.setValue(STR_CONFIG_RUN_LG_PATH, config.LG_PATH);
    m_Settings.setValue(STR_CONFIG_RUN_LG_NAME, config.LG_NAME);
    m_Settings.setValue(STR_CONFIG_RUN_LG_MCNT, config.LG_MCNT);
    m_Settings.setValue(STR_CONFIG_RUN_LG_MSIZ, config.LG_MSIZ);
    m_Settings.setValue(STR_CONFIG_RUN_LG_DLVL, config.LG_DLVL);
    m_Settings.setValue(STR_CONFIG_RUN_TM_UPLD, config.TM_UPLD);
    m_Settings.setValue(STR_CONFIG_RUN_TM_FUPD, config.TM_FUPD);
    m_Settings.setValue(STR_CONFIG_RUN_TM_SYNC, config.TM_DNLD);
    m_Settings.setValue(STR_CONFIG_RUN_TM_FSYN, config.TM_FDND);
    m_Settings.endGroup();
    m_Settings.sync();

    m_tRunConfig = config;
    if (m_tRunConfig.LG_ENAB)
    {
        qInstallMessageHandler(GLogger::OutputMessage);
    }
    else
    {
        qInstallMessageHandler(Q_NULLPTR);
    }
    qLogger->CheckDir();
}