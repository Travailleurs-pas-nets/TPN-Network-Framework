/**
 * Library containing the network configuration functions of the framework.
 */

#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include "nwk_constants.h"
#include "string_manipulation.h"
#include "logger.h"
#include "chron.h"

typedef struct sockaddr_in sockaddr_in;
typedef struct hostent hostent;

/**
 * Wrapper for the unix `gethostname()` function. This allows normalised calls to standard methods.
 * 
 * TODO: Add examples.
 */
extern char *getMachineName();

/**
 * Function that will create and return a pointer towards the hostent.
 * It will throw a critical error if the retrieved host is null before return.
 * 
 * TODO: Add examples.
 */
extern hostent *retrieveHost();

/**
 * Will configure the local address to the given host and port.
 * 
 * TODO: Add examples.
 */
extern sockaddr_in configureLocalAddress(hostent *host, unsigned short port, unsigned short hostType);
