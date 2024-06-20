
#ifndef _MENU_H
#define _MENU_H

#include <iostream>
#include <list>
#include <table.hpp>
#include <manager.hpp>
#include <fab.hpp>
#include <staff.hpp>
#include <bill.hpp>


using namespace std;

typedef enum
{
    MANAGER = 1,
    STAFF
}Objects;

typedef enum
{
    TABLE_QUANTITIES = 1,
    FOOD_AND_BEVERAGE = 2,
    STAFF_MANAGEMENT
}Manager;

typedef enum
{
    ADDING = 1,
    EDITING = 2,
    DELETING = 3,
    LIST    
}FoodAndBeverage;

typedef enum
{
    ADD = 1,    
    DELETE = 2,
    LISTT   
}Employees;

typedef enum
{
    BOOKED = 1,    
    ORDERED      
}Operation;

typedef enum
{
    ADDINGG = 1,
    EDITINGG = 2,
    DELETINGG = 3,
    LISTTT = 4,
    PAYMENT
}Order;

#define PRINT_ITEM(number, item) cout << number <<". " << item << endl;
#define PRINT_MENU(...)\
    do{\
        const char *items[] = {__VA_ARGS__};\
        int size = sizeof(items)/sizeof(items[0]);\
        cout << items[0] << endl;\
        for(int i = 1; i<size-1; i++){ \
            PRINT_ITEM(i, items[i]); \
        } \
        PRINT_ITEM(0, items[size-1]); \
    }while(0)

#define MENU(...)\
    do{\
        const char *itemm[] = {__VA_ARGS__};\
        int size = sizeof(itemm)/sizeof(itemm[0]);\       
        for(int i = 0; i<size-1; i++){ \
            PRINT_ITEM(i + 1, itemm[i]); \
        } \
        PRINT_ITEM(0, itemm[size-1]); \
    }while(0)

void menu();
void manager();
void staff(); 

void tableQuantities();
void foodAndbeverage();
void staffManaging();

void booked (TableList *tableList);
void ordered ();

#endif
