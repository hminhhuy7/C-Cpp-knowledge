
#ifndef _STAFF_H
#define _STAFF_H

#include <iostream>
#include <list>
#include <string>
#include <iomanip>
#include <table.hpp>
#include <bill.hpp>
#include <fab.hpp>


using namespace std;


typedef enum
{
    SERVE,
    BARISTA
}TypeStaff;

typedef enum
{
    MORNING,
    AFTERNOON,
    EVEVING
}TypeShifts;

class Staff
{
    private:
        string id;
        string name;
        TypeStaff typest;
        TypeShifts typesh;
    public:
        Staff(string idd, string namee, TypeStaff typestt, TypeShifts typeshh )
        : id(idd), name(namee), typest(typestt), typesh(typeshh)  {};       

        // void setId (string idd);
        // void setName (string namee);
        // void setTypeStaff (TypeStaff typestt);
        // void setTypeShift (TypeShifts typeshh);

        string getId ();
        string getName ();
        TypeStaff getTypeStaff();
        TypeShifts getTypeShift();       
};

class StaffList
{
    private:
        list <Staff> listStaff;
    public:       
        void searchst(string id);
        bool compareId(string i1, list <Staff> :: iterator i2);
        void addNewStaff(Staff st);        
        void deleteStaff(string id);        
        list <Staff> staffList();
};

void tableList (TableList *tableList);
void orderFaB (TableList *tableList, FaBList *fabList, int number);
void editOrderedFab (TableList *tableList,  FaBList *fabList, int number);
void deleteOrderedFab (TableList *tableList,  FaBList *fabList, int number);
void orderedFabList (TableList *tableList);
void payment(TableList *tableList);


#endif