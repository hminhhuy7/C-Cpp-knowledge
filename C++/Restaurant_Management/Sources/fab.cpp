#include <fab.hpp>

void FaB :: setId (int idd)
{
    id = idd;
}

void FaB :: setName (string namee)
{
    name = namee;
}

void FaB :: setType (TypeFaB typee)
{
    type = typee;
}

void FaB :: setPrices (float pricess)
{
    prices = pricess;
}

int FaB :: getId ()
{
    return id;
}

string FaB :: getName ()
{
    return name;
}

TypeFaB FaB :: getType()
{
    return type;
}
        
float FaB :: getPrices()
{
    return prices;
}    

void FaBList :: addNewfab(FaB fb)
{
    listFaB.push_back(fb);
}

void FaBList :: editFaB(int id)
{
    bool check,checkd = false;
    float pricess;
    cout << "-------------------------------------------------" << endl;    
    for (list <FaB> :: iterator i = listFaB.begin(); i != listFaB.end(); i++ )
    {
        check = false;
        if (id == i->getId())
        {            
            checkd = check = true;
            cout << "Please input new prices: ";
            cin >> pricess;
            i ->setPrices(pricess);
            cout << "DONE" << endl;
        }       
    }
    if (checkd == false)   cout << "Your ID does not exsist !" << endl;
    
}

void FaBList :: deleteFaB(int id)
{
    for (list <FaB> :: iterator i = listFaB.begin(); i != listFaB.end(); i++ )
    {
        if (id == i->getId())
        {
            listFaB.erase(i);
            cout << "DONE" << endl;
            break;
        }
    }
}

void FaBList :: search(int id)
{  
    cout << setw(10) << left << "ID" << setw(20) << "Name" << setw(10) << "Type" << "Price" << endl;  
    for (list <FaB> :: iterator i = listFaB.begin(); i != listFaB.end(); i++ )
    {
        
        if (id == i->getId())
        {    
            cout << setw(10) << left << i->getId();
            cout << setw(20) << i->getName();
            (i->getType() == FOOD) ?  cout << setw(10) << "FO" : cout << setw(10) << "BE" ;
            cout << i->getPrices()<< endl;
        }       
    }    
}

void FaBList :: searchFaB(TypeFaB fo)
{  
    cout << setw(10) << left << "ID" << setw(20) << "Name" << setw(10) << "Type" << "Price" << endl;  
    for (list <FaB> :: iterator i = listFaB.begin(); i != listFaB.end(); i++ )
    {
        
        if (fo == i->getType())
        {    
            cout << setw(10) << left << i->getId();
            cout << setw(20) << i->getName();
            (i->getType() == FOOD) ?  cout << setw(10) << "FO" : cout << setw(10) << "BE" ;
            cout << i->getPrices()<< endl;            
        }       
    }    
}

bool FaBList :: compareNameFaB(string i2, list <FaB> :: iterator i3)
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


list <FaB> FaBList :: fabList()
{
    return listFaB;
}











       
       
        

