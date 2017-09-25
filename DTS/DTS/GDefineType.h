// -*- C++ -*-

//=============================================================================
/******************************************************************************
**  @file   GDefineType.h
**
**  @description
**      �������Ͷ���
******************************************************************************/
//=============================================================================

#ifndef __GDEFINETYPE_H__
#define __GDEFINETYPE_H__

#include "GDefine.h"


/**
* �������Ͷ���
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
* �Զ������Ͷ���
*/
typedef QMap<QString, QString>          TAPPLIST;
typedef TAPPLIST::iterator              TAPPLIST_IT;

typedef QMap<QString, QString>          TMAPNAMINGSQL;
typedef TMAPNAMINGSQL::iterator         TMAPNAMINGSQL_IT;

typedef QMap<QString, QString>          TMAPNAMINGTBL;
typedef TMAPNAMINGTBL::iterator         TMAPNAMINGTBL_IT;


/**
* ϵͳ�����ṹ�嶨��
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
* ���в����ṹ�嶨��
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
* ��־������
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
* �����붨��
*/
enum GERROR {
    GERROR_OK = 0x00000000,                             //!< ��ȷ

    GERROR_APP_COMMAND_PARSE            = 0x00000010,   //!< Ӧ�������н�������
    GERROR_APP_INVALID_NAME             = 0x00000011,   //!< Ӧ�����ƷǷ�
    GERROR_APP_ALREADY_RUN              = 0x00000012,   //!< Ӧ���Ѿ�����
    GERROR_APP_TASKWS_ERROR             = 0x00000013,   //!< Ӧ������WebServiceʧ��
    GERROR_APP_TASKUL_ERROR             = 0x00000014,   //!< Ӧ���������ݿ��ϴ�����ʧ��
    GERROR_APP_TASKSN_ERROR             = 0x00000015,   //!< Ӧ���������ݿ�ͬ������ʧ��
    GERROR_APP_TASKNS_ERROR             = 0x00000016,   //!< Ӧ�ö�ȡNAMINGSQLʧ��

    GERROR_SYSTEM_REGEDIT_ERROR         = 0x00001000,   //!< ϵͳע���б��ʧ��
    GERROR_SYSTEM_REGEDIT_NOTFOUND      = 0x00001001,   //!< ϵͳע���б�δ�鵽
    GERROR_SYSTEM_FILENOTEXIST          = 0x00001002,   //!< ϵͳ�ļ�������

    GERROR_TASK_BINDPORT                = 0x00002001,   //!< ����󶨶˿�ʧ��
    GERROR_TASK_SQLOPEN                 = 0x00002002,   //!< ��������ݿ�ʧ��
    GERROR_TASK_READXML_ERROR           = 0x00002003,   //!< �����ȡXMLʧ��

    GERROR_FAIL = 0xFFFFFFFF
};

#endif