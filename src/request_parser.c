/**
 * Library containing the request parsing functions of the framework.
 */

#include "request_parser.h"

/**
 * This function will separate the option code from the message content.
 * 
 * ⚠️ WARNING: This function contains a hidden `malloc`, therefore, when you are done with the
 * value, you should free its memory.
 * 
 * Example:
 * ```c
 * int option_code;
 * char *message_buffer = "01                      Message content";
 * char *message_content = parseMessage(message_buffer, &option_code, LL_DEBUG);
 * 
 * printf("Option code: %d\\nMessage content: '%s'\\n", option_code, message_content);
 * 
 * free(message_content);
 * ```
 * 
 * => output:
 * ```txt
 * Option code: 1
 * Message content: 'Message content'
 * ```
 */
char *parseMessage(char *messageBuffer, int *optionCode, int mode) {
    if (strlen(messageBuffer) < NWK_OPTION_CODE_LENGTH) {
        handleRuntimeError("Incorrect message format => string too short!", getTime(), mode);
        return NULL;
    }

    char *code = strndup(messageBuffer, NWK_OPTION_CODE_LENGTH);
    char *content = strdup(messageBuffer + NWK_OPTION_CODE_LENGTH);

    sscanf(code, "%d", optionCode);

    free(code);
    return content;
}
