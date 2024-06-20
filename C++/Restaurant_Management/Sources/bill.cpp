#include <bill.hpp>

void Bill :: setQuantities(int quant)
{
    quantities = quant;
}

int Bill :: getOrder()
{
    return order;
}

string Bill :: getName()
{
    return name;
}   

float Bill :: getPrices()
{
    return prices;
}

int Bill :: getQuantities()
{
    return quantities;
}

float Bill :: getTotal()
{
    return prices * quantities;

}

bool BillList :: compareNameBill(string i2, list <Bill> :: iterator i3)
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

void BillList :: searchFaB(string name)
{
    cout << setw(20) << left << "Name" << "Price" << endl;  
    for (list <Bill> :: iterator i = listBill.begin(); i != listBill.end(); i++ )
    {        
        if (compareNameBill(name,i) == true)
        {              
            cout << setw(20) << left << i->getName();
            cout << i->getPrices();            
        }       
    }   
}  

void BillList :: orderFaB(Bill bill)
{
    listBill.push_back(bill);
}

void BillList :: editOrderedFaB(string name)
{
    bool check,checkd = false;
    int quant;
    cout << "-------------------------------------------------" << endl;    
    for (list <Bill> :: iterator i = listBill.begin(); i != listBill.end(); i++ )
    {
        check = false;
        if (compareNameBill(name,i) == true)
        {            
            checkd = check = true;
            cout << "Please input new quantities: ";
            cin >> quant;
            i->setQuantities(quant);
            cout << "DONE" << endl;
        }       
    }
    if (checkd == false)   cout << "Your F and B does not exsist !" << endl;    
}

void BillList :: deleteOrderedFaB(string name)
{
    for (list <Bill> :: iterator i = listBill.begin(); i != listBill.end(); i++ )
    {
        if (compareNameBill(name, i) == true)
        {
            listBill.erase(i);
            cout << "DONE" << endl;
            break;
        }
    }    
}   

list <Bill> BillList ::  billList()
{
    return listBill;
}  

