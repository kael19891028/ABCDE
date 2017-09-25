/* soapJHServiceSoapProxy.h
   Generated by gSOAP 2.8.51 for JHService.h

gSOAP XML Web services tools
Copyright (C) 2000-2017, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#ifndef soapJHServiceSoapProxy_H
#define soapJHServiceSoapProxy_H
#include "soapH.h"

    class SOAP_CMAC JHServiceSoapProxy : public soap {
      public:
        /// Endpoint URL of service 'JHServiceSoapProxy' (change as needed)
        const char *soap_endpoint;
        /// Variables globally declared in JHService.h, if any
        /// Construct a proxy with new managing context
        JHServiceSoapProxy();
        /// Copy constructor
        JHServiceSoapProxy(const JHServiceSoapProxy& rhs);
        /// Construct proxy given a managing context
        JHServiceSoapProxy(const struct soap&);
        /// Constructor taking an endpoint URL
        JHServiceSoapProxy(const char *endpoint);
        /// Constructor taking input and output mode flags for the new managing context
        JHServiceSoapProxy(soap_mode iomode);
        /// Constructor taking endpoint URL and input and output mode flags for the new managing context
        JHServiceSoapProxy(const char *endpoint, soap_mode iomode);
        /// Constructor taking input and output mode flags for the new managing context
        JHServiceSoapProxy(soap_mode imode, soap_mode omode);
        /// Destructor deletes deserialized data and managing context
        virtual ~JHServiceSoapProxy();
        /// Initializer used by constructors
        virtual void JHServiceSoapProxy_init(soap_mode imode, soap_mode omode);
        /// Return a copy that has a new managing context with the same engine state
        virtual JHServiceSoapProxy *copy();
        /// Copy assignment
        JHServiceSoapProxy& operator=(const JHServiceSoapProxy&);
        /// Delete all deserialized data (uses soap_destroy() and soap_end())
        virtual void destroy();
        /// Delete all deserialized data and reset to default
        virtual void reset();
        /// Disables and removes SOAP Header from message by setting soap->header = NULL
        virtual void soap_noheader();
        /// Get SOAP Header structure (i.e. soap->header, which is NULL when absent)
        virtual ::SOAP_ENV__Header *soap_header();
        /// Get SOAP Fault structure (i.e. soap->fault, which is NULL when absent)
        virtual ::SOAP_ENV__Fault *soap_fault();
        /// Get SOAP Fault string (NULL when absent)
        virtual const char *soap_fault_string();
        /// Get SOAP Fault detail as string (NULL when absent)
        virtual const char *soap_fault_detail();
        /// Close connection (normally automatic, except for send_X ops)
        virtual int soap_close_socket();
        /// Force close connection (can kill a thread blocked on IO)
        virtual int soap_force_close_socket();
        /// Print fault
        virtual void soap_print_fault(FILE*);
    #ifndef WITH_LEAN
    #ifndef WITH_COMPAT
        /// Print fault to stream
        virtual void soap_stream_fault(std::ostream&);
    #endif
        /// Write fault to buffer
        virtual char *soap_sprint_fault(char *buf, size_t len);
    #endif
        /// Web service operation 'test' (returns SOAP_OK or error code)
        virtual int test(_tempuri__test *tempuri__test, _tempuri__testResponse &tempuri__testResponse)
        { return this->test(NULL, NULL, tempuri__test, tempuri__testResponse); }
        virtual int test(const char *soap_endpoint, const char *soap_action, _tempuri__test *tempuri__test, _tempuri__testResponse &tempuri__testResponse);
        /// Web service operation 'ToolingTimes' (returns SOAP_OK or error code)
        virtual int ToolingTimes(_tempuri__ToolingTimes *tempuri__ToolingTimes, _tempuri__ToolingTimesResponse &tempuri__ToolingTimesResponse)
        { return this->ToolingTimes(NULL, NULL, tempuri__ToolingTimes, tempuri__ToolingTimesResponse); }
        virtual int ToolingTimes(const char *soap_endpoint, const char *soap_action, _tempuri__ToolingTimes *tempuri__ToolingTimes, _tempuri__ToolingTimesResponse &tempuri__ToolingTimesResponse);
        /// Web service operation 'BillState' (returns SOAP_OK or error code)
        virtual int BillState(_tempuri__BillState *tempuri__BillState, _tempuri__BillStateResponse &tempuri__BillStateResponse)
        { return this->BillState(NULL, NULL, tempuri__BillState, tempuri__BillStateResponse); }
        virtual int BillState(const char *soap_endpoint, const char *soap_action, _tempuri__BillState *tempuri__BillState, _tempuri__BillStateResponse &tempuri__BillStateResponse);
        /// Web service operation 'LineInventory' (returns SOAP_OK or error code)
        virtual int LineInventory(_tempuri__LineInventory *tempuri__LineInventory, _tempuri__LineInventoryResponse &tempuri__LineInventoryResponse)
        { return this->LineInventory(NULL, NULL, tempuri__LineInventory, tempuri__LineInventoryResponse); }
        virtual int LineInventory(const char *soap_endpoint, const char *soap_action, _tempuri__LineInventory *tempuri__LineInventory, _tempuri__LineInventoryResponse &tempuri__LineInventoryResponse);
        /// Web service operation 'AnDonStart' (returns SOAP_OK or error code)
        virtual int AnDonStart(_tempuri__AnDonStart *tempuri__AnDonStart, _tempuri__AnDonStartResponse &tempuri__AnDonStartResponse)
        { return this->AnDonStart(NULL, NULL, tempuri__AnDonStart, tempuri__AnDonStartResponse); }
        virtual int AnDonStart(const char *soap_endpoint, const char *soap_action, _tempuri__AnDonStart *tempuri__AnDonStart, _tempuri__AnDonStartResponse &tempuri__AnDonStartResponse);
        /// Web service operation 'AnDonList' (returns SOAP_OK or error code)
        virtual int AnDonList(_tempuri__AnDonList *tempuri__AnDonList, _tempuri__AnDonListResponse &tempuri__AnDonListResponse)
        { return this->AnDonList(NULL, NULL, tempuri__AnDonList, tempuri__AnDonListResponse); }
        virtual int AnDonList(const char *soap_endpoint, const char *soap_action, _tempuri__AnDonList *tempuri__AnDonList, _tempuri__AnDonListResponse &tempuri__AnDonListResponse);
        /// Web service operation 'AnDonOver' (returns SOAP_OK or error code)
        virtual int AnDonOver(_tempuri__AnDonOver *tempuri__AnDonOver, _tempuri__AnDonOverResponse &tempuri__AnDonOverResponse)
        { return this->AnDonOver(NULL, NULL, tempuri__AnDonOver, tempuri__AnDonOverResponse); }
        virtual int AnDonOver(const char *soap_endpoint, const char *soap_action, _tempuri__AnDonOver *tempuri__AnDonOver, _tempuri__AnDonOverResponse &tempuri__AnDonOverResponse);
        /// Web service operation 'DocAdd' (returns SOAP_OK or error code)
        virtual int DocAdd(_tempuri__DocAdd *tempuri__DocAdd, _tempuri__DocAddResponse &tempuri__DocAddResponse)
        { return this->DocAdd(NULL, NULL, tempuri__DocAdd, tempuri__DocAddResponse); }
        virtual int DocAdd(const char *soap_endpoint, const char *soap_action, _tempuri__DocAdd *tempuri__DocAdd, _tempuri__DocAddResponse &tempuri__DocAddResponse);
        /// Web service operation 'test' (returns SOAP_OK or error code)
        virtual int test_(_tempuri__test *tempuri__test, _tempuri__testResponse &tempuri__testResponse)
        { return this->test_(NULL, NULL, tempuri__test, tempuri__testResponse); }
        virtual int test_(const char *soap_endpoint, const char *soap_action, _tempuri__test *tempuri__test, _tempuri__testResponse &tempuri__testResponse);
        /// Web service operation 'ToolingTimes' (returns SOAP_OK or error code)
        virtual int ToolingTimes_(_tempuri__ToolingTimes *tempuri__ToolingTimes, _tempuri__ToolingTimesResponse &tempuri__ToolingTimesResponse)
        { return this->ToolingTimes_(NULL, NULL, tempuri__ToolingTimes, tempuri__ToolingTimesResponse); }
        virtual int ToolingTimes_(const char *soap_endpoint, const char *soap_action, _tempuri__ToolingTimes *tempuri__ToolingTimes, _tempuri__ToolingTimesResponse &tempuri__ToolingTimesResponse);
        /// Web service operation 'BillState' (returns SOAP_OK or error code)
        virtual int BillState_(_tempuri__BillState *tempuri__BillState, _tempuri__BillStateResponse &tempuri__BillStateResponse)
        { return this->BillState_(NULL, NULL, tempuri__BillState, tempuri__BillStateResponse); }
        virtual int BillState_(const char *soap_endpoint, const char *soap_action, _tempuri__BillState *tempuri__BillState, _tempuri__BillStateResponse &tempuri__BillStateResponse);
        /// Web service operation 'LineInventory' (returns SOAP_OK or error code)
        virtual int LineInventory_(_tempuri__LineInventory *tempuri__LineInventory, _tempuri__LineInventoryResponse &tempuri__LineInventoryResponse)
        { return this->LineInventory_(NULL, NULL, tempuri__LineInventory, tempuri__LineInventoryResponse); }
        virtual int LineInventory_(const char *soap_endpoint, const char *soap_action, _tempuri__LineInventory *tempuri__LineInventory, _tempuri__LineInventoryResponse &tempuri__LineInventoryResponse);
        /// Web service operation 'AnDonStart' (returns SOAP_OK or error code)
        virtual int AnDonStart_(_tempuri__AnDonStart *tempuri__AnDonStart, _tempuri__AnDonStartResponse &tempuri__AnDonStartResponse)
        { return this->AnDonStart_(NULL, NULL, tempuri__AnDonStart, tempuri__AnDonStartResponse); }
        virtual int AnDonStart_(const char *soap_endpoint, const char *soap_action, _tempuri__AnDonStart *tempuri__AnDonStart, _tempuri__AnDonStartResponse &tempuri__AnDonStartResponse);
        /// Web service operation 'AnDonList' (returns SOAP_OK or error code)
        virtual int AnDonList_(_tempuri__AnDonList *tempuri__AnDonList, _tempuri__AnDonListResponse &tempuri__AnDonListResponse)
        { return this->AnDonList_(NULL, NULL, tempuri__AnDonList, tempuri__AnDonListResponse); }
        virtual int AnDonList_(const char *soap_endpoint, const char *soap_action, _tempuri__AnDonList *tempuri__AnDonList, _tempuri__AnDonListResponse &tempuri__AnDonListResponse);
        /// Web service operation 'AnDonOver' (returns SOAP_OK or error code)
        virtual int AnDonOver_(_tempuri__AnDonOver *tempuri__AnDonOver, _tempuri__AnDonOverResponse &tempuri__AnDonOverResponse)
        { return this->AnDonOver_(NULL, NULL, tempuri__AnDonOver, tempuri__AnDonOverResponse); }
        virtual int AnDonOver_(const char *soap_endpoint, const char *soap_action, _tempuri__AnDonOver *tempuri__AnDonOver, _tempuri__AnDonOverResponse &tempuri__AnDonOverResponse);
        /// Web service operation 'DocAdd' (returns SOAP_OK or error code)
        virtual int DocAdd_(_tempuri__DocAdd *tempuri__DocAdd, _tempuri__DocAddResponse &tempuri__DocAddResponse)
        { return this->DocAdd_(NULL, NULL, tempuri__DocAdd, tempuri__DocAddResponse); }
        virtual int DocAdd_(const char *soap_endpoint, const char *soap_action, _tempuri__DocAdd *tempuri__DocAdd, _tempuri__DocAddResponse &tempuri__DocAddResponse);
    };
#endif