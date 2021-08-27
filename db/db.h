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
       void deleteAccount(int accountNo);
       void withdraw(int accountNo,int ammount);
       void deposit(int accountNo);
       void balance(int accountNo);
};

#endif /* DB */