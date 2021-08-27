#include <iostream>
#include "../db/db.h"
using namespace std;

class GetBalance{
    private:
        int no;
        Db db;
    public:
        void getBalance() {
            cout << "account number : ";
            cin >> no;
            db.balance(no);
        };
};