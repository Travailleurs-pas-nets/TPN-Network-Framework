#pragma once

/**
 * Library containing the request building functions of the framework.
 */

#include <stdlib.h>
#include <string.h>
#include "../include/tpnll.h"
#include "nwk_constants.h"

/**
 * Function that creates a request's option code from its unsigned short representation.
 * 
 * ⚠️ WARNING: This function contains a hidden `malloc`, therefore, when you are done with the
 * value, you should free its memory.
 * 
 * Example:
 * ```c
 * char *code = assembleOptionCode(NWK_CLI_SUBSCRIBED);
 * free(code);
 * ```
 */
extern char *assembleOptionCode(unsigned short optionCode);

/**
 * Function that creates a request content from its code and message.
 * 
 * ⚠️ WARNING: This function contains a hidden `malloc`, therefore, when you are done with the
 * value, you should free its memory.
 * 
 * Example:
 * ```c
 * char *request_buffer = assembleRequestContent(NWK_CLI_SUBSCRIBED, "0");
 * free(request_buffer);
 * ```
 */
extern char *assembleRequestContent(unsigned short optionCode, char *content);
