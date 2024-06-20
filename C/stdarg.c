#include <stdio.h>
#include <stdarg.h>

//xử lý các bài toán không biêt số lượng input parameter
typedef struct{
    int x; 
    double y;
}Data;

int sum (int count, ...){
    va_list args;

    va_start(args, count);

    int result = 0;
    for(int i = 0; i < count; i++){
        result += va_arg(args, int);
    }

    va_end(args);

    return result;
}

void display(int count, ...){
    va_list args;

    va_start(args, count);

    int result = 0;

     for(int i = 0; i < count; i++){
        Data tmp = va_arg(args, Data);
        printf("Data.x at %d is: %d\n", i, tmp.x);
        printf("Data.y at %d is: %.2f\n", i, tmp.y);
    }

    va_end(args);
}

int main(){

    printf ("Sum: %d\n", sum(5, 1, 2, 3, 4, 5));
    display(3, (Data){2, 0.5}, (Data){3, 1.5}, (Data){2, 0.5});
    return 0;
}