#include <iostream>
#include <menu.hpp>

using namespace std;


int main()
{
    PRINT_MENU("|---------User Interface---------|", 
                "Manager.", 
                "Staff.", 
                "Exit.");     
    menu();
}
