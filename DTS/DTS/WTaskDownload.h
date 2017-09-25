// -*- C++ -*-

//=============================================================================
/******************************************************************************
**  @file   WTaskDownload.h
**
**  @description
**      任务-基础数据同步
******************************************************************************/
//=============================================================================

#ifndef __WTASKDOWNLOAD_H__
#define __WTASKDOWNLOAD_H__

#include "GDefine.h"


class WTaskDownload : public QThread
{
    Q_OBJECT

public:
    WTaskDownload(QObject *parent = Q_NULLPTR);
    virtual ~WTaskDownload();

public:
    GERROR Initialize();
    GERROR Stop();

protected:
    virtual void run() Q_DECL_OVERRIDE;

private:
    void Task_SyncTable();

private:
    QSqlDatabase    m_cSQLDBWorkshop;

    bool            m_bStop;
    QMutex          m_mutexRun;
};

#endif