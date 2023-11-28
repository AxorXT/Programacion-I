#include <iostream>
#include <string>

using namespace std;

//decimal a binario
string dec2bin(int n) {
    if (n == 0) {
        return "";
    }
    return dec2bin(n / 2) + to_string(n % 2);
}

//binario a decimal
int bin2dec(string n) {
    int decimal = 0;
    int potencia = 1;
    for (int i = n.length() - 1; i >= 0; i--) {
        if (n[i] == '1') {
            decimal += potencia;
        }
        potencia *= 2;
    }
    return decimal;
}


//decimal a hexadecimal
string dec2hex(int n) {
    string hex = "";
    int r;
    while (n != 0) {
        r = n % 16;
        if (r < 10) {
            hex = to_string(r) + hex;
        } else {
            hex = char(r + 55) + hex;
        }
        n /= 16;
    }
    return hex;
}

//hexadecimal a Decimal

int hex2dec(string hexadec) {
    int decimal = 0;
    int base = 16; // Hexadecimal es base 16
    
    // Recorre el número hexadecimal de izquierda a derecha
    for (int i = 0; i < hexadec.length(); i++) {
        char c = hexadec[i];
        int valor = 0;
        
        if (c >= '0' && c <= '9') {
            valor = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            valor = 10 + (c - 'A');
        } else if (c >= 'a' && c <= 'f') {
            valor = 10 + (c - 'a');
        } else {
            cout << "Caracter no válido en el número hexadecimal." << endl;
            return -1; // Error
        }
        
        decimal = decimal * base + valor;
    }
    
    return decimal;
}

int main()
{
    int Elegir;
    
    cout << "1. Decimal a Binario" << endl;
    cout << "2. Binario a Decimal" << endl;
    cout << "3. Decimal a Hexadecimal" << endl;
    cout << "4. Hexadecimal a Decimal" << endl;
    cout << "Elige una operacion:";
    cin >> Elegir;

    switch(Elegir) {
        
        //decimal a binario
        case 1:{
        int t;
            cout << "Ingresa un numero decimal: ";
            cin >> t;
            cout << "El numero binario es: ";
            cout << dec2bin(t) << endl;
            break;
        }
        
        
        //binario a decimal
        case 2:{
        string w;
        cout << "Ingresa el numero binario: ";
        cin >> w;
        int decimal = bin2dec(w);
        if (decimal != -1) {
            cout << "El numero decimal es: " << decimal << endl;
        } else {
            cout << "Conversión binario a decimal fallida debido a caracteres no válidos." << endl;
        }
        break;
    }
        
        //decimal a hexadecimal
        case 3:{
        int r;
            cout << "Ingresa un numero decimal: ";
            cin >> r;
            cout << "El numero hexadecimal es: ";
            cout << dec2hex(r) << endl;
            break;
        }
        
        
        //hexadecimal a decimal
        case 4:{
        string hexadec;
        int decimal;
        cout << "Ingrese un número hexadecimal: ";
        cin >> hexadec;
        
        decimal = hex2dec (hexadec);
        
        if (decimal != -1) {
            cout << "El número decimal es: " << decimal << endl;
        }
        break;
        }
        
        default:
            cout << "Opcion invalida" << endl;
    }

    return 0;
}
