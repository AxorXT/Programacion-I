#ifndef POLIZA_DE_SEGUROS_POLIZA_H
#define POLIZA_DE_SEGUROS_POLIZA_H

#include <iostream>
#include <string>

class Poliza {
public:
    Poliza(std::string nombre, std::string curp, int edad, int nacimiento, int prestamo, int deducible){
        this -> nombre = nombre;
        this -> curp = curp;
        this -> edad = edad;
        this -> nacimiento = nacimiento;
        this -> prestamo = prestamo;
        this -> deducible = deducible;
    }

    std::string getNombre(){
        return this -> nombre;
    }

    std::string getCurp(){
        return this -> curp;
    }

    int getEdad(){
        return this -> edad;
    }

    int getNacimiento(){
        return this -> nacimiento;
    }

    int getPrestamo(){
        return this -> prestamo;
    }

    int getDeducible(){
        return this -> deducible;
    }

    void setNombre(std::string nombre){
        std::cout << "Ingresa tu nombre: ";
        std::cin >> nombre;
        this -> nombre = nombre;
    }

    void setCurp(std::string curp){
        this -> curp = curp;
    }


private:
    std::string nombre;
    std::string curp;
    int edad;
    int nacimiento;
    int prestamo;
    int deducible;


};

#endif //POLIZA_DE_SEGUROS_POLIZA_H
