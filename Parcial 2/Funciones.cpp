#include <iostream>

int pedir()
{
    int cali;
    std::cout << "Calificacion: ";
    std::cin >> cali;
    return cali;
}

int calcu(){
    
    int num1, num2, num3, num4, num5, prome;
    
    prome = (num1 + num2 + num3 + num4 + num5)/5;
    return prome;
}

int main(){

int cali;

int num1 = pedir();
    int num2 = pedir();
        int num3 = pedir();
            int num4 = pedir();
                int num5 = pedir();
                    int prome = calcu();
                

std::cout<< "El promedio es: " << prome;

return 0;

}
