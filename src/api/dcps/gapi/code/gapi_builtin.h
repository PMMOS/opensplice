
#ifndef GAPI_BUILTINDATAREADER_H
#define GAPI_BUILTINDATAREADER_H

#include "gapi.h"
#include "gapi_common.h"
#include "gapi_domainEntity.h"
#include "gapi_dataReader.h"

#define MAX_BUILTIN_TOPIC 4

typedef struct BuiltinTopicTypeInfo {
    char                 *topicName;
    char                 *typeName;
    gapi_unsigned_long    defaultAllocSize;
    gapi_topicAllocBuffer defaultAllocBuffer;
    gapi_readerCopy       defaultReaderCopy;
    gapi_copyOut          defaultCopyOut;
} BuiltinTopicTypeInfo;


_Subscriber
_SubscriberBuiltinNew (
    u_participant uParticipant,
    _DomainParticipantFactory factory,
    _DomainParticipant participant);

void
_BuiltinSubscriberFree (
    _Subscriber subscriber);

_DataReader
_BuiltinDataReaderNew (
    _Subscriber subscriber,
    const char *topicName);

const char *
_BuiltinTopicName  (
    long index);

const BuiltinTopicTypeInfo *
_BuiltinTopicFindTypeInfoByName (
    const char *topicName);

const BuiltinTopicTypeInfo *
_BuiltinTopicFindTypeInfoByType (
    const char *typeName);

const char *
_BuiltinFindTopicName (
    _Entity entity);


#endif
