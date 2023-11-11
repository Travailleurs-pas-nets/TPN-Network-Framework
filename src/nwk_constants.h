/**
 * File containing the constants of the framework
 */

#define NWK_CLIENT 0
#define NWK_SERVER 1

/** Defining server option codes */
#define NWK_SRV_SUBSCRIBE 0
#define NWK_SRV_UNSUBSCRIBE 1
#define NWK_SRV_SEND_MESSAGE 2
#define NWK_SRV_GET_ECO_SCORE 3

/** Defining client option codes */
#define NWK_CLI_SUBSCRIBED 0
#define NWK_CLI_UNSUBSCRIBED 1
#define NWK_CLI_DISTRIBUTE_MESSAGE 2
#define NWK_CLI_SEND_ECO_SCORE 3
#define NWK_CLI_DISTRIBUTE_REMINDER 4

#define NWK_OPTION_CODE_LENGTH 24
#define NWK_MAX_MESSAGE_LENGTH 1024
#define NWK_MAX_HOST_NAME_LENGTH 256
