#include <management.h>

/*
* Function: createMemberNode
* Description: This function is used for creating a new member node.
* Input: Struct named "Member" with "member" variables.
* Output: the address of "newNode".
*/
MemberNode* createMemberNode(Member member) {
    MemberNode* newNode = (MemberNode*)malloc(sizeof(MemberNode));
    newNode->data = member;
    newNode->next = NULL;
    return newNode;
}

/*
* Function: addMember
* Description: Adding a new data member into csv file.
* Input:
   - filename: csv file's name needs to add data.
   - member: Struct named "Member" with "member" variables.
* Output: None
*/
void addMember(const char* filename, Member member){
    FILE *fileMain = fopen(filename, "a");
    if (fileMain == NULL) {
        printf("Can not open this file\n");
        return;
    }
    else{
    fprintf(fileMain, "%s, %s, %s, %s\n", member.uId, member.roomNumber, member.name, member.licensePlate);
    fclose(fileMain);   
    } 
}

/*
* Function: compare
* Description: Compare two string.
* Input:
   - value1: first string.
   - value2: second string.
* Output: 
   - Return 0 if the two strings are the same.
   - Return -1 or 1 if they are different.
*/
static int compare (const char *value1, const char *value2)
{
    while (*value1 && *value2 && *value1 == *value2)
    {
        ++value1;
        ++value2;
    }
    return (int)(*value1) - (int)(*value2);
}

/*
* Function: deleteMember
* Description: Deleting any data members in csv file.
* Input:
   - filename: csv file's name needs to delete data.
   - uid: string of uid want to delete.
* Output: None
*/
void deleteMember(const char* filename, const char* uid)
{
    bool checkDelete;
    FILE *fileMain = fopen(filename, "r");
    FILE *tempFile = fopen("temp.csv", "w");
    if (fileMain == NULL) {
        printf("Can not open this file\n");
        return;
    }
    Member checkMember;
    char ptr[100];    
    while(fgets(ptr, sizeof(ptr), fileMain) != NULL)
    {
        sscanf(ptr, "%[^,], %[^,], %[^,], %[^,]", checkMember.uId, checkMember.roomNumber, checkMember.name, checkMember.licensePlate);
        if (compare(checkMember.uId, uid) == 0)
        {
            checkDelete = true;
        }
        else{
            fprintf(tempFile, "%s", ptr);
        }
    }
    fclose(fileMain);
    fclose(tempFile);
    remove(filename);
    rename("temp.csv",filename);
    (checkDelete) ? printf("----- Delete successfully ! -----\n") : printf("----- uId does not exsist ! -----\n");
}

/*
* Function: editMember
* Description: Editing any data members in csv file.
* Input:
   - filename: csv file's name needs to edit data.
   - updatedMember: Struct named "Member" with "updatedMember" variables.
   - uid: string of uid want to edit.
* Output: None
*/
void editMember(const char* filename, Member updatedMember, const char* uid)
{
    bool checkEdit;
    FILE *fileMain = fopen(filename, "r");
    FILE *tempFile = fopen("temp.csv", "w");
    if (fileMain == NULL || tempFile == NULL) {
        printf("Can not open this file\n");
        return;
    }
    Member checkMember;
    char ptr[100];    
    while(fgets(ptr, sizeof(ptr), fileMain) != NULL)
    {
        sscanf(ptr, "%[^,], %[^,], %[^,], %[^,]", checkMember.uId, checkMember.roomNumber, checkMember.name, checkMember.licensePlate);
        if (compare(checkMember.uId, uid) == 0)
        {
            fprintf(tempFile, "%s, %s, %s, %s\n", updatedMember.uId, updatedMember.roomNumber, updatedMember.name, updatedMember.licensePlate);
            checkEdit = true;
        }
        else{
            fprintf(tempFile, "%s", ptr);
        }
    }
    fclose(fileMain);
    fclose(tempFile);
    remove(filename);
    rename("temp.csv",filename);
    (checkEdit) ? printf("----- Edit successfully ! -----\n") : printf("----- uId does not exsist ! -----\n");
}

/*
* Function: searchByUID
* Description: Comparing inputed uId member with current uId member.
* Input:
   - member: Struct named "Member" with "updatedMember" variables.
   - licensePlate: License Plate of member want to search.
* Output: 
   - Returning 0 if the inputed uId member with current uId member are the same. 
   - Returnning -1 or 1 if they are different.
*/
int searchByUID(const Member* member, const char* uid)
{
    return compare(member->uId,uid);    
}

/*
* Function: searchByLicensePlate
* Description: Comparing inputed License Plate member with current License Plate.
* Input:
   - member: Struct named "Member" with "updatedMember" variables.
   - licensePlate: License Plate of member want to search.
* Output: 
   - Returning 0 if the inputed member License Plate and current License Plate are the same. 
   - Returnning -1 or 1 if they are different.
*/
int searchByLicensePlate(const Member* member, const char* licensePlate)
{
    return compare(member->licensePlate, licensePlate);
}

/*
* Function: searchMember
* Description: Search any data members in csv file.
* Input:
   - filename: csv file's name needs to search data.   - 
   - searchValue: string of uid or License Plate want to find.
   - *function: a pointer to function to manage other functions to compare the input value and the current value.
* Output: return the value of "member" variables.
*/
Member searchMember(const char* filename, const char* searchValue, int (*function)(const Member*, const char*))
{
    FILE *fileMain = fopen(filename, "r");
    if (fileMain == NULL) {
        printf("Can not open this file\n");
        //return;
    }
    Member checkMember, member;
    char ptr[100];    
    while(fgets(ptr, sizeof(ptr), fileMain) != NULL)
    {
        sscanf(ptr, "%[^,], %[^,], %[^,], %[^,]", checkMember.uId, checkMember.roomNumber, checkMember.name, checkMember.licensePlate);
        if (function(&checkMember,searchValue) == 0)
        {
            member = checkMember;            
        }        
    }
    fclose(fileMain);
    return member;
}