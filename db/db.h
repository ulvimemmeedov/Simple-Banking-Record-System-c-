#ifndef DB
#define DB

#include "mysql_driver.h"
#include <cstdlib>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/connection.h>
#include <cppconn/prepared_statement.h>

using namespace sql;
using namespace std;

class Db {
    public:
       void getCustomer(int accountNo);
       void createAccount(string name,string lastname,string tell);
       void deleteAccount(int accountNo);
       void withdraw(int accountNo,int ammount);
       void deposit(int accountNo,int ammount);
       void balance(int accountNo);
};

#endif /* DB */