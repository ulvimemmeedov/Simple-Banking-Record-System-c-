#include <iostream>
#include "../db/db.h"
using namespace std;

class GetAccount {
    private:
        int no;
        Db db;
    public:
        void show() {
            cout << "account number : ";
            cin >> no;
            db.getCustomer(no);
        };
};