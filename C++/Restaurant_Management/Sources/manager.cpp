#include <manager.hpp>



void addNewFandB (FaBList *fabList)
{    
    int idd, type1, i;
    string namee;
    TypeFaB typee;
    float pricess;
    cout << ("|---------Adding new food and beverages---------|") << endl;
    pad:
    cout << "Entering id: "; cin >> idd;
    cin.ignore();
    cout << "Entering name: "; getline(cin,namee);
    cout << "Entering type (0 Food/ 1 Beverage): "; cin >> type1;
    cout << "Entering prices: "; cin >> pricess;
    typee = (TypeFaB)type1;
    FaB fab(idd, namee, typee, pricess);       
    fabList->addNewfab(fab);
    pad1:
    cout << "---------------------------------------------------" << endl;
    cout << "DONE !" << endl;
    cout << "Do you want to continue (0 Back / 1 Continue): "; cin >> i;
    cout << "---------------------------------------------------" << endl;
    if (i == 0 ) foodAndbeverage();
    else if (i == 1 ) goto pad;
    else 
    {
        cout << "Your value does not exsist" << endl;
        goto pad1;
    }   
}

void editFandB(FaBList *fabList)
{
    int id, i;
    cout << ("|---------Editing food and beverages---------|") << endl;
    pad:   
    cout << "Please input ID: ";
    cin >> id;
    fabList->search(id);
    fabList->editFaB(id);
    pad1:
    cout << "---------------------------------------------------" << endl;    
    cout << "Do you want to continue (0 Back / 1 Continue): "; cin >> i;
    if (i == 0 ) foodAndbeverage();
    else if (i == 1 ) goto pad;
    else 
    {
        cout << "Your value does not exsist" << endl;
        goto pad1;
    } 
    cout << "---------------------------------------------------" << endl;  

}

void deleteFaB(FaBList *fabList)
{
    int id, i, c;
    cout << ("|---------Deleting food and beverages---------|") << endl;
    pad:   
    cout << "Please input ID: ";
    cin >> id;
    fabList->search(id);
    cout << "Do you want to delete (0 Y / 1 N): "; cin >> c;
    if (c == 0 ) 
    {
        fabList->deleteFaB(id);
        goto pad1;        
    }
    else if (c == 1) goto pad1;
    else 
    {
        cout << "Your value does not exsist" << endl;
        goto pad1;
    } 
    pad1:
    cout << "---------------------------------------------------" << endl;    
    cout << "Do you want to continue (0 Back / 1 Continue): "; cin >> i;
    if (i == 0 ) foodAndbeverage();
    else if (i == 1 ) goto pad;
    else 
    {
        cout << "Your value does not exsist" << endl;
        goto pad1;
    } 
    cout << "---------------------------------------------------" << endl;
}

void fabList(FaBList *fabList)
{
    int select;
    //pad:
    PRINT_MENU("|---------List---------|", 
                "Food.", 
                "Beverages.", 
                "All.",                 
                "Back.");
        cout << "Your selection: ";
        cin >> select; 
        switch ((Lists)select)
        {
        case FOODD:
            int b;
            fabList->searchFaB((TypeFaB)(select - 1));
            pad3:
            cout << "----------------------------------------------------" << endl;
            cout << "0. Back: "; cin >> b;
            if (b == 0 ) foodAndbeverage();   
            else 
            {
                cout << "Your value does not exsist" << endl;
                goto pad3;
            }           
            break;          
        case BEVERAGES:
            int c;
            fabList->searchFaB((TypeFaB)(select - 1));
            pad2:
            cout << "----------------------------------------------------" << endl;
            cout << "0. Back: "; cin >> c;
            if (c == 0 ) foodAndbeverage();   
            else 
            {
                cout << "Your value does not exsist" << endl;
                goto pad2;
            }           
            break;           
        case ALL:
            int a;
            list <FaB> menu;
             menu = fabList->fabList();
            cout << ("|--------------Food and beverages list--------------|") << endl;
            cout << setw(10) << left << "ID" << setw(20) << "Name" << setw(10) << "Type" << "Price" << endl;       
            for(list <FaB> :: iterator i = menu.begin(); i != menu.end(); i++)    
            {
                cout << setw(10) << left << i->getId();
                cout << setw(20) << i->getName();
                (i->getType() == FOOD) ?  cout << setw(10) << "FO" : cout << setw(10) << "BE" ;
                cout << i->getPrices()<< endl;
            }
            pad1:
            cout << "----------------------------------------------------" << endl;
            cout << "0. Back: "; cin >> a;
            if (a == 0 ) foodAndbeverage();   
            else 
            {
                cout << "Your value does not exsist" << endl;
                goto pad1;
            }           
            break;
        //default:                  
            //break;
        }  
}

