/**
 * @author      : sbura (sbura@$HOSTNAME)
 * @file        : balance_service
 * @created     : Monday Aug 15, 2022 18:09:38 EEST
 */

#ifndef __BALANCE_SERVICE_HPP__
#define __BALANCE_SERVICE_HPP__

#include "iendurox_service.hpp"

class BalanceService : public IEnduroxService
{
public:
    BalanceService () = default;
    virtual ~BalanceService () = default;
    virtual bool parseRequest(UBFH* p_ub) override;
    virtual bool prepareRequest(UBFH* p_ub) override;
};

#endif /* __BALANCE_SERVICE_HPP__ */
