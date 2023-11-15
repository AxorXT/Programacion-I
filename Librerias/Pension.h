#ifndef PENSION_H
#define PENSION_H

#include <iostream>
#include <string>

using namespace std;

struct Persona {
    string nombre, ocupacion;
    int edad, jubilacion, ahorrado;
    float sueldo;
};

struct Persona PedirDatos (){
    string nombre, ocupacion;
    int edad, jubilacion, ahorrado; 
    float sueldo;
    
    struct Persona persona;
    cout << "Ingresa tu nombre: ";
    cin >> nombre;
    persona.nombre = nombre;
    
    cout << "Ingresa tu edad: ";
    cin >> edad;
    persona.edad = edad;
    
    cout <<"Ingresa tu ocupacion: ";
    cin >> ocupacion;
    persona.ocupacion = ocupacion;
    
    cout << "Ingresa tu sueldo: ";
    cin >> sueldo;
    persona.sueldo = sueldo;

    persona.jubilacion = 65 - edad;
    
    persona.ahorrado = (persona.jubilacion * sueldo) / 10;
    
    return persona;
}

#endif
