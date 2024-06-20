#include <iostream>

using namespace std;

template <typename ... Args>

void print(Args...args){
    (cout << ... <<args) << endl ;
}

int main(int argc, char const *argv[])
{
    print(1, 1.5, 's', "Huy");
    return 0;
}

