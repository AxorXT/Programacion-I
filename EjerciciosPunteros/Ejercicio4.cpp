#include <iostream>

int main(){
    const char* message = "hello world ";

    std::cout << *message;

    for(int i = 0; i < 11; i++){
        std::cout << *message;
        message++;
    }

    return 0;
}