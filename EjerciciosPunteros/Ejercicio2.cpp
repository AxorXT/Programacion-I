#include <iostream>

int main(){
    int Arreglo[] = {12,34,56,67,45};
    int * ptr = Arreglo;
    for(int i = 0; i < 5; i++){
        std::cout << * ptr;
        ptr++;
    }
}