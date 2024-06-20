/*
* File: main.c
* Author: Nguyen Huynh Minh Huy
* Date: 15/01/2024
* Description: This is a main file, which uses for combinng other files together to run the programe.
*/

#include <stdio.h>
#include <management.h>
#include <menu.h>

int main(int argc, char const *argv[])
{
    pad: 
    //system("cls");    
    PRINT_MENU("|----- Apartment Manager -----|","Add Member", "Delete Member", "Edit Member", "Search Member", "Exit");        
    menu();      
    goto pad; 
    return 0;
}

