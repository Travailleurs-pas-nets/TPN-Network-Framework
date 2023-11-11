/**
 * Library containing the request handling functions of the framework.
 */

#include <stdlib.h>
#include <unistd.h>
#include "../include/tpnll.h"
#include "nwk_constants.h"

/**
 * Function reading a request content from a socket.
 * It will display an error message if a received message is empty, and return an empty buffer in
 * that case.
 * 
 * TODO: Add examples.
 */
extern char *retrieveMessage(int transferSocket, int mode);
