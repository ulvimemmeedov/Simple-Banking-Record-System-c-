#include <iostream>
#include "../db/db.h"
using namespace std;

class WithdrawAmount {
    private:
        int ammount;
        int no;
        Db db;
    public:
        void withdrawAmount() {
            cout << "account number : ";
            cin >> no;
            cout << "ammount : ";
            cin >> ammount;
            db.withdraw();
        };
};