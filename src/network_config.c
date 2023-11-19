/**
 * Library containing the network configuration functions of the framework.
 */

#include "network_config.h"

/**
 * Wrapper for the unix `gethostname()` function. This allows normalised calls to standard methods.
 * 
 * ⚠️ WARNING: This function contains a hidden `malloc`, therefore, when you are done with the
 * value, you should free its memory.
 * 
 * Example:
 * ```c
 * char *machine_name = getMachineName();
 * free(machine_name);
 * ```
 */
char *getMachineName() {
    char *machineName = malloc(NWK_MAX_HOST_NAME_LENGTH + 1);
    gethostname(machineName, NWK_MAX_HOST_NAME_LENGTH);
    return machineName;
}

/**
 * Function that will create and return a pointer towards the hostent.
 * It will throw a critical error if the retrieved host is null before return.
 * 
 * ⚠️ WARNING: This function contains a hidden `malloc`, therefore, when you are done with the
 * value, you should free its memory.
 * 
 * Example:
 * ```c
 * hostent *host = retrieveHost(LL_DEBUG);
 * free(host);
 * ```
 */
hostent *retrieveHost(int mode) {
    hostent *host;
    char *hostName;
    
    hostName = getMachineName();
    host = gethostbyname(hostName);

    if (host == NULL) {
        char *errorMessage = concat(3, "Host not found ('", hostName, "')\n");
        handleCriticalError(errorMessage, getTime(), mode);
    }

    free(hostName);
    return host;
}

/**
 * Will configure the local address to the given host and port.
 * 
 * Example:
 * ```c
 * hostent *host = retrieveHost(LL_DEBUG);
 * sockaddr_in local_address = configureLocalAddress(host, 5000, NWK_SERVER);
 * 
 * free(host);
 * ```
 */
sockaddr_in configureLocalAddress(hostent *host, unsigned short port, unsigned short hostType) {
    sockaddr_in localAddress;

    bcopy((char *)host->h_addr_list[0], (char *)&localAddress.sin_addr, host->h_length);
    if (hostType == NWK_SERVER) localAddress.sin_addr.s_addr = INADDR_ANY;
    localAddress.sin_family = host->h_addrtype;

    localAddress.sin_port = htons(port);

    return localAddress;
}
