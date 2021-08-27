#include <iostream>
#include "../db/db.h"
using namespace std;

class NewAccount {
    private:
        string name, lastname, tell;
        Db db;
    public:
        void create() {
            cout << "Enter first name : ";
            cin >> name;
            cout << "Enter last name : ";
            cin >> lastname;
            cout << "Enter tell : ";
            cin >> tell;
            db.createAccount( name, lastname, tell);
        };
};