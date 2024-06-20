#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// cáu trúc dữ liệu trong lập trình dùng để tổ chức và lưu trữ dữ liệu
// gồm các node mỗi node gồm giá trị của node và con trỏ lưu địa chỉ của 1 node tiếp theo
typedef struct node
{
    int value;
    struct node* next;
}node;

node *createNode(int value)
{
    node* ptr = (node*)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}

void printList(node** array)
{
    node* temp = *array;
    while(temp != NULL ){
        printf("%d    ", temp->value);
        temp = temp->next;
    }
}

void push_back(node** array, int value)
{
    node* temp;
    temp = createNode(value); // khoi tao node
                              // temp = 0xa1

    
    if (*array == NULL)   // if array doesn't have any node yet
    {

        *array = temp;
    }
    else                // if array has some node
    {
        node* p = *array;          // use p instead of array because we are using pointer, use array will change the structure of linkedlist
        while (p->next != NULL) // which mean the current node is not the last node
        {
            p = p->next;    // check next node until it a last node

        }

        p->next = temp;     // change it next member point to address of new node have just create
    }
}

void push_front(node **array, int value) // them 1 node vao phia truoc
{
    node *temp;
    temp = createNode(value);
    if (*array == NULL){
        *array = temp;
    }
    else{
        temp->next = *array;
        *array = temp;
    }
}

void pop_back(node** array) // xoa node cuoi cung 
{
    node* p, * temp;
    p = *array;
    int i = 0; // to 

    while (p->next->next != NULL)     // free the last node in the list
    {
        p = p->next;
        i++;
    }
    temp = p->next;
    p->next = NULL;
    free(temp);
}

void pop_front(node **array) // xoa node dau tien
{
    if (*array == NULL){
        printf("Error: List emtry\n");
        return;
    }
    else{
        node *temp = *array;
        *array = temp->next;
        free(temp);
    }
}

int front(node **array) // lay gia tri cua node dau tien
{
    if (*array == NULL){
        printf("Error: List emtry\n");
        //return;
    }

    node *temp = *array;
    return temp->value;
}

int back(node **array) // lay gia tri cua node cuoi cung 
{
    node *p = *array;
    node *temp;
    if (*array == NULL){
        printf("Error: List emtry\n");
        //return;
    }    
    else {
    while (p->next->next != NULL){
        p = p->next;
    }              
    }
    temp = p->next;  
    return temp->value;
}

void insert(node **array, int value, int pos) // them 1 node vao mot vi tri bat ky
{
    node *temp = createNode(value);
    node *p = *array;
    int count = 0;
    if (*array == NULL){
        printf("Error: List emtry\n");        
    }
    else{
        while (p->next != NULL){
            p = p->next;
            count++;
            if (count == pos - 1){
                temp->next = p->next;
                p->next = temp;              
            }
        }
        //printf ("The position is not accurate !!");
    }
}

void delete(node **array, int pos) // xoa 1 node tai mot vi tri bat ky
{
    node *temp, *p = *array;
    int count = 0;   
    if (*array == NULL){
        printf("Error: List emtry\n");        
    }
    else{
        while (p->next != NULL){
            p = p->next;
            count++;
            if (count == pos - 1){
                temp = p->next;
                p->next = p->next->next;   
                free(temp);           
            }            
        }
    }
}

unsigned int size(node **array) // lay kich thuoc cua list
{
    node *p = *array;
    int count = 1; 
    if (*array == NULL){
        printf("Error: List emtry\n");        
    }
    else{
        while (p->next != NULL){
            p = p->next;
            count++;                 
        }
    }
    return count;    
}

int get(node* array, int pos)
{
    int i = 0; 
    while (array->next != NULL && pos != i)
    {
        array = array->next;
        i++;
    }
    if (pos != i)
    {
        printf("Error: List has less element\n");
        return 0;
    }
    int value = array->value;
    return value;
}

bool empty(node **array) // kiem tra list co rong hay khong
{
    if (*array == NULL){
        return true;        
    }
    else{
        return false;
    }
}

int main()
{
    node* arr = NULL;
    push_back(&arr, 2);
    push_back(&arr, 7);
    push_back(&arr, 4);
    push_back(&arr, 5);
    push_back(&arr, 3);
    push_back(&arr, 17);

    //push_front(&arr, 3);
    //pop_front(&arr);

    insert(&arr, 12, 4);
    //delete(&arr,5);
    //empty(&arr); 
    printList(&arr);
    printf("\nValue test: %d\n", get(arr, 0));
    printf("Value test: %d\n", get(arr, 1));
    printf("Value test: %d\n", get(arr, 2));
    printf("Value test: %d\n", get(arr, 3));
    printf("Value test: %d\n", get(arr, 4));
    printf("Value test: %d\n", get(arr, 5));
    printf("Value test: %d\n", get(arr, 6));   
    //printf("Value test: %d\n", get(arr, 7));    

    printf("Value test first value: %d\n", front(&arr));     
    printf("Value test final value: %d\n", back(&arr));    

    printf("Size of list: %d\n", size(&arr));
    printf("Status of list: %s", (empty(&arr)) ? "List is emtry" : "List is used");
	return 0;
}
