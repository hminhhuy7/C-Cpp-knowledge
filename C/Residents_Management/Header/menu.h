/*
* File: menu.h
* Author: Nguyen Huynh Minh Huy
* Date: 15/01/2024
* Description: This is a header file to declare for menu.c 
*/

#ifndef _MENU_H
#define _MENU_H

#include <stdio.h>

#define PRINT_ITEM(number, item) printf("  %d. %s\r\n", number, item)
#define PRINT_MENU(...)\
    do{\
        const char *items[] = {__VA_ARGS__};\
        int size = sizeof(items)/sizeof(items[0]);\
        printf("%s\r\n",items[0]);\
        for(int i = 1; i<size-1; i++){ \
            PRINT_ITEM(i, items[i]); \
        } \
        PRINT_ITEM(0, items[size-1]); \
    }while(0)

void menu();
void _add();
void _delete();
void _edit();
void _search();

#endif