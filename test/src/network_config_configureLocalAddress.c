#include "../../src/network_config.h"
#include "../include/munit.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
static MunitResult test_configureLocalAddress(const MunitParameter params[], void *data) {
    sockaddr_in obtained_server;
    sockaddr_in obtained_client;
    hostent *host = retrieveHost(LL_DEBUG);

    // Silencing the compiler
    (void) data;
    (void) params;

    // Not much to test here...
    obtained_server = configureLocalAddress(host, 8000, NWK_SERVER);
    obtained_client = configureLocalAddress(host, 8001, NWK_CLIENT);

    // One assertion, but more by principle than anything else
    munit_assert_int32(obtained_server.sin_addr.s_addr, ==, INADDR_ANY);

    return MUNIT_OK;
}
#pragma GCC diagnostic pop
