#include <iostream>
#include <string>

int main(){
struct login{
    std::string usu, contra, contraseña;
    int a;
}
    login.usu = "Juan";
    login.contra = 'J';
    login.contraseña = "J";
    login.a=8;
    std::cout << "El usuario es: " << login.usu;
    std::cout << "La contraseña es: "<< login.contra;
    std::cout << "La contraseña es: "<< login.contraseña;

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
