#pragma once

/**
 * Library containing the request parsing functions of the framework.
 */

#include <string.h>
#include <stdio.h>
#include "../include/tpnll.h"
#include "nwk_constants.h"

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
extern char *parseMessage(char *messageBuffer, int *optionCode, int mode);
