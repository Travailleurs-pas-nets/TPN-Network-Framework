/**
 * Library containing the request parsing functions of the framework.
 */

#include "request_parser.h"

/**
 * This function will separate the option code from the message content.
 * 
 * TODO: Add examples.
 */
char *parseMessage(char *messageBuffer, int *optionCode) {
    char *messageContent = strdup(messageBuffer + NWK_OPTION_CODE_LENGTH);

    messageBuffer[NWK_OPTION_CODE_LENGTH] = '\0';
    sscanf(messageBuffer, "%d", optionCode);

    return messageContent;
}
