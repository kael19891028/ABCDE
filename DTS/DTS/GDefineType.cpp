// -*- C++ -*-

//=============================================================================
/******************************************************************************
**  @file   GDefineType.cpp
**
**  @description
**      公用类型定义
**
**  @history
**  001     2017/09/22      weiheng     创建该文档
******************************************************************************/
//=============================================================================

#include "GDefine.h"


TSYSCONFIG::TSYSCONFIG()
    : App_IID(STR_CHAR_EMPTY)
    , AppName(STR_CHAR_EMPTY)
    , WS_Addr(DEFAULT_APP_WS_ADDR)
    , WS_Port(DEFAULT_APP_WS_PORT)
    , DB_Addr(DEFAULT_APP_DB_ADDR)
    , DB_Port(DEFAULT_APP_DB_PORT)
    , DB_User(DEFAULT_APP_DB_USER)
    , DB_Pass(DEFAULT_APP_DB_PASS)
    , DB_Name(DEFAULT_APP_DB_NAME)
{

}

TSYSCONFIG::TSYSCONFIG(const TSYSCONFIG& other)
{
    App_IID = other.App_IID;
    AppName = other.AppName;
    WS_Addr = other.WS_Addr;
    WS_Port = other.WS_Port;
    DB_Addr = other.DB_Addr;
    DB_Port = other.DB_Port;
    DB_User = other.DB_User;
    DB_Pass = other.DB_Pass;
    DB_Name = other.DB_Name;
}

TSYSCONFIG& TSYSCONFIG::operator=(const TSYSCONFIG& other)
{
    App_IID = other.App_IID;
    AppName = other.AppName;
    WS_Addr = other.WS_Addr;
    WS_Port = other.WS_Port;
    DB_Addr = other.DB_Addr;
    DB_Port = other.DB_Port;
    DB_User = other.DB_User;
    DB_Pass = other.DB_Pass;
    DB_Name = other.DB_Name;

    return *this;
}

//void TSYSCONFIG::clear()
//{
//    App_IID = STR_EMPTY;
//    AppName = STR_EMPTY;
//
//    WS_Addr = DEFAULT_APP_WS_ADDR;
//    WS_Port = DEFAULT_APP_WS_PORT;
//
//    DB_Addr = DEFAULT_APP_DB_ADDR;
//    DB_Port = DEFAULT_APP_DB_PORT;
//    DB_User = DEFAULT_APP_DB_USER;
//    DB_Pass = DEFAULT_APP_DB_PASS;
//    DB_Name = DEFAULT_APP_DB_NAME;
//}


TRUNCONFIG::TRUNCONFIG()
    : App_IID(STR_CHAR_EMPTY)
    , LG_ENAB(DEFAULT_APP_LG_ENAB)
    , LG_PATH(DEFAULT_APP_LG_PATH)
    , LG_NAME(DEFAULT_APP_LG_NAME)
    , LG_MCNT(DEFAULT_APP_LG_MSIZ)
    , LG_MSIZ(DEFAULT_APP_LG_MCNT)
    , LG_DLVL(DEFAULT_APP_LG_DLVL)
    , TM_UPLD(DEFAULT_APP_TM_UPLD)
    , TM_FUPD(DEFAULT_APP_TM_FUPD)
    , TM_DNLD(DEFAULT_APP_TM_SYNC)
    , TM_FDND(DEFAULT_APP_TM_FSYN)
{
}

TRUNCONFIG::TRUNCONFIG(const TRUNCONFIG& other)
{
    App_IID = other.App_IID;
    LG_ENAB = other.LG_ENAB;
    LG_PATH = other.LG_PATH;
    LG_NAME = other.LG_NAME;
    LG_MCNT = other.LG_MCNT;
    LG_MSIZ = other.LG_MSIZ;
    LG_DLVL = other.LG_DLVL;
    TM_UPLD = other.TM_UPLD;
    TM_FUPD = other.TM_FUPD;
    TM_DNLD = other.TM_DNLD;
    TM_FDND = other.TM_FDND;
}

TRUNCONFIG& TRUNCONFIG::operator=(const TRUNCONFIG& other)
{
    App_IID = other.App_IID;
    LG_ENAB = other.LG_ENAB;
    LG_PATH = other.LG_PATH;
    LG_NAME = other.LG_NAME;
    LG_MCNT = other.LG_MCNT;
    LG_MSIZ = other.LG_MSIZ;
    LG_DLVL = other.LG_DLVL;
    TM_UPLD = other.TM_UPLD;
    TM_FUPD = other.TM_FUPD;
    TM_DNLD = other.TM_DNLD;
    TM_FDND = other.TM_FDND;
    return *this;
}