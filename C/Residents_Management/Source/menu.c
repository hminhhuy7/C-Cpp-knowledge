#include <management.h>
#include <menu.h>

/*
* Function: menu
* Description: This function is used for displaying menu when being called.
* Input: None.
* Output: a menu with 4 selections would be displayed in console screen.
*/
void menu()
{
    int select;
    printf("Your choice: ");
    scanf("%d", &select);  
    switch (select)
        {
        case 1: _add(); break;         
        case 2: _delete(); break; 
        case 3: _edit(); break; 
        case 4: _search(); break;
        //default: printf ("Your selection does not exist. Thank you.\n");
        break;         
    }
}

/*
* Function: _add
* Description: This function is used for adding a new member into csv file when being called.
* Input: None.
* Output: a new member would be added in csv file.
*/
void _add(){
    Member newMember;
    printf("|----- Add New Member -----|\n");
    printf("Entering User ID: ");
    scanf("%s",newMember.uId);
    printf("Entering Room Number: ");
    scanf("%s",newMember.roomNumber);
    printf("Entering Name: ");
    scanf("%s",newMember.name);    
    printf("Entering License Plates: ");
    scanf("%s",newMember.licensePlate);
    addMember("test1.csv", newMember);    
}

/*
* Function: _delete
* Description: This function is used for deleting any members into csv file according to their user ID.
* Input: None.
* Output: a member would be deleted in csv file.
*/
void _delete()
{
    char uid[20];
    printf ("|------ Delete Member ------|\n");
    printf ("Please enter uId: ");
    scanf("%s",uid);
    deleteMember("test1.csv", uid);
}

/*
* Function: _edit
* Description: This function is used for editing any members' information into csv file according to their user ID.
* Input: None
* Output: a member with their new information would be updated information into csv file.
*/
void _edit()
{   char uid[20];
    Member updatedMember;
    printf("|----- Edit Member -----|\n");
    printf("Entering New User ID: ");
    scanf("%s",updatedMember.uId);
    printf("Entering New Room Number: ");
    scanf("%s",updatedMember.roomNumber);
    printf("Entering New Name: ");
    scanf("%s",updatedMember.name);       
    printf("Entering New License Plates: ");
    scanf("%s",updatedMember.licensePlate);
    printf("Entering Current User ID: ");
    scanf("%s",uid);
    editMember("test1.csv", updatedMember, uid);  
}

/*
* Function: _search
* Description: This function is used for finding any members into csv file according to their user ID and License Plate..
* Input: None.
* Output: a member's informantion would be displayed on console screen.
*/
void _search()
{
    int select;
    Type type;
    Member uidOutput, licenseOutput;
    printf ("|------ Search Member ------|\n");
    printf ("Searching by (0 uId / 1 LicensePlate): ");
    scanf("%d", &select);
    type = (Type)select;
    switch (type)
    {
    case UID:
        char uidInput[20];
        printf ("Please enter uId: ");
        scanf("%s",uidInput);
        uidOutput = searchMember("test1.csv", uidInput, searchByUID);        
        if (searchByUID(&uidOutput,uidInput) != 0) 
        {
            printf("uId does not exsist !\n");
        }
        else{
            printf("Information's member:\nuId: %s - Room Number: %s - Name: %s - License Plate: %s\n",
            uidOutput.uId, uidOutput.roomNumber, uidOutput.name, uidOutput.licensePlate);
        }
        break;
    case LICENSE_PLATE:
        char licenseInput[20];  
        int i;      
        printf ("Please enter License Plate: ");
        scanf("%s",licenseInput);
        while(licenseInput[i] != '\0')
                i++;
            licenseInput[i] = '\n';
            licenseInput[i+1] = '\0';
        licenseOutput = searchMember("test1.csv", licenseInput, searchByLicensePlate);          
        if (searchByLicensePlate(&licenseOutput,licenseInput) != 0) 
        {
            printf("LicensePlate does not exsist !\n");
        }
        else{
            printf("Information's member:\nuId: %s - Room Number: %s - Name: %s - License Plate: %s\n",
            licenseOutput.uId, licenseOutput.roomNumber, licenseOutput.name, licenseOutput.licensePlate);
        }
        break;    
    default:
        break;
    }
}