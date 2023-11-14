/**
 * Library containing the request parsing functions of the framework.
 */

#include "request_parser.h"

/**
 * This function will separate the option code from the message content.
 * 
 * TODO: Add examples.
 */
char *parseMessage(char *messageBuffer, int *optionCode, int mode) {
    if (strlen(messageBuffer) < NWK_OPTION_CODE_LENGTH) {
        handleRuntimeError("Incorrect message format => string too short!", getTime(), mode);
        return NULL;
    }

    char *code = strndup(messageBuffer, NWK_OPTION_CODE_LENGTH);
    char *content = strdup(messageBuffer + NWK_OPTION_CODE_LENGTH);

    sscanf(code, "%d", optionCode);

    return content;
}
