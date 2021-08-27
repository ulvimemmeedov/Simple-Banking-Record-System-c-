#include <iostream>
using namespace std;

class Log {
    private:
        string logs[5] = {"1 account get data : ","2 new account : ","3 withdraw amount : ","4 deposit amount : ","5 get balance : "};
    public:
       void menuLog(){
           for(string log : logs)
           {
               cout << log << endl;
           }
           cout<<"select : ";
       }

};