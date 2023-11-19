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
 * ⚠️ WARNING: This function contains a hidden `malloc`, therefore, when you are done with the
 * value, you should free its memory.
 * 
 * Example:
 * ```c
 * char *message_buffer = retrieveMessage(socketDescriptor, LL_DEBUG);
 * free(message_buffer);
 * ```
 */
extern char *retrieveMessage(int transferSocket, int mode);
