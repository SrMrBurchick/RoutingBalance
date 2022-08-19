/**
 * @author      : sbura (sbura@$HOSTNAME)
 * @file        : BalanceService
 * @created     : Monday Aug 15, 2022 18:13:26 EEST
 */

#include <string>
#include "balance_service.hpp"
#include "bank.fd.h"

bool BalanceService::parseRequest(UBFH* p_ub)
{
    BFLDLEN len;
    char account[28 + 1];
    char date[10 + 1];

    /* Read the account field */
    len = sizeof(account);
    if (SUCCEED != Bget(p_ub, T_ACCNUM, 0, account, &len)) {
        fprintf(stderr, "Failed to get T_ACCNUM[0]! -  %s\n",
                Bstrerror(Berror));

        return false;
    }

    /* Read the currency field */
    len = sizeof(date);
    if (SUCCEED != Bget(p_ub, T_BDATE, 0, date, &len)) {
        fprintf(stderr, "Failed to get T_BDATE[0]! -  %s\n",
                Bstrerror(Berror));

        return false;
    }

    fprintf(stdout, "Recived request: account = %s, date = %s\n",
            account, date);

    /* Create sql request */
    Request request;
    request.account_number = std::stol(account);
    request.date = date;

    if (m_database.request(DatabaseTables::eBalanceTable, request)) {
        printf("Account Balance: %f\n", request.out_balance);
        return true;
    }

    return false;
}

bool BalanceService::prepareRequest(UBFH* p_ub)
{
    /* NOTHING TO DO */
    return false;
}
