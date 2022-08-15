/**
 * @author      : sbura (sbura@$HOSTNAME)
 * @file        : services
 * @created     : Monday Aug 15, 2022 19:11:27 EEST
 */

#ifndef __SERVICES_H__
#define __SERVICES_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <atmi.h>
#include <bank.fd.h>
#include <ubf.h>

void routerService(UBFH *p_ub);
void balanceService(UBFH *p_ub);

#ifdef __cplusplus
}
#endif

#endif /* __SERVICES_H__ */

