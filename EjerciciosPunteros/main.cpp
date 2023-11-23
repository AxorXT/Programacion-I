#include <iostream>

int main(){
    int a;
    int * b = &a; //*b declaramos un puntero

    a = 8;
    *b = 5;
    std::cout << a;

    return 0;
}