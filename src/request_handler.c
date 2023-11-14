/**
 * Library containing the request handling functions of the framework.
 */

#include "request_handler.h"

/**
 * Function reading a request content from a socket.
 * It will display an error message if a received message is empty, and return an empty buffer in
 * that case.
 * 
 * TODO: Add examples.
 */
char *retrieveMessage(int transferSocket, int mode) {
    int messageLength;
    char *messageBuffer = malloc(NWK_MAX_MESSAGE_LENGTH);

    messageLength = read(transferSocket, messageBuffer, NWK_MAX_MESSAGE_LENGTH);
    if (messageLength <= 0) {
        handleRuntimeError("Empty message received\n", getTime(), mode);
    }
    debug("[INFO] %s: Message received => '%s'\n", getTime(), messageBuffer, mode);

    return messageBuffer;
}
