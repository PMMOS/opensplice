#ifndef GAPI_DATAVIEW_H
#define GAPI_DATAVIEW_H

#include "gapi.h"
#include "gapi_common.h"
#include "gapi_set.h"
#include "gapi_domainEntity.h"
#include "gapi_status.h"
#include "gapi_loanRegistry.h"

#define U_DATAREADERVIEW_GET(r) \
        u_dataView(U_ENTITY_GET(r))

#define U_DATAREADERVIEW_SET(r,e) \
        _EntitySetUserEntity(_Entity(r), u_entity(e))

#define _DataReaderView(o) ((_DataReaderView)(o))

#define gapi_dataReaderViewClaim(h,r) \
        (_DataReaderView(gapi_objectClaim(h,OBJECT_KIND_DATAVIEW,r)))

#define gapi_dataReaderViewClaimNB(h,r) \
        (_DataReaderView(gapi_objectClaimNB(h,OBJECT_KIND_DATAVIEW,r)))

#define _DataReaderViewAlloc() \
        (_DataReaderView(_ObjectAlloc(OBJECT_KIND_DATAVIEW, \
                                      C_SIZEOF(_DataReaderView), \
                                      NULL)))

C_STRUCT(_DataReaderView) {
    C_EXTENDS(_DomainEntity);
   _DataReader        datareader;
    gapi_set          conditionSet;
    gapi_loanRegistry loanRegistry;
    u_query           uQuery;
    gapi_readerMask   reader_mask;
};

_DataReaderView
_DataReaderViewNew (
    const gapi_dataReaderViewQos * qos,
    const _DataReader datareader);

void
_DataReaderViewFree (
    _DataReaderView _this);

gapi_boolean
_DataReaderViewPrepareDelete (
    _DataReaderView _this,
    gapi_context *context);

_DataReader
_DataReaderViewDataReader(
    _DataReaderView _this);

u_dataView
_DataReaderViewUreaderView (
    _DataReaderView _this);

#endif
