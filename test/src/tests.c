// Including µnit.
#include "../include/munit.h"

// Including test functions files.
#include "network_config_getMachineName.c"
#include "network_config_retrieveHost.c"
#include "network_config_configureLocalAddress.c"
#include "request_builder_assembleOptionCode.c"
#include "request_builder_assembleRequestContent.c"
#include "request_handler_retrieveMessage.c"
#include "request_parser_parseMessage.c"

// Defining the list of tests to execute:
static MunitTest test_array[] = {
    { (char *) "/network_config/getMachineName         \t\t", test_getMachineName, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char *) "/network_config/retrieveHost           \t\t", test_retrieveHost, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char *) "/network_config/configureLocalAddress  \t\t", test_configureLocalAddress, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char *) "/request_builder/assembleOptionCode    \t\t", test_assembleOptionCode, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char *) "/request_builder/assembleRequestContent\t\t", test_assembleRequestContent, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char *) "/request_handler/retrieveMessage       \t\t", test_retrieveMessage, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char *) "/request_parser/parseMessage           \t\t", test_parseMessage, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    
    // Last item must be this one (it is used to identify that this is the end of the list).
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// Defining the test suite:
static const MunitSuite test_suite = {
    (char *) "",
    test_array,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
    return munit_suite_main(&test_suite, "tpnn", argc, argv);
}
