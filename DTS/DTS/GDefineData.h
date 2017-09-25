// -*- C++ -*-

//=============================================================================
/******************************************************************************
**  @file   GDefineData.h
**
**  @description
**      �������ݶ���
******************************************************************************/
//=============================================================================

#ifndef __GDEFINEDATA_H__
#define __GDEFINEDATA_H__

#include "GDefine.h"


/**
* ȫ�ֺ궨��
*/
#define qConfig                     (&GConfig::Instance())
#define qLogger                     (&GLogger::Instance())
#define qNaming                     (&GNamingSQL::Instance())

#define KB                          (1 * 1024)
#define MB                          (1 * 1024 * 1024)
#define GB                          (1 * 1024 * 1024 * 1024)
#define KILO                        (1 * 1000)
#define MEGA                        (1 * 1000 * 1000)
#define SEC_P_MI                    (60)
#define SEC_P_HR                    (60 * 60)
#define SEC_P_DY                    (24 * 60 * 60)

#define DEFALUT_APP_CG_PATH         "SOFTWARE"
#define DEFAULT_APP_WS_ADDR         "127.0.0.1"
#define DEFAULT_APP_WS_PORT         8123
#define DEFAULT_APP_DB_ADDR         "127.0.0.1"
#define DEFAULT_APP_DB_PORT         1433
#define DEFAULT_APP_DB_USER         "sa"
#define DEFAULT_APP_DB_PASS         "123456"
#define DEFAULT_APP_DB_NAME         "JHMidMes"
#define DEFAULT_APP_LG_ENAB         true
#define DEFAULT_APP_LG_PATH         "./log/"
#define DEFAULT_APP_LG_NAME         "mes.log"
#define DEFAULT_APP_LG_MCNT         100
#define DEFAULT_APP_LG_MSIZ         10
#define DEFAULT_APP_LG_DLVL         QUInt32(GLOGGER_WAR)
#define DEFAULT_APP_TM_UPLD         600
#define DEFAULT_APP_TM_FUPD         10
#define DEFAULT_APP_TM_SYNC         300
#define DEFAULT_APP_TM_FSYN         10
#define DEFAULT_APP_NS_FILE         "NamingSQL.xml"
#define DEFAULT_APP_NT_FILE         "NamingTBL.xml"


/**
* ȫ���ַ���
*/
#define STR_CHAR_EMPTY                               ""
#define STR_CHAR_DOT                                "."
#define STR_CHAR_STAR                               "*"

#define STR_COMB_KEY_VALUE                          QStringLiteral("%1/%2")
#define STR_COMB_DIR_LOCAL                          STR_CHAR_DOT
#define STR_COMB_DIR_PARENT                         (STR_CHAR_DOT STR_CHAR_DOT)

#define STR_APP_ORGANIZATIONNAME                    QStringLiteral("JHMES")
#define STR_APP_APPLICATIONNAME                     QStringLiteral("DTS")
#define STR_APP_APPLICATIONVARSION                  QStringLiteral("1.0.0.0000")

#define STR_APP_CMDLINE_OPTION_N                    QStringLiteral("n")
#define STR_APP_CMDLINE_OPTION_NAME                 QStringLiteral("name")
#define STR_APP_CMDLINE_NAME_N                      QStringLiteral("AppName")
#define STR_APP_CMDLINE_DESC_N                      QStringLiteral("Application Name.")
#define STR_APP_CMDLINE_DEFAULT_N                   STR_CHAR_EMPTY

#define STR_SQL_CONNECT_TQODBC                      QStringLiteral("QODBC")
#define STR_SQL_CONNECT_TQODBC_MSSQL_STR            QStringLiteral("Driver={sql server};SERVER=%1;PORT=%2;UID=%3;PWD=%4;DATABASE=%5;")
#define STR_SQL_CONNECT_TQODBC_WS_UPLD              QStringLiteral("Workshop_Upload")
#define STR_SQL_CONNECT_TQODBC_WS_DNLD              QStringLiteral("Workshop_Download")
#define STR_SQL_CONNECT_TQODBC_CC_UPLD              QStringLiteral("CenterControl_Upload")
#define STR_SQL_CONNECT_TQODBC_CC_DNLD              QStringLiteral("CenterControl_Download")

