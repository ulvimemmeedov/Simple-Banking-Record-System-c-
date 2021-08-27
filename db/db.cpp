#include "./db.h"
#include <iostream>
#include <string>
using namespace std;
void Db::createAccount(){
    cout << "created";
};
void Db::deleteAccount(){
    cout << "delete";
};
void Db::withdraw(){
        cout << "withdraw";
};
void Db::deposit(){
    cout << "deposit";
};
void Db::balance(){
    cout << "balance";
};
void Db::getCustomer(int accountNo)
{

    if (to_string(accountNo).length() < 5)
    {
        cout <<to_string(accountNo).length();
        
        cout << " \033[1;31m account number is not the correct type \033[0m\n" << endl;
    }
    else
    {
        std::string accountNoMain = std::to_string(accountNo);

        try
        {
            const std::string query = "SELECT * from customer where account_number = " + accountNoMain;
            std::cout << query << std::endl;
            sql::Driver *driver;
            sql::Connection *con;
            sql::Statement *stmt;
            sql::ResultSet *res;
            driver = sql::mysql::get_driver_instance();
            con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
            con->setSchema("Banking_record_db");
            stmt = con->createStatement();

            res = stmt->executeQuery(query);
            std::cout << "First name | "
                      << " ";
            std::cout << "Last Name | "
                      << " ";
            std::cout << "Account No | "
                      << " ";
            std::cout << "Balance | "
                      << " ";
            std::cout << "Account Limit |"
                      << " ";
            std::cout << "Tell" << std::endl;

            while (res->next())
            {
                std::cout << res->getString("first_name") << "          ";
                std::cout << res->getString("last_Name") << "         ";
                std::cout << res->getInt("account_number") << "         ";
                std::cout << res->getInt("balance") << "      ";
                std::cout << res->getInt("account_limit") << "           ";
                std::cout << res->getString("tell") << "        " << std::endl;
            }
            delete res;
            delete stmt;
            delete con;
        }
        catch (sql::SQLException &e)
        {
            std::cout << "# ERR: SQLException in " << __FILE__;
            std::cout << "(" << __FUNCTION__ << ") on line " << std::endl;
            std::cout << "# ERR: " << e.what();
            std::cout << " (MySQL error code: " << e.getErrorCode();
            std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
        }
    }
}