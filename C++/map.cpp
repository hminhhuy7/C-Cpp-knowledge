#include <iostream>
#include <map>

using namespace std;

typedef struct{
    string ten;
}SinhVien;

int main(){
    map<int, SinhVien> danhSach;
    danhSach[1] = {"huy"};
    danhSach[2] = {"hoang"};
    for(auto item : danhSach)
        cout<<item.first<<": "<<item.second.ten<<endl;

    return 0;
}