#define STR_TIMEFORMAT_YYYY_MM_DD_HH_MM_SS_ZZZ      QStringLiteral("yyyy-MM-dd hh:mm:ss.zzz")
#define STR_TIMEFORMAT_YYYYMMDDHHMMSS               QStringLiteral("yyyyMMddhhmmss")

#define STR_GLOGGER_DBG_ENG                         QStringLiteral("DBG")
#define STR_GLOGGER_DBG_CHS                         QStringLiteral("����")
#define STR_GLOGGER_INF_ENG                         QStringLiteral("INF")
#define STR_GLOGGER_INF_CHS                         QStringLiteral("����")
#define STR_GLOGGER_WAR_ENG                         QStringLiteral("WAR")
#define STR_GLOGGER_WAR_CHS                         QStringLiteral("����")
#define STR_GLOGGER_ERR_ENG                         QStringLiteral("ERR")
#define STR_GLOGGER_ERR_CHS                         QStringLiteral("����")

#define STR_GSYNCH_UPLD                             QStringLiteral("�ϴ�")
#define STR_GSYNCH_DNLD                             QStringLiteral("����")

#define STR_CONFIG_SYS_APPNAME                      QStringLiteral("APPNAME")
#define STR_CONFIG_SYS_WS_ADDR                      QStringLiteral("WS_ADDR")
#define STR_CONFIG_SYS_WS_PORT                      QStringLiteral("WS_PORT")
#define STR_CONFIG_SYS_DB_ADDR                      QStringLiteral("DB_ADDR")
#define STR_CONFIG_SYS_DB_PORT                      QStringLiteral("DB_PORT")
#define STR_CONFIG_SYS_DB_USER                      QStringLiteral("DB_USER")
#define STR_CONFIG_SYS_DB_PASS                      QStringLiteral("DB_PASS")
#define STR_CONFIG_SYS_DB_NAME                      QStringLiteral("DB_NAME")

#define STR_CONFIG_RUN_LG_ENAB                      QStringLiteral("LG_ENAB")
#define STR_CONFIG_RUN_LG_PATH                      QStringLiteral("LG_PATH")
#define STR_CONFIG_RUN_LG_NAME                      QStringLiteral("LG_NAME")
#define STR_CONFIG_RUN_LG_MCNT                      QStringLiteral("LG_MCNT")
#define STR_CONFIG_RUN_LG_MSIZ                      QStringLiteral("LG_MSIZ")
#define STR_CONFIG_RUN_LG_DLVL                      QStringLiteral("LG_DLVL")
#define STR_CONFIG_RUN_TM_UPLD                      QStringLiteral("TM_UPLD")
#define STR_CONFIG_RUN_TM_FUPD                      QStringLiteral("TM_FUPD")
#define STR_CONFIG_RUN_TM_SYNC                      QStringLiteral("TM_DNLD")
#define STR_CONFIG_RUN_TM_FSYN                      QStringLiteral("TM_FDND")

#define STR_PICTURE_WORKSHOP                        QStringLiteral(":/DTS/workshop")
#define STR_PICTURE_MAIN                            QStringLiteral(":/DTS/main")
#define STR_PICTURE_MAIN_RUN                        QStringLiteral(":/DTS/main_run")
#define STR_PICTURE_RES_ERROR                       QStringLiteral(":/DTS/res_error")
#define STR_PICTURE_RES_OK                          QStringLiteral(":/DTS/res_ok")
#define STR_PICTURE_RES_DELETE                      QStringLiteral(":/DTS/res_delete")
#define STR_PICTURE_ACTION_LOGIN                    QStringLiteral(":/DTS/action_login")
#define STR_PICTURE_ACTION_LOGOUT                   QStringLiteral(":/DTS/action_logout")
#define STR_PICTURE_ACTION_SYSCONFIG                QStringLiteral(":/DTS/action_sysconfig")
#define STR_PICTURE_ACTION_RUNCONFIG                QStringLiteral(":/DTS/action_runconfig")
#define STR_PICTURE_ACTION_SYNCONFIG                QStringLiteral(":/DTS/action_synconfig")

