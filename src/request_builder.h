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
 * TODO: Add examples.
 */
extern char *assembleOptionCode(unsigned short optionCode);

/**
 * Function that creates a request content from its code and message.
 * 
 * TODO: Add examples.
 */
extern char *assembleRequestContent(unsigned short optionCode, char *content);
