#include "../../src/network_config.h"
#include "../include/munit.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
static MunitResult test_getMachineName(const MunitParameter params[], void *data) {
    unsigned int obtained;

    // Silencing the compiler
    (void) data;
    (void) params;

    // Not much to test here... The best we can do is to check the result of a call's length equals
    // the expected length.
    obtained = (unsigned int) strlen(getMachineName());

    munit_assert_uint32(obtained, <=, NWK_MAX_HOST_NAME_LENGTH);

    return MUNIT_OK;
}
#pragma GCC diagnostic pop
