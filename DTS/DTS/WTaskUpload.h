// -*- C++ -*-

//=============================================================================
/******************************************************************************
**  @file   WTaskUpload.h
**
**  @description
**      任务-生产数据上传
******************************************************************************/
//=============================================================================

#ifndef __WTASKUPLOAD_H__
#define __WTASKUPLOAD_H__

#include "GDefine.h"


class WTaskUpload : public QThread
{
    Q_OBJECT

public:
    WTaskUpload(QObject *parent = Q_NULLPTR);
    virtual  ~WTaskUpload();

public:
    GERROR Initialize();
    GERROR Stop();

protected:
    virtual void run() Q_DECL_OVERRIDE;

private:
    void Task_Upload();

private:
    QSqlDatabase    m_cSQLDBWorkshop;

    bool            m_bStop;
    QMutex          m_mutexRun;
};

#endif