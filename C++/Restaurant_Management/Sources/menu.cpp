#include <menu.hpp>




void menu()
{
    int select;           
    cout << "Your selection: ";
    cin >> select;    
    switch ((Objects)select)
    {
    case MANAGER:   manager();
        break;      
    case STAFF:     staff();
        break;        
    case 0: system("cls");         
    default:            
        break;
    }
}

void manager ()
{
    int select;   
    PRINT_MENU("|---------Manager---------|", 
                "Set up table quantities.", 
                "Set up food and beverages.", 
                "Staff management.", 
                "Back.");
        cout << "Your selection: ";
        cin >> select; 
        switch ((Manager)select)
        {
        case TABLE_QUANTITIES: tableQuantities();  
            break;
        case FOOD_AND_BEVERAGE: foodAndbeverage();
            break;
        case STAFF_MANAGEMENT: staffManaging();
            break;
        case 0:
            PRINT_MENU("|---------User Interface---------|", 
                "Manager.", 
                "Staff.", 
                "Exit.");
            menu();
        break; 
        default:
            break;
        }     
}


TableList list3;
void tableQuantities ()
{        
    TableStatus status = AVAILABLE;    
    int tableNumber, back, i;
    list <Bill> listBill;
    cout << ("|---------Set up table quantities---------|") << endl;
    cout << "Please input table quantities: ";
    cin >> tableNumber;   
    for (i = 1; i <= tableNumber; i++)
    {
        Table table(i, status, listBill);        
        list3.addNewTables(table);         
    }
    pad:
    cout << "The quantities of tables: " << tableNumber << endl << "Press 0 to back ";
    cin >> back;
    if (back == 0) manager();          
    else goto pad;
}

FaBList list1;
void foodAndbeverage()
{    
    int select;    
    PRINT_MENU("|---------Set up food and beverages---------|", 
                "Adding new food and beverages.", 
                "Editing food and beverages.", 
                "Deleting food and beverages.", 
                "Food and beverages list",
                "Back.");
        cout << "Your selection: ";
        cin >> select; 
    switch ((FoodAndBeverage)select)
    {
    case ADDING:  addNewFandB (&list1);    
        break;
    case EDITING: editFandB(&list1);
        break;
    case DELETING: deleteFaB(&list1);;
        break;
    case LIST:    fabList(&list1);
        break;
    case 0:    manager();
        break;    
    default:       
        break;
        }  
    } 

StaffList list2;
void staffManaging()
{
    int select;    
    PRINT_MENU("|---------Staff management---------|", 
                "Adding new staff.",                 
                "Deleting staff.", 
                "Staff list.",
                "Back.");
        cout << "Your selection: ";
        cin >> select; 
    switch ((Employees)select)
    {
    case ADD:  addStaff(&list2);        
        break;
    case DELETE: deleteStaff (&list2);   
        break;
    case LISTT: staffList (&list2);       
        break;
    case 0:  manager();        
        break; 
    default:
        break;
    }
} 


void staff()
{
    int select;    
    PRINT_MENU("|--------------Staff--------------|", 
                "Table booking.",                 
                "Food and beverages booking.",                 
                "Back.");
    cout << "Your selection: ";
    cin >> select;
    switch ((Operation)select)
    {
    case BOOKED: 
        tableList(&list3);
        booked(&list3); 
        break;
    case ORDERED:        
        tableList(&list3);
        ordered();
        break; 
    case 0:
        PRINT_MENU("|---------User Interface---------|", 
                "Manager.", 
                "Staff.", 
                "Exit.");
        menu();
        break;    
    default:
        break;
    }    

}

void booked (TableList *tableList)
{
    int a, status,i;     
    cout << ("\n|-------------------------------------------------------------------------------------------|") << endl;
    paddd:  
    cout <<"\nPlease input the number of table: ";
    cin >> a;    
    cout << "Please input the status of table (0 AVAILABLE/ 1 UNAVAILABLE): ";
    cin >> status;
    tableList->editTables(a,(TableStatus)status);  
    padd:
    cout << "---------------------------------------------------" << endl;   
    cout << "Do you want to continue (0 Back / 1 Continue): "; cin >> i;
    cout << "---------------------------------------------------" << endl;
    if (i == 0 ) staff();
    else if (i == 1 ) goto paddd;
    else 
    {
        cout << "Your value does not exsist" << endl;
        goto padd;
    }
}

void ordered ()
{
    int b, select;
    cout << ("\n|-------------------------------------------------------------------------------------------|") << endl;
    pad1:  
    cout <<"Please input the number of table: ";
    cin >> b;     
    cout << ("\n|-------------------------------------------------------------------------------------------|") << endl;
    cout << "Table " << b << endl;
    MENU ("Adding Food and Beverages.", 
        "Editing Food and Beverages.", 
        "Deleting Food and Beverages.",
        "Ordered Food and Beverages List",
        "Making the payment",
        "Back.");
    cout << "Your selection: ";
    cin >> select;
    switch ((Order)select)
    {
    case ADDINGG :   orderFaB (&list3, &list1, b);    
        break;
    case EDITINGG :  editOrderedFab(&list3, &list1, b);   
        break;
    case DELETINGG : deleteOrderedFab(&list3, &list1, b);   
        break;
    case LISTTT :    orderedFabList (&list3);   
        break;
    case PAYMENT :   payment(&list3);
        break;
    case 0 :       staff();     
        break;
    default:
        break;
    }    
}



