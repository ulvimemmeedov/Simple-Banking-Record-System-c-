#include "./db/db.h"
#include "./db/db.cpp"
#include <iostream>
#include "./screen/screen.cpp"
int main()
{   
    Screen screen;

    cout << "System started" << endl;
    
    screen.init();

    return 0;
}