#include "stdio.h"

//#define NDEBUG // có thể tắt chức năng của assert

#include "assert.h"

#define LOG(condition, cmd) assert(condition && #cmd)
/*
thư viện assert giúp phát hiện những lỗi đã xác định trước không thể phát hiện trong quá trình compile và dừng chương trình tại vị trí đó
*/


int main(int argc, char const *argv[])
{
    int a = 5;
    printf("a = %d\r\n", a);
    a = 7;
    assert(a < 6 && "Error");
    printf("a = %d\r\n", a);

    
    return 0;
}