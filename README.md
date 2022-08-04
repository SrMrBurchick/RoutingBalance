****************************************************************************************************
***                                               Info                                           ***
****************************************************************************************************
https://www.endurox.org/dokuwiki/doku.php?id=enduro_x_overview
https://www.endurox.org/dokuwiki/doku.php?id=endurox:v8.0.x:guides:getting_started_tutorial#_creating_the_server_process

****************************************************************************************************
***                                             Exercise                                         ***
****************************************************************************************************

1. Install latest version of Enduro/X Middleware 8.0 (https://www.mavimax.com/downloads)
2. Install or use existing database server - Oracle or Postgres.
3. Create 2 database tables: Account, Balance
4. Develop and configure 2 EnduroX servers: Router Server, Balance Server
5. Test server calls
6. Provide ud files, test results, all configuration files, source code and compiled binaries.

Regarding DB table/field names, internal id, foreign constraints, indexes, field formats, server names and UBF field naming there are no strict requirements.
You can use any names as you prefer.

========================================
DB tables
========================================
Account:
--------
    - Account Number
    - Currency
    - Branch Code

Balance:
--------
    - Date
    - Balance

Relationships:
--------------
    Account ---< Balance
        (1 to many)

========================================
EnduroX servers
========================================
NOTE: For DB access EmbeddedSQL must be used!!!

Router Server
-------------
Input fields:
    - Account Number
    - Date
Output:
    - Human readable message
Configuration file:
    - Format: any (text, ini,...)
    - Configuration parameter: Branch
Logic:
1. Retrieve Account record from DB.
2. If account not found return human readable message "Account not found"
3. Check if Account Branch code is equal to Branch value from configuration file.
4. If codes are not equal or account does not exists then return human readable message "Branch not supported"
5. Forward request to Balance Server

Balance Server
-------------
Input fields:
    - Account Number or internal ID
    - Date
Output:
    - Human readable message
Logic:
1. Retrieve Account balance for specified date
2. If balance exists
    a) return human readable message "Account Balance: 999999.99" (where 999999.99 is actual value from db)
   else
    a) return human readable message "Account Balance not available"

========================================
Tests
========================================
Tests must be done by creating *.ud files and executing them using utility - ud.

Tests to be done:
1. Request with non existing Account
2. Request with existing Account, but from different branch (not specified in Router Server configuration)
3. Request with existing Account with data for which there is no Balance record
4. Request with existing Account and existing Balance record
