#include <iostream>
#include "../db/db.h"
using namespace std;

class NewAccount {
    private:
        int no;
        Db db;
    public:
        void create() {
            db.createAccount();
        };
};