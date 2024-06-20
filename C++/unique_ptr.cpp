#include <iostream>
#include <memory>

using namespace std;
// unique là 1 dạng smart prt nhưng mỗi unique_ptr chỉ trỏ đến 1 đối tượng hoặc một mảng không trỏ đến nhưng đối tượng đã được quán lý
 
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
    unique_ptr <HinhChuNhat> ptr1(new HinhChuNhat(10,5));
    (*ptr1).tinhDienTich();
    //unique_ptr <HinhChuNhat> ptr2(ptr1); // Khong cho phep
    unique_ptr <HinhChuNhat> ptr2 = move(ptr1); // gan object HinhChuNhat(10,5) cho ptr2, sau do remove ptr1
    (*ptr2).tinhDienTich();
    (*ptr1).tinhDienTich();

    return 0;
}