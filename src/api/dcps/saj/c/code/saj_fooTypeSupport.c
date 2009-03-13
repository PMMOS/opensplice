
#include <gapi.h>
#include <os_abstract.h>
#include <os_heap.h>
#include <c_metabase.h>

#include "saj_fooTypeSupport.h"
#include "saj__fooDataReader.h"
#include "saj_copyCache.h"
#include "saj_utilities.h"
#include "saj_copyIn.h"
#include "saj_copyOut.h"
#include "saj_copyCache.h"

#include "idl_genSajMeta.h"

#include <gapi.h>

/* Defines the package of the java implementation classes */
#define SAJ_PACKAGENAME "org/opensplice/dds/dcps/"
#define SAJ_FUNCTION(name) Java_org_opensplice_dds_dcps_FooTypeSupportImpl_##name

/*
 * Class:     org_opensplice_dds_dcps_FooTypeSupportImpl
 * Method:    jniAlloc
 * Signature: (Ljava/lang/Object;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL
SAJ_FUNCTION(jniAlloc) (
    JNIEnv *env,
    jclass object,
    jobject TypeSupport,
    jstring type_name,
    jstring key_list,
    jarray type_descriptor)
{
    const char *typeName;
    const char *keyList;
    char *typeDescriptor;
    PA_ADDRCAST typeSupport;    
    int statusOK = TRUE;
    jsize type_descriptor_length;

#if 0
    char line[100];

    printf ("Waiting:\n");
    gets (line);
#endif
    typeName = (*env)->GetStringUTFChars (env, type_name, NULL);
    /* Convert key_list */
    keyList = (*env)->GetStringUTFChars (env, key_list, NULL);

    /* Convert type_descriptor */
    type_descriptor_length = (*env)->GetArrayLength(env, type_descriptor);
    typeDescriptor = os_malloc(type_descriptor_length * IDL_MAX_JSTRING_META_SIZE + 1);
    
    if (typeDescriptor) {
        jsize i;
        typeDescriptor[0] = '\0';
        for (i = 0; i < type_descriptor_length && statusOK; i++) {
            jstring type_descriptor_frame = (jstring) (*env)->GetObjectArrayElement(env, type_descriptor, i);
            if (type_descriptor_frame) {
                const char *typeDescriptorFrame = (*env)->GetStringUTFChars (env, type_descriptor_frame, NULL);
                if (typeDescriptorFrame) {
                    strcat(typeDescriptor, typeDescriptorFrame);
                    (*env)->ReleaseStringUTFChars (env, type_descriptor_frame, typeDescriptorFrame);
                } else {
                    statusOK = FALSE;
                }
            } else {
                statusOK = FALSE;
            }
        }  
    } 

    if (typeName != NULL && keyList != NULL && typeDescriptor != NULL && statusOK) {
        typeSupport = (PA_ADDRCAST)gapi_fooTypeSupport__alloc (
            typeName,
            keyList,
            typeDescriptor,
            NULL, /* type_load */
            saj_copyInStruct, /* copyIn: copy in Java types */
            saj_copyOutStruct, /* copyOut: copy out Java types */
            0,    /* alloc_size */
            NULL, /* alloc buffer */
            NULL, /* writer copy */
            saj_dataReaderCopy, /* reader copy */
            NULL, /* create datawriter */
            NULL  /* create datareader */
            );
        if (typeSupport) {
            saj_write_gapi_address (env, TypeSupport, typeSupport);
            saj_write_java_address (env, (gapi_object)typeSupport, TypeSupport);
        } else {
            return SAJ_RETCODE_ERROR;
        }
    }

    /* Release used strings */
    if (type_name) {
        (*env)->ReleaseStringUTFChars (env, type_name, typeName);
    }
    if (key_list) {
        (*env)->ReleaseStringUTFChars (env, key_list, keyList);
    }
    if (typeDescriptor) {
        os_free(typeDescriptor);
    }

    return SAJ_RETCODE_OK;
}

/*
 * Class:     org_opensplice_dds_dcps_FooTypeSupportImpl
 * Method:    jniFree
 * Signature: (Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL
SAJ_FUNCTION(jniFree) (
    JNIEnv *env,
    jclass object,
    jobject TypeSupport)
{
    gapi_free ((gapi_fooTypeSupport)saj_read_gapi_address (env, TypeSupport));

    return GAPI_RETCODE_OK;
}

/*
 * Class:     org_opensplice_dds_dcps_FooTypeSupportImpl
 * Method:    jniRegisterType
 * Signature: (Ljava/lang/Object;LDDS/DomainParticipant;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL
SAJ_FUNCTION(jniRegisterType) (
    JNIEnv *env,
    jclass object,
    jobject TypeSupport,
    jobject participant,
    jstring type_alias)
{
    const char *typeAlias;
    const char *typeName;
    jint result;
    jclass typeSupportClass;
    jfieldID copyCache_fid;
    c_metaObject typeMeta;
    saj_copyCache copyCache;
 
    /* Convert type_alias */
    if (type_alias != NULL) {
        typeAlias = (*env)->GetStringUTFChars (env, type_alias, NULL);
    }  else {
        typeAlias = NULL;
    }

    /* Call GAPI register type function */
    result = gapi_fooTypeSupport_register_type (
            	(gapi_fooTypeSupport)saj_read_gapi_address (env, TypeSupport),
            	(gapi_typeSupport)saj_read_gapi_address (env, participant),
            	(gapi_string)typeAlias);
    if (result == GAPI_RETCODE_OK) {
    	typeName = gapi_typeSupport_get_type_name ((gapi_typeSupport)saj_read_gapi_address (env, TypeSupport));
    	typeMeta = (c_metaObject)gapi_domainParticipant_get_type_metadescription (
	    (gapi_domainParticipant)saj_read_gapi_address (env, participant), typeName);
      
    	if (typeMeta) {
    	    copyCache = saj_copyCacheNew (env, typeMeta);
    	    if (copyCache) {
    	        typeSupportClass = (*env)->GetObjectClass (env, TypeSupport);
    		copyCache_fid = (*env)->GetFieldID (env, typeSupportClass, "copyCache", "J");
    		(*env)->SetLongField (env, TypeSupport, copyCache_fid, (jlong)(PA_ADDRCAST)copyCache);
    	    } else {
    	        result = GAPI_RETCODE_ERROR;
    	    }
    	} else {
    	    result = GAPI_RETCODE_ERROR;
    	}
    }
    /* Release used strings */
    if (type_alias != NULL) {
        (*env)->ReleaseStringUTFChars (env, type_alias, typeAlias);
    }
    return (jint)result;
}

#undef SAJ_FUNCTION
