/**
 * @author      : sbura (sbura@$HOSTNAME)
 * @file        : iendurox_service
 * @created     : Monday Aug 15, 2022 17:28:59 EEST
 */

#ifndef __IENDUROX_SERVICE_HPP__
#define __IENDUROX_SERVICE_HPP__

#include <atmi.h>
#include <bank.fd.h>
#include <ubf.h>
#include <string_view>
#include "ecpg_database.h"

#define SUCCEED 0
#define FAIL -1

class IEnduroxService {
public:
    virtual ~IEnduroxService() = default;
    virtual bool parseRequest(UBFH* p_ub) = 0;
    virtual bool prepareRequest(UBFH* p_ub) = 0;
    bool sendServiceRequest(std::string_view service, UBFH* p_ub,
        long& result_len);
protected:
    IEnduroxService();
    ECPGDatabase m_database;
};

#endif /* __IENDUROX_SERVICE_HPP__ */
