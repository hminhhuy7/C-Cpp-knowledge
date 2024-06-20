
#ifndef _TABLE_H
#define _TABLE_H

#include <iostream>
#include <list>
#include <bill.hpp>


using namespace std;

typedef enum
{
    AVAILABLE,
    UNAVAILABLE
} TableStatus;

class Table
{
   private:
      int tableNumber;
      TableStatus tableStatus;   
      list <Bill> bills;   
   public:
      Table(int number, TableStatus status = AVAILABLE, list <Bill> billss = {})
      : tableNumber(number), tableStatus(status), bills(billss)  {};

      void setNumber (int number);
      void setStatus (TableStatus status);

      int getNumber();
      TableStatus getStatus();
      bool compareNameBill(string i2, list <Bill> :: iterator i3);
      void addBills (Bill bill);
      void deleteBills (string name);
      list <Bill> getBills();
};

class TableList
{
   private:
       list <Table> listTable;     
   public:       
       void addNewTables (Table table);
       void editTables (int number, TableStatus status);       
       list <Table> tableList();
};


#endif