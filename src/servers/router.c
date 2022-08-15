#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Enduro/X includes: */
#include <atmi.h>
#include <bank.fd.h>
#include <ubf.h>
#include "services.h"

#define SUCCEED 0
#define FAIL -1

/**
 * Router service
 */
void ROUTER(TPSVCINFO *p_svc) {
    int ret = SUCCEED;
    BFLDLEN len;

    UBFH *p_ub = (UBFH *)p_svc->data;

    fprintf(stderr, "ROUTER got call\n");

    /* Resize the buffer to have some space in... */
    if (NULL == (p_ub = (UBFH *)tprealloc((char *)p_ub, 1024))) {
        fprintf(stderr, "Failed to realloc the UBF buffer - %s\n",
                tpstrerror(tperrno));
        ret = FAIL;
        goto out;
    }

    routerService(p_ub);

out:
    tpreturn(ret == SUCCEED ? TPSUCCESS : TPFAIL, 0L, (char *)p_ub, 0L, 0L);
}

/**
 * Do initialization
 */
int tpsvrinit(int argc, char **argv) {
    if (SUCCEED != tpadvertise("ROUTER", ROUTER)) {
        fprintf(stderr, "Failed to advertise ROUTER - %s\n",
                tpstrerror(tperrno));
        return FAIL;
    }

    return SUCCEED;
}

/**
 * Do de-initialization
 */
void tpsvrdone(void) { fprintf(stderr, "tpsvrdone called\n"); }
