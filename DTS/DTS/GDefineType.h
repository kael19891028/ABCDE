// -*- C++ -*-

//=============================================================================
/******************************************************************************
**  @file   GDefineType.h
**
**  @description
**      公用类型定义
******************************************************************************/
//=============================================================================

#ifndef __GDEFINETYPE_H__
#define __GDEFINETYPE_H__

#include "GDefine.h"


/**
* 基本类型定义
*/
typedef quint64 QUInt64;
typedef qint64  QInt64;
typedef quint32 QUInt32;
typedef qint32  QInt32;
typedef quint16 QUInt16;
typedef qint16  QInt16;
typedef quint8  QUInt8;
typedef qint8   QInt8;
typedef bool    QBool;


/**
* 自定义类型定义
*/
typedef QMap<QString, QString>          TAPPLIST;
typedef TAPPLIST::iterator              TAPPLIST_IT;

typedef QMap<QString, QString>          TMAPNAMINGSQL;
typedef TMAPNAMINGSQL::iterator         TMAPNAMINGSQL_IT;

typedef QMap<QString, QString>          TMAPNAMINGTBL;
typedef TMAPNAMINGTBL::iterator         TMAPNAMINGTBL_IT;


/**
* 系统参数结构体定义
*/
struct TSYSCONFIG
{
    TSYSCONFIG();
    TSYSCONFIG(const TSYSCONFIG& other);
    TSYSCONFIG& operator=(const TSYSCONFIG& other);

    QString App_IID;
    QString AppName;
    QString WS_Addr;
    QInt32  WS_Port;
    QString DB_Addr;
    QInt32  DB_Port;
    QString DB_User;
    QString DB_Pass;
    QString DB_Name;
};


/**
* 运行参数结构体定义
*/
struct TRUNCONFIG
{
    TRUNCONFIG();
    TRUNCONFIG(const TRUNCONFIG& other);
    TRUNCONFIG& operator=(const TRUNCONFIG& other);

    QString App_IID;
    QBool   LG_ENAB;
    QString LG_PATH;
    QString LG_NAME;
    QInt32  LG_MCNT;
    QInt32  LG_MSIZ;
    QInt32  LG_DLVL;
    QUInt32 TM_UPLD;
    QUInt32 TM_FUPD;
    QUInt32 TM_DNLD;
    QUInt32 TM_FDND;
};




/**
* 日志级别定义
*/
enum GLOGGER {
    GLOGGER_DBG = 0,
    GLOGGER_INF,
    GLOGGER_WAR,
    GLOGGER_ERR,
    GLOGGER_MAX
};


enum GSYNCH
{
    GSYNCH_UPLD = 0,
    GSYNCH_DNLD,
    GSYNCH_MAX
};

/**
* 错误码定义
*/
enum GERROR {
    GERROR_OK = 0x00000000,                             //!< 正确

    GERROR_APP_COMMAND_PARSE            = 0x00000010,   //!< 应用命令行解析错误
    GERROR_APP_INVALID_NAME             = 0x00000011,   //!< 应用名称非法
    GERROR_APP_ALREADY_RUN              = 0x00000012,   //!< 应用已经开启
    GERROR_APP_TASKWS_ERROR             = 0x00000013,   //!< 应用启动WebService失败
    GERROR_APP_TASKUL_ERROR             = 0x00000014,   //!< 应用启动数据库上传任务失败
    GERROR_APP_TASKSN_ERROR             = 0x00000015,   //!< 应用启动数据库同步任务失败
    GERROR_APP_TASKNS_ERROR             = 0x00000016,   //!< 应用读取NAMINGSQL失败

    GERROR_SYSTEM_REGEDIT_ERROR         = 0x00001000,   //!< 系统注册列表打开失败
    GERROR_SYSTEM_REGEDIT_NOTFOUND      = 0x00001001,   //!< 系统注册列表未查到
    GERROR_SYSTEM_FILENOTEXIST          = 0x00001002,   //!< 系统文件不存在

    GERROR_TASK_BINDPORT                = 0x00002001,   //!< 任务绑定端口失败
    GERROR_TASK_SQLOPEN                 = 0x00002002,   //!< 任务打开数据库失败
    GERROR_TASK_READXML_ERROR           = 0x00002003,   //!< 任务读取XML失败

    GERROR_FAIL = 0xFFFFFFFF
};

#endif