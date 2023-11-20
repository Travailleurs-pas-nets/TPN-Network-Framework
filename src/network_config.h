#pragma once

/**
 * Library containing the network configuration functions of the framework.
 */

#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include "../include/tpnll.h"
#include "nwk_constants.h"

typedef struct sockaddr_in sockaddr_in;
typedef struct hostent hostent;

/**
 * Wrapper for the unix `gethostname()` function. This allows normalised calls to standard methods.
 * 
 * ⚠️ WARNING: This function contains a hidden `malloc`, therefore, when you are done with the
 * value, you should free its memory.
 * 
 * Example:
 * ```c
 * char *machine_name = getMachineName();
 * free(machine_name);
 * ```
 */
extern char *getMachineName();

/**
 * Function that will create and return a pointer towards the hostent.
 * It will throw a critical error if the retrieved host is null before return.
 * 
 * ⚠️ WARNING: This function contains a hidden `malloc`, therefore, when you are done with the
 * value, you should free its memory.
 * 
 * Example:
 * ```c
 * hostent *host = retrieveHost(LL_DEBUG);
 * free(host);
 * ```
 */
extern hostent *retrieveHost(int mode);

/**
 * Will configure the local address to the given host and port.
 * 
 * Example:
 * ```c
 * hostent *host = retrieveHost(LL_DEBUG);
 * sockaddr_in local_address = configureLocalAddress(host, 5000, NWK_SERVER);
 * 
 * free(host);
 * ```
 */
extern sockaddr_in configureLocalAddress(hostent *host, unsigned short port, unsigned short hostType);
