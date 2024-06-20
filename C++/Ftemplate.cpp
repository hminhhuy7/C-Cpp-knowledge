#include <iostream>
#include <string>

using namespace std;

template <typename valA, typename valB>

valA tong (valA a, valB b){
    return (valA)a+b;    
}

int main(int argc, char const *argv[])
{
    printf ("%f\n",tong (3.5, 2));
    printf ("%d",tong (1, 1));
    return 0;
}
