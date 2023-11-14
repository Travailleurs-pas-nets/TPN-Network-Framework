#include <stdio.h>
#include <unistd.h>
#include "../../src/request_handler.h"
#include "../include/munit.h"
#define RETRIEVE_MESSAGE_TEST_VALUES_COUNT 2

typedef struct {
    char *input;
    int mode;
    char *output;
} RetrieveMessageTestStruct;

RetrieveMessageTestStruct retrieveMessageTestValues[RETRIEVE_MESSAGE_TEST_VALUES_COUNT] = {
    { "I am a message", LL_DEBUG, "I am a message" },   // Normal case
    { "I am a message", LL_PROD, "I am a message" }     // Normal case
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
static MunitResult test_retrieveMessage(const MunitParameter params[], void *data) {
    // Silencing the compiler
    (void) data;
    (void) params;

    int std_backup = dup(fileno(stdout));
    int std_stream[2];
    pipe(std_stream);
    dup2(std_stream[1], fileno(stdout));
    
    for (int i = 0; i < RETRIEVE_MESSAGE_TEST_VALUES_COUNT; i++) {
        // We are going to write into a stream and see if the function returns the expected content.
        char *obtained;
        char *expected = retrieveMessageTestValues[i].output;

        int message_stream[2];

        // Setting the stream to fake the receipt of a message
        pipe(message_stream);
        write(message_stream[1], retrieveMessageTestValues[i].input, strlen(retrieveMessageTestValues[i].input) + 1);
        close(message_stream[1]);
        obtained = retrieveMessage(message_stream[0], retrieveMessageTestValues[i].mode);

        // Checking the result
        munit_assert_string_equal(obtained, expected);

        free(obtained);
    }

    close(std_stream[1]);
    dup2(std_backup, fileno(stdout));

    return MUNIT_OK;
}
#pragma GCC diagnostic pop
