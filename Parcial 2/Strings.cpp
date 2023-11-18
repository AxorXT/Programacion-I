#include <iostream>
#include <string>

int main(){
    int a = 8;
    std::string usu;
    std::string contra;
    std::string contraseña;
    std::cout << "Usuario: ";
    std::cin >> usu;
    std::cout << "Contraseña: ";
    std::cin >> contra;
    std::cout<<"Comprueba tu contraseña: ";
    std::cin>>contraseña;
    
    do{
    if(contra == contraseña){
    std::cout<< "Contraseña correcta";
    break;
    }
    else{
        std::cout<< "Contraseña incorrecta" << std::endl;
        break;
    }
    }
    while(true);

    return 0;
}
