#include <iostream>
using namespace std;

class Log {
    private:
        string logs[6] = {"1 Get account data ","2 New account ","3 Withdraw amount ","4 Deposit amount ","5 Get balance ","6 Quit "};
    public:
       void menuLog(){
           for(string log : logs)
           {
               cout << log << endl;
           }
           cout<<"select : ";
       }

};