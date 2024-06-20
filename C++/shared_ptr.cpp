#include <iostream>
#include <memory>

/*
shared_ptr là 1 dạng smart ptr nhưng khác với unique ( chỉ trỏ đến 1 đối tượng hoặc arr) thỉ nhiều con shared có thể trỏ đến 1 đối tượng và 
có 1 bộ đếm x.use_count() để đếm có bao nhiêu con shared đang trỏ đến và x.reset() để dừng việc trỏ đến.
*/
using namespace std;

class HinhChuNhat {
private:
    int ChieuDai;
    int ChieuRong;
public:
    HinhChuNhat(int dai, int rong){
        ChieuDai = dai;
        ChieuRong = rong;
        cout << "Constructor called. "  << endl;
    }
    void tinhDienTich() {
        cout << "Dien tich: " << ChieuDai * ChieuRong << endl;
    }
    ~HinhChuNhat() {
        cout << "Destructor called " << endl;
    }
};
int main() {
    shared_ptr <HinhChuNhat> ptr1 (new HinhChuNhat(40,10));
    (*ptr1).tinhDienTich();
    shared_ptr <HinhChuNhat> ptr2 (ptr1);
    shared_ptr <HinhChuNhat> ptr3;
    ptr3 = ptr2;
    (*ptr2).tinhDienTich();
    (*ptr1).tinhDienTich();
    (*ptr3).tinhDienTich();
    ptr3.reset();
    cout << "Count: " << ptr1.use_count() << endl;
    cout << "Count: " << ptr2.use_count() << endl;
    cout << "Count: " << ptr3.use_count() << endl;
    return 0;
}