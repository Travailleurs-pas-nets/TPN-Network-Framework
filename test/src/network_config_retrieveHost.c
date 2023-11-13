#include "../../src/network_config.h"
#include "../include/munit.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
static MunitResult test_retrieveHost(const MunitParameter params[], void *data) {
    hostent *obtained_debug;
    hostent *obtained_prod;

    // Silencing the compiler
    (void) data;
    (void) params;

    // Not much to test here... The best we can do is to check the result of a call's different
    // than null
    obtained_debug = retrieveHost(LL_DEBUG);
    obtained_prod = retrieveHost(LL_PROD);

    munit_assert_not_null(obtained_debug);
    munit_assert_not_null(obtained_prod);

    return MUNIT_OK;
}
#pragma GCC diagnostic pop
