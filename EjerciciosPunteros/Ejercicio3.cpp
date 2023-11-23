#include <iostream>

void ModificarValores(int * ptr){
    *ptr = 3;
}

int main(){
    int e = 7;

    ModificarValores(&e);

    std::cout << e;
}
