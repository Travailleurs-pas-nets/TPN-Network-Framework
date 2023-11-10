/**
 * Library containing the request building functions of the framework.
 */

#include "request_builder.h"

/**
 * Function that creates a request's option code from its unsigned short representation.
 * 
 * TODO: Add examples.
 */
char *assembleOptionCode(unsigned short optionCode) {
    char *codeValue;
    char *optionCodeString = malloc(sizeof(char) * (NWK_OPTION_CODE_LENGTH + 1));

    codeValue = intToChars(optionCode);
    optionCodeString[0] = '0';
    for (int i = 1; i <= strlen(codeValue); i++) {
        optionCodeString[i] = codeValue[i - 1];
    }
    for (int i = strlen(codeValue) + 1; i < NWK_OPTION_CODE_LENGTH; i++) {
        optionCodeString[i] = ' ';
    }

    optionCodeString[NWK_OPTION_CODE_LENGTH] = '\0';
    return optionCodeString;
}

/**
 * Function that creates a request content from its code and message.
 * 
 * TODO: Add examples.
 */
char *assembleRequestContent(unsigned short optionCode, char *content) {
    char *optionCodeString = assembleOptionCode(optionCode);
    return concat(2, optionCodeString, content);
}
