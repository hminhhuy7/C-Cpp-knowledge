#include <table.hpp>


void Table :: setNumber (int number)
{
    tableNumber = number;
}

void Table :: setStatus (TableStatus status)
{
    tableStatus = status;
}

int Table :: getNumber()
{
    return tableNumber;
}

TableStatus Table :: getStatus()
{
    return tableStatus;
}

bool Table :: compareNameBill(string i2, list <Bill> :: iterator i3)
{
    int i = 0;
    while (i2[i] == i3->getName()[i] && i2[i] != '\0' && i3->getName()[i] != '\0')
    {
        i++;
    }
    if ((int)i2[i] - (int)i3->getName()[i] == 0)
    {
        return true;
    }
    else return false;
}

void Table :: addBills (Bill bill)
{
    bills.push_back(bill);
    cout << "DONE " << endl;
}

void Table :: deleteBills (string name)
{
    for (list <Bill> :: iterator i = bills.begin(); i != bills.end(); i++ )
    {
        if (compareNameBill(name, i) == true)
        {
            bills.erase(i);
            cout << "DONE" << endl;
            break;
        }
    }  
}

list <Bill> Table :: getBills()
{
    return bills;
}

void TableList ::  addNewTables (Table table)
{
    listTable.push_back(table);    
}

void TableList:: editTables (int number, TableStatus status)
{    
    bool check, checkd = false;
    for (list <Table> :: iterator i = listTable.begin(); i != listTable.end(); i++){
        check = false;
        if(number == i->getNumber())
        {   
            check = checkd = true;        
            i->setStatus(status);
            cout << "DONE" << endl;
            break;
        }        
    }
    if (checkd == false) cout << "This number does not exsist !" << endl;
}

list <Table> TableList:: tableList()
{
    return listTable ;
}