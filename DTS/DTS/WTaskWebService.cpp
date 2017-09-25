// -*- C++ -*-

//=============================================================================
/******************************************************************************
**  @file   WTaskWebService.cpp
**
**  @description
**      任务-WebService服务
**
**  @history
**  001     2017/09/22      weiheng     创建该文档
******************************************************************************/
//=============================================================================

#include "WTaskWebService.h"
#include "gSOAP/JHServiceSoap.nsmap"
#include "gSOAP/soapJHServiceSoapService.h"
#include "gSOAP/soapJHServiceSoapProxy.h"


// TODO
#define _TEST_

#ifdef _TEST_
static int gCount = 0;
#endif

int JHServiceSoapService::test(_tempuri__test *tempuri__test, _tempuri__testResponse &tempuri__testResponse)
{
    // TODO
#ifdef _TEST_
    char* buff = new char[100];
    snprintf(buff, 100, "this is test interface, Total [%d]", gCount++);
    tempuri__testResponse.testResult = buff;
    return SOAP_OK;
#endif

    JHServiceSoapProxy proxy;
    proxy.test(tempuri__test, tempuri__testResponse);
    return SOAP_OK;
}
int JHServiceSoapService::ToolingTimes(_tempuri__ToolingTimes *tempuri__ToolingTimes, _tempuri__ToolingTimesResponse &tempuri__ToolingTimesResponse)
{
    // TODO
#ifdef _TEST_
    char* buff = new char[100];
    snprintf(buff, 100, "this is ToolingTimes interface, Total [%d]", gCount++);
    tempuri__ToolingTimesResponse.ToolingTimesResult = buff;
    return SOAP_OK;
#endif

    JHServiceSoapProxy proxy;
    proxy.ToolingTimes(tempuri__ToolingTimes, tempuri__ToolingTimesResponse);
    return SOAP_OK;
}
int JHServiceSoapService::BillState(_tempuri__BillState *tempuri__BillState, _tempuri__BillStateResponse &tempuri__BillStateResponse)
{
    // TODO
#ifdef _TEST_
    char* buff = new char[100];
    snprintf(buff, 100, "this is BillState interface, Total [%d]", gCount++);
    tempuri__BillStateResponse.BillStateResult = buff;
    return SOAP_OK;
#endif

    JHServiceSoapProxy proxy;
    proxy.BillState(tempuri__BillState, tempuri__BillStateResponse);
    return SOAP_OK;
}
int JHServiceSoapService::LineInventory(_tempuri__LineInventory *tempuri__LineInventory, _tempuri__LineInventoryResponse &tempuri__LineInventoryResponse)
{
    // TODO
#ifdef _TEST_
    char* buff = new char[100];
    snprintf(buff, 100, "this is LineInventory interface, Total [%d]", gCount++);
    tempuri__LineInventoryResponse.LineInventoryResult = buff;
    return SOAP_OK;
#endif

    JHServiceSoapProxy proxy;
    proxy.LineInventory(tempuri__LineInventory, tempuri__LineInventoryResponse);
    return SOAP_OK;
}
int JHServiceSoapService::AnDonStart(_tempuri__AnDonStart *tempuri__AnDonStart, _tempuri__AnDonStartResponse &tempuri__AnDonStartResponse)
{
    // TODO
#ifdef _TEST_
    char* buff = new char[100];
    snprintf(buff, 100, "this is AnDonStart interface, Total [%d]", gCount++);
    tempuri__AnDonStartResponse.AnDonStartResult = buff;
    return SOAP_OK;
#endif

    JHServiceSoapProxy proxy;
    proxy.AnDonStart(tempuri__AnDonStart, tempuri__AnDonStartResponse);
    return SOAP_OK;
}
int JHServiceSoapService::AnDonList(_tempuri__AnDonList *tempuri__AnDonList, _tempuri__AnDonListResponse &tempuri__AnDonListResponse)
{
    // TODO
#ifdef _TEST_
    char* buff = new char[100];
    snprintf(buff, 100, "this is AnDonList interface, Total [%d]", gCount++);
    tempuri__AnDonListResponse.AnDonListResult = buff;
    return SOAP_OK;
#endif

    JHServiceSoapProxy proxy;
    proxy.AnDonList(tempuri__AnDonList, tempuri__AnDonListResponse);
    return SOAP_OK;
}
int JHServiceSoapService::AnDonOver(_tempuri__AnDonOver *tempuri__AnDonOver, _tempuri__AnDonOverResponse &tempuri__AnDonOverResponse)
{
    // TODO
#ifdef _TEST_
    char* buff = new char[100];
    snprintf(buff, 100, "this is AnDonOver interface, Total [%d]", gCount++);
    tempuri__AnDonOverResponse.AnDonOverResult = buff;
    return SOAP_OK;
#endif

    JHServiceSoapProxy proxy;
    proxy.AnDonOver(tempuri__AnDonOver, tempuri__AnDonOverResponse);
    return SOAP_OK;
}
int JHServiceSoapService::DocAdd(_tempuri__DocAdd *tempuri__DocAdd, _tempuri__DocAddResponse &tempuri__DocAddResponse)
{
    // TODO
#ifdef _TEST_
    char* buff = new char[100];
    snprintf(buff, 100, "this is DocAdd interface, Total [%d]", gCount++);
    tempuri__DocAddResponse.DocAddResult = buff;
    return SOAP_OK;
#endif

    JHServiceSoapProxy proxy;
    proxy.DocAdd(tempuri__DocAdd, tempuri__DocAddResponse);
    return SOAP_OK;
}

