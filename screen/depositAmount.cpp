#include <iostream>
#include "../db/db.h"
using namespace std;

class DepositAmount {
    private:
        int no;
        int ammount;
        Db db;
    public:
        void depositAmount() {
            cout << "account number : ";
            cin >> no;
            cout << "deposit ammount : ";
            cin >> ammount;
            db.deposit(no,ammount);
        };
};