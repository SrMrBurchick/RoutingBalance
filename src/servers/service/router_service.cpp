/**
 * @author      : sbura (sbura@$HOSTNAME)
 * @file        : RouterService
 * @created     : Monday Aug 15, 2022 18:13:26 EEST
 */

#include <cstdio>
#include <sstream>

#include "router_service.hpp"
#include "bank.fd.h"

bool RouterService::parseRequest(UBFH* p_ub)
{
    BFLDLEN len;
    long result_len;
    char account[28 + 1];
    char date[10 + 1];

    std::printf("PADLO!\n");
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

    m_date = std::string(date);
    m_account_number = std::stol(account);

    fprintf(stdout, "Recived request: account = %s, date = %s\n",
            account, date);

    /* Create sql request */
    Request request;
    request.account_number = m_account_number;
    request.date = date;

    if (!m_database.request(DatabaseTables::eAccountTable, request)) {

        return false;
    }


    fprintf(stdout, "ALYO! request: account = %s, date = %s\n",
            account, date);

    sendServiceRequest("BALANCE", p_ub, result_len);

    return true;
}

bool RouterService::prepareRequest(UBFH* p_ub)
{
    long rsplen;
    std::stringstream account_number;

    account_number << m_account_number;

    /* Set the data */
    if (SUCCEED != Badd(p_ub, T_ACCNUM, (char*)account_number.str().c_str(), 0) ||
        SUCCEED != Badd(p_ub, T_BDATE, (char*)m_date.c_str(), 0)) {
        fprintf(stderr, "Failed to update buffer! -  %s\n",
                Bstrerror(Berror));
            return false;
    }

    return true;
}
