#include "./db.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
void Db::createAccount(string name, string lastname, string tell)
{
    try
    {
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::PreparedStatement *prep_stmt;
        sql::ResultSet *res;
        driver = sql::mysql::get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
        stmt = con -> createStatement();
        con->setSchema("Banking_record_db");

        const int accountCreated = rand() % 30 + 17985648;

        string accountCreated1 = to_string(accountCreated);

        prep_stmt = con->prepareStatement("INSERT INTO customer (first_Name, last_Name, account_number, account_limit, tell) VALUES (?,?,?,?,?)");

        prep_stmt->setString(1, name);
        prep_stmt->setString(2, lastname);
        prep_stmt->setInt(3, accountCreated);
        prep_stmt->setInt(4, 100);
        prep_stmt->setString(5, tell);
        prep_stmt->execute();
        cout << "successfull created your account number : " << accountCreated << endl;

        delete prep_stmt;
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
};
void Db::deleteAccount(int accountNo){

};
void Db::withdraw(int accountNo, int ammount)
{

    if (to_string(accountNo).length() < 5)
    {
        cout << " \033[1;31m account number is not the correct type \033[0m\n"
             << endl;
    }
    else
    {

        std::string accountNoMain = std::to_string(accountNo);
        std::string ammountMain = std::to_string(ammount);

        try
        {
            sql::Driver *driver;
            sql::Connection *con;
            sql::Statement *stmt;
            sql::ResultSet *res;
            driver = sql::mysql::get_driver_instance();
            con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
            con->setSchema("Banking_record_db");
            stmt = con->createStatement();

            const std::string query = "update customer set balance = balance - " + ammountMain + " where account_number = " + accountNoMain;

            stmt->execute(query);

            cout << "successfull withdraw : " << ammount << " dollar" << endl;

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
};
void Db::deposit(int accountNo, int ammount)
{
    if (to_string(accountNo).length() < 5)
    {
        cout << " \033[1;31m account number is not the correct type \033[0m\n"
             << endl;
    }
    else
    {

        std::string accountNoMain = std::to_string(accountNo);
        std::string ammountMain = std::to_string(ammount);

        try
        {
            sql::Driver *driver;
            sql::Connection *con;
            sql::Statement *stmt;
            sql::ResultSet *res;
            driver = sql::mysql::get_driver_instance();
            con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
            con->setSchema("Banking_record_db");
            stmt = con->createStatement();

            const std::string query = "update customer set balance = balance + " + ammountMain + " where account_number = " + accountNoMain;

            stmt->execute(query);

            cout << "successfull add deposit : " << ammount << " dollar" << endl;

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
};
void Db::balance(int accountNo)
{

    if (to_string(accountNo).length() < 5)
    {
        cout << to_string(accountNo).length();

        cout << " \033[1;31m account number is not the correct type \033[0m\n"
             << endl;
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
            std::cout << "Account No | "
                      << " ";
            std::cout << "Balance | "
                      << " " << std::endl;
            while (res->next())
            {
                std::cout << res->getString("first_name") << "          ";
                std::cout << res->getInt("account_number") << "         ";
                std::cout << res->getInt("balance") << "      " << std::endl;
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
};
void Db::getCustomer(int accountNo)
{

    if (to_string(accountNo).length() < 5)
    {
        cout << to_string(accountNo).length();

        cout << " \033[1;31m account number is not the correct type \033[0m\n"
             << endl;
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
