

#ifndef _MANAGER_H
#define _MANAGER_H

#include <iostream>
#include <iomanip>
#include <table.hpp>
#include <fab.hpp>
#include <menu.hpp>
#include <staff.hpp>


using namespace std;

typedef enum
{
    FOODD = 1, 
    BEVERAGES = 2,
    ALL
}Lists;

void addNewFandB (FaBList *fabList);
void editFandB(FaBList *fabList);
void deleteFaB(FaBList *fabList);        
void fabList(FaBList *fabList);

void addStaff(StaffList *staffList);
void deleteStaff (StaffList *staffList);
void staffList (StaffList *staffList);




#endif