#include <stdio.h>
#include <stdint.h>

uint64_t a;

void tong(int a, int b){
    printf ("Ket qua la :%d",a+b);
}

void hieu(int a, int b){
    printf ("Ket qua la :%d\n",a-b);
}

void tich(int a, int b){
    printf ("Ket qua la :%d",a*b);
}

void thuong(int a, int b){
    printf ("Ket qua la :%d",a/b);
}

int baso(int a, int b, double c){
    return a+b+c;
}

void tinhtoan (void(*prt)(int,int),int a, int b){
    prt(a,b);
}
/* 
- pointer dùng để lưu trữ địa chỉ của 1 biến khác.
- function pointer dùng để lưu trữ địa chỉ của một hàm có cùng kiểu trả về hoặc input para với nó, có thể gọi hàm mà nó trỏ tới.
- void pointer dùng 1 dạng con trỏ có thể trỏ đến bất kì biến nào mà không quan tâm kiểu dữ liệu và có thể in ra địa chỉ nhưng muốn lấy giá trị
thì phải ép kiểu cho pointer đó.
- Con trỏ NULL là con trỏ lưu địa chỉ 0x00000000. Tức địa chỉ bộ nhớ 0, có ý nghĩa đặc biệt, cho biết con trỏ không trỏ vào đâu cả.
Khi khai báo con trỏ nhưng chưa sử dụng thì phải gán NULL để tránh những lỗi không lường trước.
- Pointer to pointer là một loại con trỏ dùng để lưu trữ địa chỉ của biến con trỏ.
- Pointer Constant là 1 con trỏ bình thường nhưng không thể thay đổi giá trị của biến nó trỏ tới bằng con trỏ mà phải thay đổi trực tiếp thông
qua biến đó.
- Constant Pointer là con trỏ chỉ trỏ được 1 địa chỉ duy nhất tr
Size of Pointer
Kích thước của mọi con trỏ là như nhau. Kích thước này phụ thuộc vào môi trường hệ thống máy tính:
*/


int main(int argc, char const *argv[])
{
   void(*ketqua)(int,int)=&tong;
   ketqua(1,5);

   void(*dapan[])(int,int)={&hieu, &tich};
   dapan[1](4,5);

    tinhtoan(&hieu,1,2);
    
    int *pr = NULL;
    printf ("DC :%d\n", pr);

    int d = 10;
    int *prt=&d;
    int **prt2=&prt;
    printf ("DC1 :%d  %d\n", prt2,&prt);// bang nhau        
    printf ("DC2 :%d  %d\n", *prt2,prt);// bang nhau 
    printf ("DC3 :%d  %d\n", **prt2,*prt);//  bang nhau

    int e = 20;
    void *pt;  pt=&e;
    printf ("DC1 :%d %d\n", pt,&e);
    printf ("DC :%d %d\n", *(int*)pt,e);
}