int JHServiceSoapService::test_(_tempuri__test *tempuri__test, _tempuri__testResponse &tempuri__testResponse)
{
    return test(tempuri__test, tempuri__testResponse);
}
int JHServiceSoapService::ToolingTimes_(_tempuri__ToolingTimes *tempuri__ToolingTimes, _tempuri__ToolingTimesResponse &tempuri__ToolingTimesResponse)
{
    return ToolingTimes(tempuri__ToolingTimes, tempuri__ToolingTimesResponse);
}
int JHServiceSoapService::BillState_(_tempuri__BillState *tempuri__BillState, _tempuri__BillStateResponse &tempuri__BillStateResponse)
{
    return BillState(tempuri__BillState, tempuri__BillStateResponse);
}
int JHServiceSoapService::LineInventory_(_tempuri__LineInventory *tempuri__LineInventory, _tempuri__LineInventoryResponse &tempuri__LineInventoryResponse)
{
    return LineInventory(tempuri__LineInventory, tempuri__LineInventoryResponse);
}
int JHServiceSoapService::AnDonStart_(_tempuri__AnDonStart *tempuri__AnDonStart, _tempuri__AnDonStartResponse &tempuri__AnDonStartResponse)
{
    return AnDonStart(tempuri__AnDonStart, tempuri__AnDonStartResponse);
}
int JHServiceSoapService::AnDonList_(_tempuri__AnDonList *tempuri__AnDonList, _tempuri__AnDonListResponse &tempuri__AnDonListResponse)
{
    return AnDonList(tempuri__AnDonList, tempuri__AnDonListResponse);
}
int JHServiceSoapService::AnDonOver_(_tempuri__AnDonOver *tempuri__AnDonOver, _tempuri__AnDonOverResponse &tempuri__AnDonOverResponse)
{
    return AnDonOver(tempuri__AnDonOver, tempuri__AnDonOverResponse);
}
int JHServiceSoapService::DocAdd_(_tempuri__DocAdd *tempuri__DocAdd, _tempuri__DocAddResponse &tempuri__DocAddResponse)
{
    return DocAdd(tempuri__DocAdd, tempuri__DocAddResponse);
}



WTaskWebService::WTaskWebService(QObject *parent)
    : QThread(parent)
    , m_pWebService(new JHServiceSoapService())
{

}

WTaskWebService::~WTaskWebService()
{
    if (this->isRunning())
    {
        this->terminate();
    }
}

GERROR WTaskWebService::Initialize()
{
    qInfo() << STR_TASK_WEBSERVICE_INITIALIZE_BEGIN;

    if (SOAP_INVALID_SOCKET == m_pWebService->bind(qConfig->m_tSysConfig.WS_Addr.toStdString().c_str(), qConfig->m_tSysConfig.WS_Port, 0))
    {
        qWarning() << STR_TASK_WEBSERVICE_INITIALIZE_BIND;
        return GERROR_TASK_BINDPORT;
    }

    qInfo() << STR_TASK_WEBSERVICE_INITIALIZE_END;
    return GERROR_OK;
}

GERROR WTaskWebService::Stop()
{
    terminate();
    return GERROR_OK;
}

void WTaskWebService::run()
{
    qInfo() << STR_TASK_WEBSERVICE_RUN_BEGIN.arg((QInt32)QThread::currentThreadId());

    while (true)
    {
        if (SOAP_INVALID_SOCKET != m_pWebService->accept())
        {
            qInfo() << STR_TASK_WEBSERVICE_RUN_ACCEPT;
            QInt32 ret = m_pWebService->serve();
            if (ret != SOAP_OK)
            {
                qWarning() << STR_TASK_WEBSERVICE_RUN_SERVE << ret;
            }
            qInfo() << STR_TASK_WEBSERVICE_RUN_FINISH;
        }
    }

    qWarning() << STR_TASK_WEBSERVICE_RUN_END.arg((QInt32)QThread::currentThreadId());
}

