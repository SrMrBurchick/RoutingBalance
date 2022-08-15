/**
 * @author      : sbura (sbura@$HOSTNAME)
 * @file        : common_data
 * @created     : Monday Aug 15, 2022 13:20:06 EEST
 */

#ifndef __COMMON_DATA_H__
#define __COMMON_DATA_H__

#include <string_view>

enum class DatabaseTables {
    eAccountTable = 0,
    eBalanceTable = 1,
    eTablesCount
};

struct Request {
    long account_number;
    std::string_view date;
    float out_balance;
};

#endif /* end of include guard __COMMON_DATA_H__ */

