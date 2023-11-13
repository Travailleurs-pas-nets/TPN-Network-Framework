#include <stdio.h>
#include <unistd.h>
#include "../../src/request_builder.h"
#include "../include/munit.h"
#define ASSEMBLE_OPTION_CODE_TEST_VALUES_COUNT 9

typedef struct {
    unsigned short code;
    char *result;
} AssembleOptionCodeTestStruct;;

AssembleOptionCodeTestStruct assembleOptionCodeTestValues[ASSEMBLE_OPTION_CODE_TEST_VALUES_COUNT] = {
    { NWK_SRV_SUBSCRIBE, "00                      " },          // Normal case, server subscribe option code
    { NWK_SRV_UNSUBSCRIBE, "01                      " },        // Normal case, server unsubscribe option code
    { NWK_SRV_SEND_MESSAGE, "02                      " },       // Normal case, server send message option code
    { NWK_SRV_GET_ECO_SCORE, "03                      " },      // Normal case, server eco score option code
    { NWK_CLI_SUBSCRIBED, "00                      " },         // Normal case, client subscribed option code
    { NWK_CLI_UNSUBSCRIBED, "01                      " },       // Normal case, client unsubscribed option code
    { NWK_CLI_DISTRIBUTE_MESSAGE, "02                      " }, // Normal case, client distribute message option code
    { NWK_CLI_SEND_ECO_SCORE, "03                      " },     // Normal case, client send eco score option code
    { NWK_CLI_DISTRIBUTE_REMINDER, "04                      " } // Normal case, client distribute reminder option code
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
static MunitResult test_assembleOptionCode(const MunitParameter params[], void *data) {
    // Silencing the compiler
    (void) data;
    (void) params;
    
    for (int i = 0; i < ASSEMBLE_OPTION_CODE_TEST_VALUES_COUNT; i++) {
        char *expected = assembleOptionCodeTestValues[i].result;
        char *obtained = assembleOptionCode(assembleOptionCodeTestValues[i].code);

        munit_assert_string_equal(obtained, expected);

        free(obtained);
    }

    return MUNIT_OK;
}
#pragma GCC diagnostic pop