#define STR_XML_ATTRIBUTE_NAMINGSQL                 QStringLiteral("NamingSQL")
#define STR_XML_ATTRIBUTE_NAME                      QStringLiteral("name")
#define STR_XML_ATTRIBUTE_NAMINGTBL                 QStringLiteral("NamingTBL")
#define STR_XML_ATTRIBUTE_OPERATE                   QStringLiteral("operate")
#define STR_XML_ATTRIBUTE_TYPE                      QStringLiteral("type")

#define STR_UI_MAINWINDOW_STARTUP                   QStringLiteral("����ҳ")
#define STR_UI_MAINWINDOW_SYSCONFIG                 QStringLiteral("ϵͳ��������ҳ")
#define STR_UI_MAINWINDOW_RUNCONFIG                 QStringLiteral("���в�������ҳ")
#define STR_UI_MAINWINDOW_SYNCONFIG                 QStringLiteral("ͬ����������ҳ")
#define STR_UI_SYSCONFIG_BUTTON_SAVE                QStringLiteral("����")
#define STR_UI_SYSCONFIG_BUTTON_CREATE              QStringLiteral("����")
#define STR_UI_SYNCONFIG_TABLETITLE_NAME            QStringLiteral("ͬ������")
#define STR_UI_SYNCONFIG_TABLETITLE_OPER            QStringLiteral("ͬ������")
#define STR_UI_SYNCONFIG_TABLETITLE_TYPE            QStringLiteral("ͬ������")

#define STR_MESSAGEBOX_BUTTON_YES                   QStringLiteral("ȷ��")
#define STR_MESSAGEBOX_BUTTON_CANCEL                QStringLiteral("ȡ��")
#define STR_MESSAGEBOX_TITLE_INF                    QStringLiteral("֪ͨ")
#define STR_MESSAGEBOX_TITLE_WAR                    QStringLiteral("����")
#define STR_MESSAGEBOX_TITLE_CRI                    QStringLiteral("����")
#define STR_MESSAGEBOX_TXT_SAVECONFIRM              QStringLiteral("����ɹ���")
#define STR_MESSAGEBOX_TXT_CREATECONFIRM            QStringLiteral("�����ɹ���")
#define STR_MESSAGEBOX_TXT_DELETECONFIRM            QStringLiteral("ȷ��ɾ����")
#define STR_MESSAGEBOX_TXT_QUITCONFIRM              QStringLiteral("ȷ���˳���")
#define STR_MESSAGEBOX_TXT_UNKOWNCMD                QStringLiteral("��Ч�������в���!")

#define STR_TASK_WEBSERVICE_INITIALIZE_BEGIN    QStringLiteral("WebService �����ʼ����ʼ")
#define STR_TASK_WEBSERVICE_INITIALIZE_END      QStringLiteral("WebService �����ʼ���ɹ�")
#define STR_TASK_WEBSERVICE_INITIALIZE_BIND     QStringLiteral("WebService �󶨵�ַ����!")
#define STR_TASK_WEBSERVICE_RUN_BEGIN           QStringLiteral("WebService �����߳̿���, THREADID=%1")
#define STR_TASK_WEBSERVICE_RUN_END             QStringLiteral("WebService �����߳̽���, THREADID=%1")
#define STR_TASK_WEBSERVICE_RUN_FINISH          QStringLiteral("WebService ���������")
#define STR_TASK_WEBSERVICE_RUN_ACCEPT          QStringLiteral("WebService ���յ�һ������")
#define STR_TASK_WEBSERVICE_RUN_SERVE           QStringLiteral("WebService ������һ������ERROR=")

