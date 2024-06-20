#include <iostream>
#include <functional>
	
#define PI 3.14

using namespace std;
	
void processFunction(int a, int b, const function<void(int, int)>& func) {
    cout << "Processing numbers: " << a << " and " << b << endl;
    func(a, b);
}
int main() {
    int a = 10;
    const double g = 9.8;
    processFunction(7, 9, [a](int x, int y) {
        cout << "Product: " << x * y + a << endl;
    });
    processFunction(7, 9, [g](int x, int y) {
        cout << "Product: " << x + y + g << endl;
    });
    processFunction(7, 9, [](int x, int y) {
        cout << "Product: " << x - y + PI << endl;
    });
    return 0;
}