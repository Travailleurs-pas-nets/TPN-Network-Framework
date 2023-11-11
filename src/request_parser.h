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
 * TODO: Add examples.
 */
extern char *parseMessage(char *messageBuffer, int *optionCode);
