// -*- C++ -*-

//=============================================================================
/******************************************************************************
**  @file   WTaskWebService.h
**
**  @description
**      任务-WebService服务
******************************************************************************/
//=============================================================================

#ifndef __WTASKWEBSERVICE_H__
#define __WTASKWEBSERVICE_H__

#include "GDefine.h"

class JHServiceSoapService;
class WTaskWebService : public QThread
{
    Q_OBJECT

public:
    WTaskWebService(QObject *parent = Q_NULLPTR);
    virtual ~WTaskWebService();

public:
    GERROR Initialize();
    GERROR Stop();

protected:
    virtual void run() Q_DECL_OVERRIDE;

private:
    QScopedPointer<JHServiceSoapService> m_pWebService;
};

#endif