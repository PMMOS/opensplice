#ifndef NW_SOCKET_H
#define NW_SOCKET_H

#include "os_time.h"

typedef struct nw_socket_s *nw_socket;
typedef unsigned char  sk_bool;
typedef unsigned short sk_portNr;     /* Internally converted into n_port_t */
typedef unsigned long  sk_length;     /* Internally converted into size_t */
typedef unsigned long  sk_address;    /* Networking address */
typedef unsigned long  sk_partitionId; /* Networking partition */

typedef enum sk_addressType_e {
    SK_TYPE_UNKNOWN,
    SK_TYPE_LOOPBACK,
    SK_TYPE_BROADCAST,
    SK_TYPE_MULTICAST
} sk_addressType;


nw_socket   nw_socketSendNew(
                const char *defaultAddress,
                sk_portNr portNr,
                sk_bool supportsControl,
                const char *pathName);

nw_socket   nw_socketReceiveNew(
                const char *defaultAddress,
                sk_portNr portNr,
                sk_bool supportsControl,
                const char *pathName);

void        nw_socketFree(
                nw_socket sock);
                

sk_bool     nw_socketLoopsback(
                nw_socket sock);

                
sk_address  nw_socketPrimaryAddress(
                nw_socket sock);

sk_address  nw_socketBrodcastAddress(
                nw_socket sock);

sk_address  nw_socketDataAddress(
                nw_socket sock);

int         nw_socketPrimaryAddressCompare(
                nw_socket sock,
                sk_address toCompare);
                
                

void        nw_socketAddPartition(
                nw_socket sock,
                sk_partitionId partitionId,
                const char *addressString,
                sk_bool connected);

sk_length   nw_socketSendData(
                nw_socket sock,
                void *buffer,
                sk_length length);

sk_length   nw_socketSendDataTo(
                nw_socket sock,
                sk_address receiverAddress,
                void *buffer,
                sk_length length);

sk_length   nw_socketSendDataToPartition(
                nw_socket sock,
                sk_partitionId partitionId,
                void *buffer,
                sk_length length);
                

sk_length   nw_socketSendControlTo(
                nw_socket sock,
                sk_address receiverAddress,
                void *buffer,
                sk_length length);

sk_length   nw_socketReceive(
                nw_socket sock,
                sk_address *senderAddress,
                void *buffer,
                sk_length length,
                os_time *timeOut);
int         nw_socketBind(
                nw_socket sock);
                       
#endif /* NW_SOCKET_H */

