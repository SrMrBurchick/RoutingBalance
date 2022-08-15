/**
 * @author      : sbura (sbura@$HOSTNAME)
 * @file        : ecpg_database
 * @created     : Monday Aug 15, 2022 11:34:43 EEST
 */

#ifndef __ECPG_DATABASE_H__
#define __ECPG_DATABASE_H__

#include <string_view>

#include "../common/common_data.h"

class ECPGDatabase {
public:
    ECPGDatabase();
    ~ECPGDatabase();

    bool connect(const std::string_view path,
                 const std::string_view user,
                 const std::string_view password);

    bool request(DatabaseTables table, Request& request);

    void disconnect();
private:
    bool m_isConnected;
    std::string_view m_target;
    std::string_view m_user;
    std::string_view m_passwd;
};

#endif /* end of include guard __ECPG_DATABASE_H__ */

