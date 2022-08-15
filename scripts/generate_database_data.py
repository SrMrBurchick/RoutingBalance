import random

CURRENCIES = ["UAH", "USD", "EUR", "YEN"]
SQL_SCRIPT = "data_generator.sql"
ACCOUNTS = []

account_request = """
INSERT INTO account (account_number, currency, branch_code)
    VALUES('{acc_num}', '{currency}', '{code}'
);
"""

balance_request = """
INSERT INTO balance (account_number, balance, date)
    VALUES('{acc_num}', '{balance}', '{date}'
);
"""


def main():
    with open(SQL_SCRIPT, 'w') as script:
        for _ in range(1000):
            acc_num = int(random.uniform(100000000, 999999999))
            ACCOUNTS.append(acc_num)
            currency = CURRENCIES[int(random.uniform(0, len(CURRENCIES)))]
            code = int(random.uniform(100000000, 999999999))
            script.write("{}\n".format(account_request.format(acc_num=acc_num,
                                                              currency=currency,
                                                              code=code)))

        for _ in range(10000):
            acc_num = ACCOUNTS[int(random.uniform(0, len(ACCOUNTS)))]
            currency = int(random.uniform(0, 3))
            balance = random.uniform(-23000, 900000000)
            date = "{year}-{month}-{day}".format(year=int(random.uniform(1998, 2023)),
                                                 month=int(random.uniform(1, 12)),
                                                 day=int(random.uniform(1, 31)))
            script.write("{}\n".format(balance_request.format(acc_num=acc_num,
                                                              balance=balance,
                                                              date=date)))

        acc_num = 100000
        ACCOUNTS.append(acc_num)
        currency = CURRENCIES[int(random.uniform(0, len(CURRENCIES)))]
        code = int(random.uniform(100000000, 999999999))
        script.write("{}\n".format(account_request.format(acc_num=acc_num,
                                                          currency=currency,
                                                          code=code)))



if __name__ == "__main__":
    main()
