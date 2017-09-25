/* soapJHServiceSoapService.cpp
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

#include "soapJHServiceSoapService.h"

JHServiceSoapService::JHServiceSoapService() : soap(SOAP_IO_DEFAULT)
{	JHServiceSoapService_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

JHServiceSoapService::JHServiceSoapService(const JHServiceSoapService& rhs)
{	soap_copy_context(this, &rhs);
}

JHServiceSoapService::JHServiceSoapService(const struct soap &_soap) : soap(_soap)
{ }

JHServiceSoapService::JHServiceSoapService(soap_mode iomode) : soap(iomode)
{	JHServiceSoapService_init(iomode, iomode);
}

JHServiceSoapService::JHServiceSoapService(soap_mode imode, soap_mode omode) : soap(imode, omode)
{	JHServiceSoapService_init(imode, omode);
}

JHServiceSoapService::~JHServiceSoapService()
{
	this->destroy();
}

void JHServiceSoapService::JHServiceSoapService_init(soap_mode imode, soap_mode omode)
{	soap_imode(this, imode);
	soap_omode(this, omode);
	static const struct Namespace namespaces[] = {
        {"SOAP-ENV", "http://www.w3.org/2003/05/soap-envelope", "http://schemas.xmlsoap.org/soap/envelope/", NULL},
        {"SOAP-ENC", "http://www.w3.org/2003/05/soap-encoding", "http://schemas.xmlsoap.org/soap/encoding/", NULL},
        {"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
        {"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
        {"tempuri", "http://tempuri.org/", NULL, NULL},
        {NULL, NULL, NULL, NULL}
    };
	soap_set_namespaces(this, namespaces);
}

void JHServiceSoapService::destroy()
{	soap_destroy(this);
	soap_end(this);
}

void JHServiceSoapService::reset()
{	this->destroy();
	soap_done(this);
	soap_initialize(this);
	JHServiceSoapService_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

#ifndef WITH_PURE_VIRTUAL
JHServiceSoapService *JHServiceSoapService::copy()
{	JHServiceSoapService *dup = SOAP_NEW_COPY(JHServiceSoapService(*(struct soap*)this));
	return dup;
}
#endif

JHServiceSoapService& JHServiceSoapService::operator=(const JHServiceSoapService& rhs)
{	soap_copy_context(this, &rhs);
	return *this;
}

int JHServiceSoapService::soap_close_socket()
{	return soap_closesock(this);
}

int JHServiceSoapService::soap_force_close_socket()
{	return soap_force_closesock(this);
}

int JHServiceSoapService::soap_senderfault(const char *string, const char *detailXML)
{	return ::soap_sender_fault(this, string, detailXML);
}

int JHServiceSoapService::soap_senderfault(const char *subcodeQName, const char *string, const char *detailXML)
{	return ::soap_sender_fault_subcode(this, subcodeQName, string, detailXML);
}

int JHServiceSoapService::soap_receiverfault(const char *string, const char *detailXML)
{	return ::soap_receiver_fault(this, string, detailXML);
}

int JHServiceSoapService::soap_receiverfault(const char *subcodeQName, const char *string, const char *detailXML)
{	return ::soap_receiver_fault_subcode(this, subcodeQName, string, detailXML);
}

void JHServiceSoapService::soap_print_fault(FILE *fd)
{	::soap_print_fault(this, fd);
}

#ifndef WITH_LEAN
#ifndef WITH_COMPAT
void JHServiceSoapService::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this, os);
}
#endif

char *JHServiceSoapService::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this, buf, len);
}
#endif

void JHServiceSoapService::soap_noheader()
{	this->header = NULL;
}

::SOAP_ENV__Header *JHServiceSoapService::soap_header()
{	return this->header;
}

#ifndef WITH_NOIO
int JHServiceSoapService::run(int port)
{	if (!soap_valid_socket(this->master) && !soap_valid_socket(this->bind(NULL, port, 100)))
		return this->error;
	for (;;)
	{	if (!soap_valid_socket(this->accept()))
		{	if (this->errnum == 0) // timeout?
				this->error = SOAP_OK;
			break;
		}
		if (this->serve())
			break;
		this->destroy();
	}
	return this->error;
}

#if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
int JHServiceSoapService::ssl_run(int port)
{	if (!soap_valid_socket(this->master) && !soap_valid_socket(this->bind(NULL, port, 100)))
		return this->error;
	for (;;)
	{	if (!soap_valid_socket(this->accept()))
		{	if (this->errnum == 0) // timeout?
				this->error = SOAP_OK;
			break;
		}
		if (this->ssl_accept() || this->serve())
			break;
		this->destroy();
	}
	return this->error;
}
#endif

SOAP_SOCKET JHServiceSoapService::bind(const char *host, int port, int backlog)
{	return soap_bind(this, host, port, backlog);
}

SOAP_SOCKET JHServiceSoapService::accept()
{	return soap_accept(this);
}

#if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
int JHServiceSoapService::ssl_accept()
{	return soap_ssl_accept(this);
}
#endif
#endif

int JHServiceSoapService::serve()
{
#ifndef WITH_FASTCGI
	this->keep_alive = this->max_keep_alive + 1;
#endif
	do
	{
#ifndef WITH_FASTCGI
		if (this->keep_alive > 0 && this->max_keep_alive > 0)
			this->keep_alive--;
#endif
		if (soap_begin_serve(this))
		{	if (this->error >= SOAP_STOP)
				continue;
			return this->error;
		}
		if ((dispatch() || (this->fserveloop && this->fserveloop(this))) && this->error && this->error < SOAP_STOP)
		{
#ifdef WITH_FASTCGI
			soap_send_fault(this);
#else
			return soap_send_fault(this);
#endif
		}
#ifdef WITH_FASTCGI
		soap_destroy(this);
		soap_end(this);
	} while (1);
#else
	} while (this->keep_alive);
#endif
	return SOAP_OK;
}

static int serve___tempuri__test(JHServiceSoapService*);
static int serve___tempuri__ToolingTimes(JHServiceSoapService*);
static int serve___tempuri__BillState(JHServiceSoapService*);
static int serve___tempuri__LineInventory(JHServiceSoapService*);
static int serve___tempuri__AnDonStart(JHServiceSoapService*);
static int serve___tempuri__AnDonList(JHServiceSoapService*);
static int serve___tempuri__AnDonOver(JHServiceSoapService*);
static int serve___tempuri__DocAdd(JHServiceSoapService*);
static int serve___tempuri__test_(JHServiceSoapService*);
static int serve___tempuri__ToolingTimes_(JHServiceSoapService*);
static int serve___tempuri__BillState_(JHServiceSoapService*);
static int serve___tempuri__LineInventory_(JHServiceSoapService*);
static int serve___tempuri__AnDonStart_(JHServiceSoapService*);
static int serve___tempuri__AnDonList_(JHServiceSoapService*);
static int serve___tempuri__AnDonOver_(JHServiceSoapService*);
static int serve___tempuri__DocAdd_(JHServiceSoapService*);

int JHServiceSoapService::dispatch()
{
	soap_peek_element(this);
	if (!soap_match_tag(this, this->tag, "tempuri:test"))
		return serve___tempuri__test(this);
	if (!soap_match_tag(this, this->tag, "tempuri:ToolingTimes"))
		return serve___tempuri__ToolingTimes(this);
	if (!soap_match_tag(this, this->tag, "tempuri:BillState"))
		return serve___tempuri__BillState(this);
	if (!soap_match_tag(this, this->tag, "tempuri:LineInventory"))
		return serve___tempuri__LineInventory(this);
	if (!soap_match_tag(this, this->tag, "tempuri:AnDonStart"))
		return serve___tempuri__AnDonStart(this);
	if (!soap_match_tag(this, this->tag, "tempuri:AnDonList"))
		return serve___tempuri__AnDonList(this);
	if (!soap_match_tag(this, this->tag, "tempuri:AnDonOver"))
		return serve___tempuri__AnDonOver(this);
	if (!soap_match_tag(this, this->tag, "tempuri:DocAdd"))
		return serve___tempuri__DocAdd(this);
	if (!soap_match_tag(this, this->tag, "tempuri:test"))
		return serve___tempuri__test_(this);
	if (!soap_match_tag(this, this->tag, "tempuri:ToolingTimes"))
		return serve___tempuri__ToolingTimes_(this);
	if (!soap_match_tag(this, this->tag, "tempuri:BillState"))
		return serve___tempuri__BillState_(this);
	if (!soap_match_tag(this, this->tag, "tempuri:LineInventory"))
		return serve___tempuri__LineInventory_(this);
	if (!soap_match_tag(this, this->tag, "tempuri:AnDonStart"))
		return serve___tempuri__AnDonStart_(this);
	if (!soap_match_tag(this, this->tag, "tempuri:AnDonList"))
		return serve___tempuri__AnDonList_(this);
	if (!soap_match_tag(this, this->tag, "tempuri:AnDonOver"))
		return serve___tempuri__AnDonOver_(this);
	if (!soap_match_tag(this, this->tag, "tempuri:DocAdd"))
		return serve___tempuri__DocAdd_(this);
	return this->error = SOAP_NO_METHOD;
}

static int serve___tempuri__test(JHServiceSoapService *soap)
{	struct __tempuri__test soap_tmp___tempuri__test;
	_tempuri__testResponse tempuri__testResponse;
	tempuri__testResponse.soap_default(soap);
	soap_default___tempuri__test(soap, &soap_tmp___tempuri__test);
	if (!soap_get___tempuri__test(soap, &soap_tmp___tempuri__test, "-tempuri:test", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->test(soap_tmp___tempuri__test.tempuri__test, tempuri__testResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	tempuri__testResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tempuri__testResponse.soap_put(soap, "tempuri:testResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tempuri__testResponse.soap_put(soap, "tempuri:testResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tempuri__ToolingTimes(JHServiceSoapService *soap)
{	struct __tempuri__ToolingTimes soap_tmp___tempuri__ToolingTimes;
	_tempuri__ToolingTimesResponse tempuri__ToolingTimesResponse;
	tempuri__ToolingTimesResponse.soap_default(soap);
	soap_default___tempuri__ToolingTimes(soap, &soap_tmp___tempuri__ToolingTimes);
	if (!soap_get___tempuri__ToolingTimes(soap, &soap_tmp___tempuri__ToolingTimes, "-tempuri:ToolingTimes", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->ToolingTimes(soap_tmp___tempuri__ToolingTimes.tempuri__ToolingTimes, tempuri__ToolingTimesResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	tempuri__ToolingTimesResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tempuri__ToolingTimesResponse.soap_put(soap, "tempuri:ToolingTimesResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tempuri__ToolingTimesResponse.soap_put(soap, "tempuri:ToolingTimesResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tempuri__BillState(JHServiceSoapService *soap)
{	struct __tempuri__BillState soap_tmp___tempuri__BillState;
	_tempuri__BillStateResponse tempuri__BillStateResponse;
	tempuri__BillStateResponse.soap_default(soap);
	soap_default___tempuri__BillState(soap, &soap_tmp___tempuri__BillState);
	if (!soap_get___tempuri__BillState(soap, &soap_tmp___tempuri__BillState, "-tempuri:BillState", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->BillState(soap_tmp___tempuri__BillState.tempuri__BillState, tempuri__BillStateResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	tempuri__BillStateResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tempuri__BillStateResponse.soap_put(soap, "tempuri:BillStateResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tempuri__BillStateResponse.soap_put(soap, "tempuri:BillStateResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tempuri__LineInventory(JHServiceSoapService *soap)
{	struct __tempuri__LineInventory soap_tmp___tempuri__LineInventory;
	_tempuri__LineInventoryResponse tempuri__LineInventoryResponse;
	tempuri__LineInventoryResponse.soap_default(soap);
	soap_default___tempuri__LineInventory(soap, &soap_tmp___tempuri__LineInventory);
	if (!soap_get___tempuri__LineInventory(soap, &soap_tmp___tempuri__LineInventory, "-tempuri:LineInventory", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->LineInventory(soap_tmp___tempuri__LineInventory.tempuri__LineInventory, tempuri__LineInventoryResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	tempuri__LineInventoryResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tempuri__LineInventoryResponse.soap_put(soap, "tempuri:LineInventoryResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tempuri__LineInventoryResponse.soap_put(soap, "tempuri:LineInventoryResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tempuri__AnDonStart(JHServiceSoapService *soap)
{	struct __tempuri__AnDonStart soap_tmp___tempuri__AnDonStart;
	_tempuri__AnDonStartResponse tempuri__AnDonStartResponse;
	tempuri__AnDonStartResponse.soap_default(soap);
	soap_default___tempuri__AnDonStart(soap, &soap_tmp___tempuri__AnDonStart);
	if (!soap_get___tempuri__AnDonStart(soap, &soap_tmp___tempuri__AnDonStart, "-tempuri:AnDonStart", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->AnDonStart(soap_tmp___tempuri__AnDonStart.tempuri__AnDonStart, tempuri__AnDonStartResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	tempuri__AnDonStartResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tempuri__AnDonStartResponse.soap_put(soap, "tempuri:AnDonStartResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tempuri__AnDonStartResponse.soap_put(soap, "tempuri:AnDonStartResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tempuri__AnDonList(JHServiceSoapService *soap)
{	struct __tempuri__AnDonList soap_tmp___tempuri__AnDonList;
	_tempuri__AnDonListResponse tempuri__AnDonListResponse;
	tempuri__AnDonListResponse.soap_default(soap);
	soap_default___tempuri__AnDonList(soap, &soap_tmp___tempuri__AnDonList);
	if (!soap_get___tempuri__AnDonList(soap, &soap_tmp___tempuri__AnDonList, "-tempuri:AnDonList", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->AnDonList(soap_tmp___tempuri__AnDonList.tempuri__AnDonList, tempuri__AnDonListResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	tempuri__AnDonListResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tempuri__AnDonListResponse.soap_put(soap, "tempuri:AnDonListResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tempuri__AnDonListResponse.soap_put(soap, "tempuri:AnDonListResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tempuri__AnDonOver(JHServiceSoapService *soap)
{	struct __tempuri__AnDonOver soap_tmp___tempuri__AnDonOver;
	_tempuri__AnDonOverResponse tempuri__AnDonOverResponse;
	tempuri__AnDonOverResponse.soap_default(soap);
	soap_default___tempuri__AnDonOver(soap, &soap_tmp___tempuri__AnDonOver);
	if (!soap_get___tempuri__AnDonOver(soap, &soap_tmp___tempuri__AnDonOver, "-tempuri:AnDonOver", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->AnDonOver(soap_tmp___tempuri__AnDonOver.tempuri__AnDonOver, tempuri__AnDonOverResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	tempuri__AnDonOverResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tempuri__AnDonOverResponse.soap_put(soap, "tempuri:AnDonOverResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tempuri__AnDonOverResponse.soap_put(soap, "tempuri:AnDonOverResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tempuri__DocAdd(JHServiceSoapService *soap)
{	struct __tempuri__DocAdd soap_tmp___tempuri__DocAdd;
	_tempuri__DocAddResponse tempuri__DocAddResponse;
	tempuri__DocAddResponse.soap_default(soap);
	soap_default___tempuri__DocAdd(soap, &soap_tmp___tempuri__DocAdd);
	if (!soap_get___tempuri__DocAdd(soap, &soap_tmp___tempuri__DocAdd, "-tempuri:DocAdd", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->DocAdd(soap_tmp___tempuri__DocAdd.tempuri__DocAdd, tempuri__DocAddResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	tempuri__DocAddResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tempuri__DocAddResponse.soap_put(soap, "tempuri:DocAddResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tempuri__DocAddResponse.soap_put(soap, "tempuri:DocAddResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tempuri__test_(JHServiceSoapService *soap)
{	struct __tempuri__test_ soap_tmp___tempuri__test_;
	_tempuri__testResponse tempuri__testResponse;
	tempuri__testResponse.soap_default(soap);
	soap_default___tempuri__test_(soap, &soap_tmp___tempuri__test_);
	if (!soap_get___tempuri__test_(soap, &soap_tmp___tempuri__test_, "-tempuri:test", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->test_(soap_tmp___tempuri__test_.tempuri__test, tempuri__testResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	tempuri__testResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tempuri__testResponse.soap_put(soap, "tempuri:testResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tempuri__testResponse.soap_put(soap, "tempuri:testResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tempuri__ToolingTimes_(JHServiceSoapService *soap)
{	struct __tempuri__ToolingTimes_ soap_tmp___tempuri__ToolingTimes_;
	_tempuri__ToolingTimesResponse tempuri__ToolingTimesResponse;
	tempuri__ToolingTimesResponse.soap_default(soap);
	soap_default___tempuri__ToolingTimes_(soap, &soap_tmp___tempuri__ToolingTimes_);
	if (!soap_get___tempuri__ToolingTimes_(soap, &soap_tmp___tempuri__ToolingTimes_, "-tempuri:ToolingTimes", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->ToolingTimes_(soap_tmp___tempuri__ToolingTimes_.tempuri__ToolingTimes, tempuri__ToolingTimesResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	tempuri__ToolingTimesResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tempuri__ToolingTimesResponse.soap_put(soap, "tempuri:ToolingTimesResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tempuri__ToolingTimesResponse.soap_put(soap, "tempuri:ToolingTimesResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tempuri__BillState_(JHServiceSoapService *soap)
{	struct __tempuri__BillState_ soap_tmp___tempuri__BillState_;
	_tempuri__BillStateResponse tempuri__BillStateResponse;
	tempuri__BillStateResponse.soap_default(soap);
	soap_default___tempuri__BillState_(soap, &soap_tmp___tempuri__BillState_);
	if (!soap_get___tempuri__BillState_(soap, &soap_tmp___tempuri__BillState_, "-tempuri:BillState", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->BillState_(soap_tmp___tempuri__BillState_.tempuri__BillState, tempuri__BillStateResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	tempuri__BillStateResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tempuri__BillStateResponse.soap_put(soap, "tempuri:BillStateResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tempuri__BillStateResponse.soap_put(soap, "tempuri:BillStateResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tempuri__LineInventory_(JHServiceSoapService *soap)
{	struct __tempuri__LineInventory_ soap_tmp___tempuri__LineInventory_;
	_tempuri__LineInventoryResponse tempuri__LineInventoryResponse;
	tempuri__LineInventoryResponse.soap_default(soap);
	soap_default___tempuri__LineInventory_(soap, &soap_tmp___tempuri__LineInventory_);
	if (!soap_get___tempuri__LineInventory_(soap, &soap_tmp___tempuri__LineInventory_, "-tempuri:LineInventory", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->LineInventory_(soap_tmp___tempuri__LineInventory_.tempuri__LineInventory, tempuri__LineInventoryResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	tempuri__LineInventoryResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tempuri__LineInventoryResponse.soap_put(soap, "tempuri:LineInventoryResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tempuri__LineInventoryResponse.soap_put(soap, "tempuri:LineInventoryResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tempuri__AnDonStart_(JHServiceSoapService *soap)
{	struct __tempuri__AnDonStart_ soap_tmp___tempuri__AnDonStart_;
	_tempuri__AnDonStartResponse tempuri__AnDonStartResponse;
	tempuri__AnDonStartResponse.soap_default(soap);
	soap_default___tempuri__AnDonStart_(soap, &soap_tmp___tempuri__AnDonStart_);
	if (!soap_get___tempuri__AnDonStart_(soap, &soap_tmp___tempuri__AnDonStart_, "-tempuri:AnDonStart", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->AnDonStart_(soap_tmp___tempuri__AnDonStart_.tempuri__AnDonStart, tempuri__AnDonStartResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	tempuri__AnDonStartResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tempuri__AnDonStartResponse.soap_put(soap, "tempuri:AnDonStartResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tempuri__AnDonStartResponse.soap_put(soap, "tempuri:AnDonStartResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tempuri__AnDonList_(JHServiceSoapService *soap)
{	struct __tempuri__AnDonList_ soap_tmp___tempuri__AnDonList_;
	_tempuri__AnDonListResponse tempuri__AnDonListResponse;
	tempuri__AnDonListResponse.soap_default(soap);
	soap_default___tempuri__AnDonList_(soap, &soap_tmp___tempuri__AnDonList_);
	if (!soap_get___tempuri__AnDonList_(soap, &soap_tmp___tempuri__AnDonList_, "-tempuri:AnDonList", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->AnDonList_(soap_tmp___tempuri__AnDonList_.tempuri__AnDonList, tempuri__AnDonListResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	tempuri__AnDonListResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tempuri__AnDonListResponse.soap_put(soap, "tempuri:AnDonListResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tempuri__AnDonListResponse.soap_put(soap, "tempuri:AnDonListResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tempuri__AnDonOver_(JHServiceSoapService *soap)
{	struct __tempuri__AnDonOver_ soap_tmp___tempuri__AnDonOver_;
	_tempuri__AnDonOverResponse tempuri__AnDonOverResponse;
	tempuri__AnDonOverResponse.soap_default(soap);
	soap_default___tempuri__AnDonOver_(soap, &soap_tmp___tempuri__AnDonOver_);
	if (!soap_get___tempuri__AnDonOver_(soap, &soap_tmp___tempuri__AnDonOver_, "-tempuri:AnDonOver", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->AnDonOver_(soap_tmp___tempuri__AnDonOver_.tempuri__AnDonOver, tempuri__AnDonOverResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	tempuri__AnDonOverResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tempuri__AnDonOverResponse.soap_put(soap, "tempuri:AnDonOverResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tempuri__AnDonOverResponse.soap_put(soap, "tempuri:AnDonOverResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tempuri__DocAdd_(JHServiceSoapService *soap)
{	struct __tempuri__DocAdd_ soap_tmp___tempuri__DocAdd_;
	_tempuri__DocAddResponse tempuri__DocAddResponse;
	tempuri__DocAddResponse.soap_default(soap);
	soap_default___tempuri__DocAdd_(soap, &soap_tmp___tempuri__DocAdd_);
	if (!soap_get___tempuri__DocAdd_(soap, &soap_tmp___tempuri__DocAdd_, "-tempuri:DocAdd", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->DocAdd_(soap_tmp___tempuri__DocAdd_.tempuri__DocAdd, tempuri__DocAddResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	tempuri__DocAddResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tempuri__DocAddResponse.soap_put(soap, "tempuri:DocAddResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tempuri__DocAddResponse.soap_put(soap, "tempuri:DocAddResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}
/* End of server object code */