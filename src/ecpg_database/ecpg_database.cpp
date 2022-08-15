/**
 * @author      : sbura (sbura@$HOSTNAME)
 * @file        : ecpg_database
 * @created     : Monday Aug 15, 2022 11:39:24 EEST
 */

#include <cstdio>
#include "ecpg_database.h"
#include "ecpg_sql.h"

#define SUCCES 0

ECPGDatabase::ECPGDatabase()
    : m_isConnected(false) {}

ECPGDatabase::~ECPGDatabase()
{
}

void ECPGDatabase::disconnect()
{
    disconnect_from_database();
}

bool ECPGDatabase::connect(const std::string_view path,
    const std::string_view user,
    const std::string_view password)
{
    if (true == m_isConnected) {
        return m_isConnected;
    }

    if (SUCCES == connect_to_database(path.data(), user.data(),
                                      password.data())) {
        m_isConnected = true;
        m_target = path;
        m_user = user;
        m_passwd = password;
    }

    return m_isConnected;
}

bool ECPGDatabase::request(DatabaseTables table, Request& request)
{
    if (!m_isConnected) {
        return false;
    }

    int result = SUCCES;

    switch (table) {
        case DatabaseTables::eAccountTable:
            result = select_from_account(request.account_number);
            break;
        case DatabaseTables::eBalanceTable:
            result = select_from_balance(request.account_number,
                                         request.date.data(),
                                         &request.out_balance);
            break;
        default:
            break;
    }

    return SUCCES == result ? true : false;
}
