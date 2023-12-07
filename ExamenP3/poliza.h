#ifndef POLIZA_DE_SEGUROS_POLIZA_H
#define POLIZA_DE_SEGUROS_POLIZA_H

#include <iostream>
#include <string>
#include <random>
#include <algorithm>

//Creamos clase Poliza
class Poliza {
public:

    Poliza (std::string nombre, std::string curp, std::string nacimiento, int year, int edad, int prestamo, int deducible){
        this -> nombre = nombre;
        this -> curp = curp;
        this -> nacimiento = nacimiento;
        this -> year = year;
        this -> edad = edad;
        this -> prestamo = prestamo;
        this -> deducible = deducible;
    }

    int Folio(const Poliza& poliza) {   //Esta funcion se usara para crear los Folios de forma aleatoria
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> distribution(1000000000, 9999999999); //Limitamos el resultado a 10 digitos

        int random_number = distribution(generator);

        return random_number; //Retornamos el resultado para usarlo a nuestro gusto.
    }

    std::string getNombre(){
        return this -> nombre;
    }

    std::string getCurp(){
        return this -> curp;
    }

    std::string getNacimiento(){
        return this -> nacimiento;
    }

    int getEdad(){
        return this -> edad;
    }

    int getYear(){
        return this -> year;
    }

    int getPrestamo(){
        return this -> prestamo;
    }

    int getDeducible(){
        return this -> deducible;
    }

    virtual //Funcion para pedir los datos Madre o los datos Principales
    void SetDatos(){
        std::cout << "Ingresa Nombre: " << std::endl;
        std::cin >> nombre;
        std::cout << "Ingresa CURP: " << std::endl;
        std::cin >> curp;
        std::cout << "Ingresa Anio de Nacimiento: " << std::endl;
        std::cin >> year;
        std::cout << "Edad del Cliente: "; //Usamos el año propuesto en la fecha de nacimeinto para calcular la edad
        this -> edad = 2023 - year;
        std::cout << edad << std::endl;
        std::cout << "Ingresa Monto Maximo del Prestamo: " << std::endl;
        std::cin >> prestamo;
        std::cout << "Ingresa Deducible: " << std::endl;
        std::cin >> deducible;
    }

private:
    std::string nombre;
    std::string curp;
    std::string nacimiento;
    int edad, year, prestamo, deducible;
};


//Poliza de Casa
class Casa : public Poliza{
public:

    Casa (std::string nombre, std::string curp, std::string nacimiento, int year, int edad, int prestamo, int deducible, float medida, int antiguedad, int postal, int Nexterior, std::string pais, std::string estado, std::string colonia, std::string calle)
    : Poliza (nombre, curp, nacimiento, year, edad, prestamo, deducible){
        this -> medida = medida;
        this -> antiguedad = antiguedad;
        this -> postal = postal;
        this -> Nexterior = Nexterior;
        this -> pais = pais;
        this -> estado = estado;
        this -> colonia = colonia;
        this -> calle = calle;
    }

    //Funcion de Datos de Poliza de Casa
    void SetDatos() {

        std::cout << "Accediste a la poliza de Casa, ingresa los datos necesarios" << std::endl;
        std::cout << "Ingresa la medida de la casa en m2: " << std::endl;
        std::cin >> medida;
        std::cout << "Ingresa el anio en que se construyo: " << std::endl;
        std::cin >> antiguedad;

        //Con este IF nos aseguramos de que el año de construccion que escriban es antes o sea menor al año actual
        if (antiguedad > 2023){
            std::cout << "El anio de construccion debe ser menor al año actual" << std::endl;
            exit(1);
        } else {
            std::cout << "Ingresa la Direccion de la Casa" << std::endl; //Agregamos los Datos basicos de una Direccion, como en Amazon jeje
            std::cout << "Pais: " << std::endl;
            std::cin >> pais;
            std::cout << "Estado: " << std::endl;
            std::cin >> estado;
            std::cout << "Codigo Postal: " << std::endl;
            std::cin >> postal;
            std::cout << "Colonia: " << std::endl;
            std::cin >> colonia;
            std::cout << "Calle: " << std::endl;
            std::cin >> calle;
            std::cout << "Numero Exterior: " << std::endl;
            std::cin >> Nexterior;

            //Aqui imprimimos todos los datos que se escribieron anteriormente, agregando los de la poliza señalada
            std::cout << "El cliente " << getNombre() << " con " << getEdad() << " anios de edad, de CURP " << getCurp()
                      << "con un prestamo de $" << getPrestamo() << "y su deducible de $" << getDeducible()
                      << " se ha registrado para una poliza de Casa con los siguientes datos:" << std::endl;
            std::cout << "Medida de casa en m2: " << medida << std::endl;
            std::cout << "Anio en que se construyo la casa: " << antiguedad << std::endl;
            std::cout << "Direccion de la Casa: " << pais << ", " << estado << ", " << postal << ", " << colonia
                      << ", "<< calle << ", " << Nexterior << std::endl;
            std::cout << "Folio de Poliza: " << Folio(*this) << std::endl;
        }
    }

private:
    float medida;
    int antiguedad, postal, Nexterior;
    std::string pais, estado, colonia, calle;

};


