#include <iostream>
#include <string>
#include "NewUser.h"
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

int main()
{
    int exit1 = 0;
    int exit2 = 0;
    NewUser one ("N/A","N/A", "N/A", "N/A" ,0,0);
    while (exit1 != 1){//run program until the user decides to leave
        one.Menu(); // all user interface was implemented in the NewUser.cpp
        if ((one.exit3 == 1))
        {
            exit1 = 1;
            exit2 = 1;
        }
        else
        {
            exit1 = 0;
            exit2 = 0;
        }
        while (exit2 != 1)
        {
            one.userMenu();
        }
    }
    return 0;
}

