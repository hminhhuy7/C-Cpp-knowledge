#include <staff.hpp>
#include <menu.hpp>


string Staff :: getId ()
{
    return id;
}

string Staff :: getName ()
{
    return name;
}

TypeStaff Staff :: getTypeStaff()
{
    return typest;
}
        
TypeShifts Staff :: getTypeShift()
{
    return typesh;
} 

bool StaffList :: compareId(string i1, list <Staff> :: iterator i2)
{
    int i = 0;
    while (i1[i] == i2->getId()[i] && i1[i] != '\0' && i2->getId()[i] != '\0')
    {
        i++;
    }
    if ((int)i1[i] - (int)i2->getId()[i] == 0)
    {
        return true;
    }
    else return false;
}

void StaffList :: searchst(string id)
{  
    cout << setw(10) << left << "ID" << setw(20) << "Name" << setw(10) << "Position" << "Shift" << endl;  
    for (list <Staff> :: iterator i = listStaff.begin(); i != listStaff.end(); i++ )
    {        
        if (compareId(id,i) == true)
        {    
            cout << setw(10) << left << i->getId();
            cout << setw(20) << i->getName();
            (i->getTypeStaff() == SERVE) ?  cout << setw(10) << "Serve" : cout << setw(10) << "Barista" ;
            if(i->getTypeShift() == MORNING)  cout << "MOR" << endl;
            else if(i->getTypeShift() == AFTERNOON) cout << "AFT" << endl;
            else cout << "EVE" << endl;
        }       
    }    
}

void StaffList :: addNewStaff(Staff st)
{
     listStaff.push_back(st);    
}

void StaffList :: deleteStaff(string id)
{
    for (list <Staff> :: iterator i = listStaff.begin(); i != listStaff.end(); i++ )
    {
        if (compareId(id,i) == true)
        {
            listStaff.erase(i);
            cout << "DONE" << endl;
            break;
        }
    }
}

list <Staff> StaffList :: staffList()
{
    return listStaff;
}

void tableList (TableList *tableList)
{
    list <Table> menu = tableList->tableList();
    cout << ("|----------------------------------------Tables list-----------------------------------------|") << endl;
    cout << setw(9) << left << "Tables|" ;    
    for (list <Table> :: iterator i = menu.begin(); i != menu.end(); i++)
    {
        cout << setw(4) << i->getNumber();        
    }
    cout << setw(10) << left << "\nStatus|";
    for (list <Table> :: iterator i = menu.begin(); i != menu.end(); i++)
    {
        (i->getStatus() == AVAILABLE) ? cout << setw(4) << "O" : cout << setw(4) << "X";
    }
}

void orderFaB (TableList *tableList, FaBList *fabList, int number)
{
    bool checkk = false;
    string name, fb;
    float prices; 
    int quant, i;
    list <FaB> menu = fabList->fabList();
    pad: 
    cout << ("\n|-------------------------------------------------------------------------------------------|") << endl;   
    cin.ignore();  
    cout <<"Please the name of Food or Beverages: ";
    getline(cin,name);
    cout << setw(20) << left << "Name" << "Price" << endl;  
    for(list <FaB> :: iterator i = menu.begin(); i != menu.end(); i++)
    {
        if(fabList->compareNameFaB(name, i))
        {
            checkk = true;
            cout << setw(20) << left << i->getName();
            cout << i->getPrices() << endl;
            fb = i->getName();
            prices = i->getPrices();
            break;
        }
    }
    if (checkk == false) 
    {
        cout << "Food or Beverages does not exsist !";
        goto pad;
    }
    cout <<"Please input quantities: ";
    cin >> quant; 
    Bill bill (fb, prices, quant);   
    list <Table> menu1 = tableList->tableList();
    for (list <Table> :: iterator i = menu1.begin(); i != menu1.end(); i++)
    {
        if (number == i->getNumber())
        {
            i->addBills(bill);                                    
        }        
    }
    pad1:
    cout << "Do you want to continue (0 Back / 1 Continue): "; cin >> i;    
    if (i == 0 ) ordered();
    else if (i == 1 ) goto pad;
    else 
    {
        cout << "Your value does not exsist" << endl;
        goto pad1;
    }
}

