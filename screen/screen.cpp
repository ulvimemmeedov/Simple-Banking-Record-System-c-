#include <iostream>
#include "./log.cpp"
#include "./getAccount.cpp"
#include "./newAccount.cpp"
#include "./getBalance.cpp"
#include "./withdrawAmount.cpp"
#include "./depositAmount.cpp"

using namespace std;

void menu()
{
    GetAccount getAccount;
    NewAccount newAccount;
    WithdrawAmount withdrawAmount;
    GetBalance getBalance;
    DepositAmount depositAmount;

    int input;
    cin >> input;

    switch (input)
    {
    case 1:
        getAccount.show();
        break;
    case 2:
        newAccount.create();
        break;
    case 3:
        withdrawAmount.withdrawAmount();
        break;
    case 4:
        depositAmount.depositAmount();
        break;
    case 5:
        getBalance.getBalance();
        break;
    case 6:
         exit(1);
         break;
    default:
        cout << "wronge input" << endl;
        menu();
        break;
    }
}

class Screen
{
public:
    void init()
    {
        Log log;

        log.menuLog();
        menu();
    }
};