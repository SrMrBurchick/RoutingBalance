/**
 * @author      : sbura (sbura@$HOSTNAME)
 * @file        : router_service
 * @created     : Monday Aug 15, 2022 18:09:38 EEST
 */

#ifndef __ROUTER_SERVICE_HPP__
#define __ROUTER_SERVICE_HPP__

#include <string>
#include "iendurox_service.hpp"

class RouterService : public IEnduroxService
{
public:
    RouterService () = default;
    virtual ~RouterService () = default;
    virtual bool parseRequest(UBFH* p_ub) override;
    virtual bool prepareRequest(UBFH* p_ub) override;
private:
    long m_account_number;
    std::string m_date;
};

#endif /* __ROUTER_SERVICE_HPP__ */