//Poliza de Carro
class Carro : public Poliza{
public:
    Carro (std::string nombre, std::string curp, std::string nacimiento, int year, int edad, int prestamo, int deducible, std::string marca, std::string modelo, int km, int anio, int serial)
    : Poliza (nombre, curp, nacimiento, year, edad, prestamo, deducible){
        this -> marca = marca;
        this -> modelo = modelo;
        this -> km = km;
        this -> anio = anio;
        this -> serial = serial;
    }

    //Funcion de Datos de Poliza de Carro
    void SetDatos(){

        std::cout << "Accediste a la poliza de Carro, ingresa los datos necesarios" << std::endl;
        std::cout << "Marca de carro:" << std::endl;
        std::cin >> marca;
        std::cout << "Modelo del carro: " << std::endl;
        std::cin >> modelo;
        std::cout << "Kilometraje del carro: " << std::endl;
        std::cin >> km;
        std::cout << "Anio del carro: " << std::endl;
        std::cin >> anio;
        std::cout << "Numero de serie del carro: " << std::endl;
        std::cin >> serial;

        //Aqui imprimimos todos los datos que se escribieron anteriormente, agregando los de la poliza señalada
        std::cout << "El cliente " << getNombre() << " con " << getEdad() << " anios de edad, de CURP " << getCurp()
                  << "con un prestamo de $" << getPrestamo() << "y su deducible de $" << getDeducible()
                  << " se ha registrado para una poliza de Casa con los siguientes datos:" << std::endl;
        std::cout << "Marca: " << marca << std::endl;
        std::cout << "Modelo: " << modelo << std::endl;
        std::cout << "Kilometraje: " << km << std::endl;
        std::cout << "Anio: " << anio << std::endl;
        std::cout << "Numero de Serie: " << serial << std::endl;
        std::cout << "Folio de Poliza: " << Folio(*this) << std::endl;
    }

private:
    int km, anio, serial;
    std::string marca, modelo;
};

class Vida : public Poliza {
public:
    Vida (std::string nombre, std::string curp, std::string nacimiento, int year, int edad, int prestamo, int deducible, std::string sangre, std::string* enfermedades, int num)
    : Poliza (nombre, curp, nacimiento, year, edad, prestamo, deducible){
        this -> sangre = sangre;
        this -> enfermedades = enfermedades;
        this -> num = num;

    }

    Vida() : enfermedades(nullptr), num(0) {}

    ~Vida(){
        delete[] enfermedades;
    }

    void setEnfermedades(){
        while (true){
            std::cout << "Numero de enfermedades: ";
            std::string numStr;
            std::getline(std::cin, numStr);

            if (std::all_of (numStr.begin(), numStr.end(), ::isdigit) && !numStr.empty()){
                num = std::stoi(numStr);
                break;
            } else {
                std::cerr << "Ingresa un numero de enfermedades valido" << std::endl;
            }
        }

        delete[] enfermedades;
        enfermedades = new std::string[num];
        std::cout << "Nombre de enfermedades una por una: " << std::endl;

        for(int i = 0; i < num; ++i){
            std::cout << "Enfermedad " << i + 1 << ": ";
            std::getline(std::cin, enfermedades[i]);
        }
    }

    void DatosEnfermedad() const {
        std::cout << "Enfermedades del paciente" << std::endl;
        for (int i = 0; i < num; ++i) {
            std::cout << "Enfermedad " << i + 1 << ": " << enfermedades[i] << std::endl;
        }
    }

    void SetDatos(){

        std::cout << "Accediste a la poliza de Vida, ingresa los datos necesarios" << std::endl;
        std::cout << "Tipo de Sangre: " << std::endl;
        std::cin >> sangre;
        setEnfermedades();

        std::cout << "El cliente " << getNombre() << " con " << getEdad() << " anios de edad, de CURP " << getCurp()
                  << "con un prestamo de $" << getPrestamo() << "y su deducible de $" << getDeducible()
                  << " se ha registrado para una poliza de Casa con los siguientes datos:" << std::endl;
        std::cout << "Tipo de Sangre del cliente: " << sangre << std::endl;
        DatosEnfermedad();
        std::cout << "Folio de Poliza: " << Folio(*this) << std::endl;
    }

private:
    std::string sangre;
    std::string* enfermedades;
    int num;
};

void Principal(){

    int elegir;

    std::cout << "Elije la Poliza que deseas usar:" << std::endl;
    std::cout << "1.Poliza de Casa" << std::endl;
    std::cout << "2.Poliza de Carro" << std::endl;
    std::cout << "3.Poliza de Vida" << std::endl;
    std::cout << "4.Salir" << std::endl;
    std::cin >> elegir;

    switch(elegir) {

        case 1: {
            Casa casa();
            casa().SetDatos();
            break;
        }

        case 2: {
            Carro carro();
            carro().SetDatos();
            break;
        }

        case 3: {
            Vida vida();
            vida().SetDatos();
            break;
        }

        case 4: {
            exit(0);
        }

        default:
            std::cout << "Opcion Invalida";
    }
}




#endif //POLIZA_DE_SEGUROS_POLIZA_H