#include "saj_fooTypeSupport.h"
#include "saj_utilities.h"
#include "gapi.h"

/* Defines the package of the java implementation classes */
#define SAJ_PACKAGENAME "org/opensplice/dds/dcps/"
#define SAJ_FUNCTION(name) Java_org_opensplice_dds_dcps_TypeSupportImpl_##name

/*
 * Class:     org_opensplice_dds_dcps_TypeSupportImpl
 * Method:    jniGetTypeName
 * Signature: (Ljava/lang/Object;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL 
SAJ_FUNCTION(jniGetTypeName)(
    JNIEnv *env, 
    jclass this, 
    jobject jtypeSupport)
{
    gapi_typeSupport typeSupport;
    gapi_string typeName;
    jstring jtypeName;
    
    jtypeName = NULL;
    typeSupport = (gapi_typeSupport)saj_read_gapi_address (env, jtypeSupport); 
    typeName = gapi_typeSupport_get_type_name (typeSupport);
    
    if(typeName){
        jtypeName = (*env)->NewStringUTF(env, typeName);
        gapi_free(typeName);
    }
    return jtypeName;
}
  
#undef SAJ_FUNCTION