void editOrderedFab (TableList *tableList,  FaBList *fabList, int number)
{
    bool checkk = false;
    string name;    
    int quant, i;
    list <FaB> menu = fabList->fabList();
    pad:     
    cout << ("\n|-------------------------------------------------------------------------------------------|") << endl;   
    cin.ignore();  
    cout <<"Please the name of Food or Beverages: ";
    getline(cin,name);
    cout << setw(20) << left << "Name" << "Price" << endl;  
    for(list <FaB> :: iterator i = menu.begin(); i != menu.end(); i++)
    {
        if(fabList->compareNameFaB(name, i))
        {
            checkk = true;
            cout << setw(20) << left << i->getName();
            cout << i->getPrices() << endl; 
            break;
        }
    }
    if (checkk == false) 
    {
        cout << "Food or Beverages does not exsist !";
        goto pad;
    }
    cout <<"Please input quantities again: ";
    cin >> quant; 

    list <Table> menu1 = tableList->tableList();
    for (list <Table> :: iterator i = menu1.begin(); i != menu1.end(); i++)
    {
        if (number == i->getNumber())
        {            
            cout << "hihihi" << endl;
            list <Bill> menu2 = i->getBills();
            // if(menu2.empty() == true) cout <<"co" << endl;
            // else cout << "Khong" << endl;
            for (list <Bill> :: iterator y = menu2.begin(); y != menu2.end(); y++)
            {                
                cout << "DONE " << endl;
                y->setQuantities(quant);                       
            }        
        }                    
    }
    pad1:
    cout << "Do you want to continue (0 Back / 1 Continue): "; cin >> i;    
    if (i == 0 ) ordered();
    else if (i == 1 ) goto pad;
    else 
    {
        cout << "Your value does not exsist" << endl;
        goto pad1;
    }
}

void deleteOrderedFab (TableList *tableList,  FaBList *fabList, int number)
{
    bool checkk = false;
    string name;    
    int quant, i;
    list <FaB> menu = fabList->fabList();
    pad: 
    cout << ("\n|-------------------------------------------------------------------------------------------|") << endl;   
    cin.ignore();  
    cout <<"Please the name of Food or Beverages: ";
    getline(cin,name);
    cout << setw(20) << left << "Name" << "Price" <<  endl;  
    for(list <FaB> :: iterator i = menu.begin(); i != menu.end(); i++)
    {
        if(fabList->compareNameFaB(name, i))
        {
            checkk = true;
            cout << setw(20) << left << i->getName();
            cout << i->getPrices() << endl;                     
        }
    }
    if (checkk == false) 
    {
        cout << "Food or Beverages does not exsist !";
        goto pad;
    }
    cout <<"Do you want to delete (0 Y/ 1 N): ";
    cin >> quant; 
    if (quant == 0)
    {
        list <Table> menu1 = tableList->tableList();
        for (list <Table> :: iterator i = menu1.begin(); i != menu1.end(); i++)
        {
            if (number == i->getNumber())
            {
                cout << "DONE " << endl;
                i->deleteBills(name);              
            }
        }
  
    }
    else if (quant == 1)
    {
        ordered();
    }
    else goto pad;
    pad1:
    cout << "Do you want to continue (0 Back / 1 Continue): "; cin >> i;    
    if (i == 0 ) ordered();
    else if (i == 1 ) goto pad;
    else 
    {
        cout << "Your value does not exsist" << endl;
        goto pad1;
    }

}

void orderedFabList (TableList *tableList)
{
    list <Table> menu = tableList->tableList();
    cout << setw(5) << left << "Ord" << setw(20) << "Name" << setw(10) << "Price" << "Quantities" << endl;  
    for (list <Table> :: iterator i = menu.begin(); i != menu.end(); i++)
    {
        if (i->getBills().empty() == true ) cout << "C";
        else cout << "Khong";
        list <Bill> menu1 = i->getBills();        
        for (list <Bill> :: iterator j = menu1.begin(); j != menu1.end(); i++)
        {
            cout << setw(5) << left << j->getOrder();
            cout << setw(20) <<  j->getName();
            cout << setw(10) <<  j->getPrices();
            cout << j->getQuantities() << endl;                  
        }   
    }
}

void payment(TableList *tableList)
{
    list <Table> menu = tableList->tableList();
    cout << setw(5) << left << "Ord" << setw(20) << "Name" << setw(10) << "Price" << setw(10) << "Quantities" << "Total" << endl;  
    for (list <Table> :: iterator i = menu.begin(); i != menu.end(); i++)
    {
        if (i->getBills().empty() == true ) cout << "C";
        else cout << "Khong";
        list <Bill> menu1 = i->getBills();        
        for (list <Bill> :: iterator j = menu1.begin(); j != menu1.end(); i++)
        {
            cout << setw(5) << left << j->getOrder();
            cout << setw(20) <<  j->getName();
            cout << setw(10) <<  j->getPrices();
            cout << setw(10) << j->getQuantities();
            cout << j->getTotal();                 
        }   
    }
    int a;
    cout <<  "1. Thanh toan: ";
    cin >> a;
    cout <<  "\nDONE";
}











