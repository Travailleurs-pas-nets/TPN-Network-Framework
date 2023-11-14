#include <stdio.h>
#include <unistd.h>
#include "../../src/request_parser.h"
#include "../include/munit.h"
#define PARSE_MESSAGE_TEST_VALUES_COUNT 18

typedef struct {
    char *message;
    int code;
    char *content;
} ParseMessageTestStruct;

ParseMessageTestStruct parseMessageTestValues[PARSE_MESSAGE_TEST_VALUES_COUNT] = {
    { "00                      MESSAGE_CONTENT", NWK_SRV_SUBSCRIBE, "MESSAGE_CONTENT" },            // Normal case
    { "01                      MESSAGE_CONTENT", NWK_SRV_UNSUBSCRIBE, "MESSAGE_CONTENT" },          // Normal case
    { "02                      MESSAGE_CONTENT", NWK_SRV_SEND_MESSAGE, "MESSAGE_CONTENT" },         // Normal case
    { "03                      MESSAGE_CONTENT", NWK_SRV_GET_ECO_SCORE, "MESSAGE_CONTENT" },        // Normal case
    { "00                      MESSAGE_CONTENT", NWK_CLI_SUBSCRIBED, "MESSAGE_CONTENT" },           // Normal case
    { "01                      MESSAGE_CONTENT", NWK_CLI_UNSUBSCRIBED, "MESSAGE_CONTENT" },         // Normal case
    { "02                      MESSAGE_CONTENT", NWK_CLI_DISTRIBUTE_MESSAGE, "MESSAGE_CONTENT" },   // Normal case
    { "03                      MESSAGE_CONTENT", NWK_CLI_SEND_ECO_SCORE, "MESSAGE_CONTENT" },       // Normal case
    { "04                      MESSAGE_CONTENT", NWK_CLI_DISTRIBUTE_REMINDER, "MESSAGE_CONTENT" },  // Normal case
    { "00                      ", NWK_SRV_SUBSCRIBE, "" },                                          // Edge case
    { "01                      ", NWK_SRV_UNSUBSCRIBE, "" },                                        // Edge case
    { "02                      ", NWK_SRV_SEND_MESSAGE, "" },                                       // Edge case
    { "03                      ", NWK_SRV_GET_ECO_SCORE, "" },                                      // Edge case
    { "00                      ", NWK_CLI_SUBSCRIBED, "" },                                         // Edge case
    { "01                      ", NWK_CLI_UNSUBSCRIBED, "" },                                       // Edge case
    { "02                      ", NWK_CLI_DISTRIBUTE_MESSAGE, "" },                                 // Edge case
    { "03                      ", NWK_CLI_SEND_ECO_SCORE, "" },                                     // Edge case
    { "04                      ", NWK_CLI_DISTRIBUTE_REMINDER, "" }                                 // Edge case
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
static MunitResult test_parseMessage(const MunitParameter params[], void *data) {
    // Silencing the compiler
    (void) data;
    (void) params;
    
    for (int i = 0; i < PARSE_MESSAGE_TEST_VALUES_COUNT; i++) {
        int expectedCode = parseMessageTestValues[i].code;
        char *expected = parseMessageTestValues[i].content;

        int obtainedCode = 0;
        char *obtained = parseMessage(parseMessageTestValues[i].message, &obtainedCode, LL_DEBUG);

        munit_assert_int32(obtainedCode, ==, expectedCode);
        munit_assert_string_equal(obtained, expected);

        //free(obtained);
    }

    return MUNIT_OK;
}
#pragma GCC diagnostic pop
