#ifndef DB
#define DB

#include "mysql_driver.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>


using namespace sql;

class Db {
    public:
       void getCustomer(int accountNo);
       void createAccount();
       void deleteAccount();
       void withdraw();
       void deposit();
       void balance();
};

#endif /* DB */