/**
 * @author      : sbura (sbura@$HOSTNAME)
 * @file        : ecpg_sql
 * @created     : Monday Aug 15, 2022 13:34:10 EEST
 */

#ifndef __ECPG_SQL_H__
#define __ECPG_SQL_H__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

int connect_to_database(const char* path, const char* user,
    const char* password);
void disconect_connect_from_database();


long select_from_account(long account_number);
int select_from_balance(long account_number, const char* date,
    float* out_balance);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif /* end of include guard __ECPG_SQL_H__ */

