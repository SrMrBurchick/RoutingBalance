/**
 * @author      : sbura (sbura@$HOSTNAME)
 * @file        : iendurox_service
 * @created     : Monday Aug 15, 2022 17:40:16 EEST
 */

#include "iendurox_service.hpp"

IEnduroxService::IEnduroxService()
{
    m_database.connect("account_balance",
                       "endurox",
                       "000");
}

bool IEnduroxService::sendServiceRequest(std::string_view service,
    UBFH* p_ub, long& result_len)
{
    if (FAIL == tpcall((char *)service.data(), (char*)p_ub, 0L, (char**)&p_ub,
                       &result_len, 0)) {
        return false;
    }

    return true;
}
