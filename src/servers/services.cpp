/**
 * @author      : sbura (sbura@$HOSTNAME)
 * @file        : services
 * @created     : Monday Aug 15, 2022 19:15:23 EEST
 */

#include <iostream>
#include <cstdio>
#include "services.h"
#include "router_service.hpp"
#include "balance_service.hpp"

extern "C" {

void routerService(UBFH *p_ub)
{
    static RouterService service;

    if (false == service.parseRequest(p_ub)) {
        std::cout << "Account not found" << std::endl;
    }
}

void balanceService(UBFH *p_ub)
{
    static BalanceService service;

    if (false == service.parseRequest(p_ub)) {
        std::cout << "Account Balance not available" << std::endl;
    } else {
        printf("Yoy nay bude!\n");
    }
}

}