#define STR_TASK_UPLOAD_INITIALIZE_BEGIN        QStringLiteral("�����ϴ� �����ʼ����ʼ")
#define STR_TASK_UPLOAD_INITIALIZE_END          QStringLiteral("�����ϴ� �����ʼ���ɹ�")
#define STR_TASK_UPLOAD_INITIALIZE_SQLSTR       QStringLiteral("�����ϴ� ���ݿ������ַ�����STR=\n\t%1")
#define STR_TASK_UPLOAD_INITIALIZE_OPEN         QStringLiteral("�����ϴ� �������ݿ�ʧ��")
#define STR_TASK_UPLOAD_RUN_BEGIN               QStringLiteral("�����ϴ� �����߳̿���, THREADID=%1")
#define STR_TASK_UPLOAD_RUN_END                 QStringLiteral("�����ϴ� �����߳̽���, THREADID=%1")
#define STR_TASK_UPLOAD_TASK_BEGIN              QStringLiteral("�����ϴ� ����ʼִ��")

#define STR_TASK_DOWNLOAD_INITIALIZE_BEGIN      QStringLiteral("�������� �����ʼ����ʼ")
#define STR_TASK_DOWNLOAD_INITIALIZE_END        QStringLiteral("�������� �����ʼ���ɹ�")
#define STR_TASK_DOWNLOAD_INITIALIZE_SQLSTR     QStringLiteral("�������� ���ݿ������ַ�����STR=\n\t%1")
#define STR_TASK_DOWNLOAD_INITIALIZE_OPEN       QStringLiteral("�������� �������ݿ�ʧ��")
#define STR_TASK_DOWNLOAD_RUN_BEGIN             QStringLiteral("�������� �����߳̿���, THREADID=%1")
#define STR_TASK_DOWNLOAD_RUN_END               QStringLiteral("�������� �����߳̽���, THREADID=%1")
#define STR_TASK_DOWNLOAD_TASK_BEGIN            QStringLiteral("�������� ����ʼִ��")

#define STR_MAINWINDOW_INITIALIZE_BEGIN         QStringLiteral("ϵͳ��ʼ����ʼ")
#define STR_MAINWINDOW_INITIALIZE_END           QStringLiteral("ϵͳ��ʼ���ɹ�")
#define STR_MAINWINDOW_INITIALIZE_NOAPPID       QStringLiteral("Ӧ�ñ�Ų�����")
#define STR_MAINWINDOW_INITIALIZE_NOTINREG      QStringLiteral("Ӧ��δע��")
#define STR_MAINWINDOW_INITIALIZE_APPIDIS       QStringLiteral("Ӧ�ñ���ǣ�%1")
#define STR_MAINWINDOW_INITIALIZE_APPALRDRUN    QStringLiteral("Ӧ���Ѿ�����")
#define STR_MAINWINDOW_INITIALIZE_RDCONFIGERR   QStringLiteral("Ӧ�ö�ȡ������Ϣʧ��")
#define STR_MAINWINDOW_INITIALIZE_CREATEMUTEX   QStringLiteral("����Ӧ��ʵ���ɹ�")
#define STR_MAINWINDOW_INITIALIZE_TASKWSERROR   QStringLiteral("WebService ��������ʧ��")
#define STR_MAINWINDOW_INITIALIZE_TASKULERROR   QStringLiteral("���ݿ��ϴ� ��������ʧ��")
#define STR_MAINWINDOW_INITIALIZE_TASKSNERROR   QStringLiteral("���ݿ�ͬ�� ��������ʧ��")

#define STR_MAINTHREAD_BEGIN_CMDLINE_UNKNOWN    QStringLiteral("δ֪�Ĳ����б�")
#define STR_MAINTHREAD_BEGIN_CMDLINE_N          QStringLiteral("Ӧ�ò����б�[n]=%1")

#define STR_NAMINGSQL_OPENFILE_ERROR            QStringLiteral("���ļ�ʧ�ܣ��ļ����ƣ�%1")
#define STR_NAMINGSQL_READXML_ERROR             QStringLiteral("��ȡXML�ļ�ʧ�ܣ���%1�У���%2�У�����������%3")


#endif