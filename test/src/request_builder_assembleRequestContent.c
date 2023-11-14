#include <stdio.h>
#include <unistd.h>
#include "../../src/request_builder.h"
#include "../include/munit.h"
#define ASSEMBLE_REQUEST_CONTENT_TEST_VALUES_COUNT 18

typedef struct {
    unsigned short code;
    char *content;
    char *result;
} AssembleRequestContentTestStruct;

AssembleRequestContentTestStruct assembleRequestContentTestValues[ASSEMBLE_REQUEST_CONTENT_TEST_VALUES_COUNT] = {
    { NWK_SRV_SUBSCRIBE, "MESSAGE_CONTENT", "00                      MESSAGE_CONTENT" },            // Normal case
    { NWK_SRV_UNSUBSCRIBE, "MESSAGE_CONTENT", "01                      MESSAGE_CONTENT" },          // Normal case
    { NWK_SRV_SEND_MESSAGE, "MESSAGE_CONTENT", "02                      MESSAGE_CONTENT" },         // Normal case
    { NWK_SRV_GET_ECO_SCORE, "MESSAGE_CONTENT", "03                      MESSAGE_CONTENT" },        // Normal case
    { NWK_CLI_SUBSCRIBED, "MESSAGE_CONTENT", "00                      MESSAGE_CONTENT" },           // Normal case
    { NWK_CLI_UNSUBSCRIBED, "MESSAGE_CONTENT", "01                      MESSAGE_CONTENT" },         // Normal case
    { NWK_CLI_DISTRIBUTE_MESSAGE, "MESSAGE_CONTENT", "02                      MESSAGE_CONTENT" },   // Normal case
    { NWK_CLI_SEND_ECO_SCORE, "MESSAGE_CONTENT", "03                      MESSAGE_CONTENT" },       // Normal case
    { NWK_CLI_DISTRIBUTE_REMINDER, "MESSAGE_CONTENT", "04                      MESSAGE_CONTENT" },  // Normal case
    { NWK_SRV_SUBSCRIBE, "", "00                      " },                                          // Edge case
    { NWK_SRV_UNSUBSCRIBE, "", "01                      " },                                        // Edge case
    { NWK_SRV_SEND_MESSAGE, "", "02                      " },                                       // Edge case
    { NWK_SRV_GET_ECO_SCORE, "", "03                      " },                                      // Edge case
    { NWK_CLI_SUBSCRIBED, "", "00                      " },                                         // Edge case
    { NWK_CLI_UNSUBSCRIBED, "", "01                      " },                                       // Edge case
    { NWK_CLI_DISTRIBUTE_MESSAGE, "", "02                      " },                                 // Edge case
    { NWK_CLI_SEND_ECO_SCORE, "", "03                      " },                                     // Edge case
    { NWK_CLI_DISTRIBUTE_REMINDER, "", "04                      " }                                 // Edge case
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
static MunitResult test_assembleRequestContent(const MunitParameter params[], void *data) {
    // Silencing the compiler
    (void) data;
    (void) params;
    
    for (int i = 0; i < ASSEMBLE_REQUEST_CONTENT_TEST_VALUES_COUNT; i++) {
        char *expected = assembleRequestContentTestValues[i].result;
        char *obtained = assembleRequestContent(assembleRequestContentTestValues[i].code, assembleRequestContentTestValues[i].content);

        munit_assert_string_equal(obtained, expected);

        free(obtained);
    }

    return MUNIT_OK;
}
#pragma GCC diagnostic pop