void addStaff(StaffList *staffList)
{
    int type1, i, typest, typesh;
    string namee, idd;
    // TypeStaff typest;
    // TypeShifts typesh;
    cout << ("|---------Adding new staff---------|") << endl;
    pad:
    cout << "Entering id: "; cin >> idd;
    cin.ignore();
    cout << "Entering name: "; getline(cin,namee);
    cout << "Entering the position (0 Serve/ 1 Barista): "; cin >> typest;
    cout << "Entering the shift of working(0 Morning/ 1 Afternoon/ 2 Evening): "; cin >> typesh;    
    Staff staff(idd, namee, (TypeStaff)typest, (TypeShifts)typesh);       
    staffList->addNewStaff(staff);
    pad1:
    cout << "---------------------------------------------------" << endl;
    cout << "DONE !" << endl;
    cout << "Do you want to continue (0 Back / 1 Continue): "; cin >> i;
    cout << "---------------------------------------------------" << endl;
    if (i == 0 ) staffManaging();
    else if (i == 1 ) goto pad;
    else 
    {
        cout << "Your value does not exsist" << endl;
        goto pad1;
    }
}

void deleteStaff (StaffList *staffList)
{
    int i, c;
    string id;
    cout << ("|---------Deleting staff---------|") << endl;
    pad:   
    cout << "Please input ID: ";
    cin >> id;
    staffList->searchst(id);
    cout << "Do you want to delete (0 Y / 1 N): "; cin >> c;
    if (c == 0 ) 
    {
        staffList->deleteStaff(id);
        goto pad1;        
    }
    else if (c == 1) goto pad1;
    else 
    {
        cout << "Your value does not exsist" << endl;
        goto pad1;
    } 
    pad1:
    cout << "---------------------------------------------------" << endl;    
    cout << "Do you want to continue (0 Back / 1 Continue): "; cin >> i;
    if (i == 0 ) staffManaging();
    else if (i == 1 ) goto pad;
    else 
    {
        cout << "Your value does not exsist" << endl;
        goto pad1;
    } 
    cout << "---------------------------------------------------" << endl;

}

void staffList (StaffList *staffList)
{
    int a;
    list <Staff> menust;
    menust = staffList->staffList();
    cout << ("|--------------------Staff list---------------------|") << endl;
    cout << setw(10) << left << "ID" << setw(20) << "Name" << setw(10) << "Position" << "Shift" << endl;       
    for(list <Staff> :: iterator z = menust.begin(); z != menust.end(); z++)    
        {
            cout << setw(10) << left << z->getId();
            cout << setw(20) << z->getName();
            (z->getTypeStaff() == SERVE) ?  cout << setw(10) << "Serve" : cout << setw(10) << "Barista" ;
            if(z->getTypeShift() == MORNING)  cout << "MOR" << endl;
            else if(z->getTypeShift() == AFTERNOON) cout << "AFT" << endl;
            else cout << "EVE" << endl;            
        }
        pad1:
        cout << "----------------------------------------------------" << endl;
        cout << "0. Back: "; cin >> a;
        if (a == 0 ) staffManaging();   
        else 
        {
            cout << "Your value does not exsist" << endl;
            goto pad1;
        }              
}




 

    




