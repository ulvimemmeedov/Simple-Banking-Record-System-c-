#include <iostream>
#include "../db/db.h"
using namespace std;

class DepositAmount {
    private:
        int no;
        Db db;
    public:
        void depositAmount() {
            cout << "account number : ";
            cin >> no;
            db.deposit();
        };
};