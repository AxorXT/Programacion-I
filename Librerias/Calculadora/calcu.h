#ifndef CALCU_H
#define CALCU_H

#include <iostream>
#include <vector>

struct Pediche {
    int opcionN;
};

struct Pediche ElegirOperacion() {

    int opcionN;

    std::cout << "1. Suma" << std::endl;
    std::cout << "2. Resta" << std::endl;
    std::cout << "3. Multiplicacion" << std::endl;
    std::cout << "4. Division" << std::endl;
    std::cout << "5. Potencia" << std::endl;
    std::cout << "6. Porcentaje" << std::endl;
    std::cout << "Selecciona una operacion: ";
    std::cin >> opcionN;

    switch (opcionN){
        case 1: {
            int a, b;
            std::cout << "Ingresa la primera cantidad: ";
            std::cin >> a;
            std::cout << "Ingresa la sagunda cantidad: ";
            std::cin >> b;
            std::cout << "El resultado es: " << a + b;
            break;
        }
        case 2: {
            int c,d;
            std::cout << "Ingresa la primera cantidad: ";
            std::cin >> c;
            std::cout << "Ingresa la sagunda cantidad: ";
            std::cin >> d;
            std::cout << "El resultado es: " << c-d;
            break;
        }
        case 3: {
            int e,f;
            std::cout << "Ingresa la primera cantidad: ";
            std::cin >> e;
            std::cout << "Ingresa la sagunda cantidad: ";
            std::cin >> f;
            std::cout << "El resultado es: " << e*f;
            break;
        }
        case 4: {
            int g,h;
            std::cout << "Ingresa la primera cantidad: ";
            std::cin >> g;
            std::cout << "Ingresa la sagunda cantidad: ";
            std::cin >> h;
            std::cout << "El resultado es: " << g/h;
            break;
        }
        case 5: {
            int k,j, resultado = 1;
            std::cout << "Ingresa la base: ";
            std::cin >> k;
            std::cout << "Ingresa el exponente: ";
            std::cin >> j;
            for (int i = 0; i < j; i++){
                resultado *= k;
            }
            std::cout << "El resultado es: " << resultado;
            break;
        }
        case 6: {
            int l,m;
            std::cout << "Ingresa la cantidad: ";
            std::cin >> l;
            std::cout << "Ingresa el porcentaje: ";
            std::cin >> m;
            std::cout << "El resultado es: " << (l*m) / 100;
            break;
        }


        default: {
            std::cout << "Opcion invalida" << std::endl;
        }

    }

}



#endif //CALCU_H
