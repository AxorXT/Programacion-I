#ifndef POLIZA_DE_SEGUROS_POLIZA_H
#define POLIZA_DE_SEGUROS_POLIZA_H

#include <iostream>
#include <string>
#include <random>
#include <algorithm>

//Creamos clase Poliza
class Poliza {
public:

    //Constructor de la clase Poliza, la cual contiene los datos principales o datos madre del programa
    Poliza (std::string nombre, std::string curp, std::string nacimiento, int year, int edad, int prestamo, int deducible){
        this -> nombre = nombre;
        this -> curp = curp;
        this -> nacimiento = nacimiento;
        this -> year = year;
        this -> edad = edad;
        this -> prestamo = prestamo;
        this -> deducible = deducible;
    }

    //Funcion para generar un numero de Folio Aleatorio
    int Folio(const Poliza& poliza) {   //Esta funcion se usara para crear los Folios de forma aleatoria
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> distribution(1000000000, 9999999999); //Limitamos el resultado a 10 digitos

        int random_number = distribution(generator);

        return random_number; //Retornamos el resultado para usarlo a nuestro gusto.
    }

    //Apartir de aqui se crean Getters para obtener los atributos de la clase, y asi pode urilizarlos mas adelante
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

    //Funcion para pedir los datos Madre o los datos Principales
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
//Agregamos a un private para que los datos no puedan ser modificados
private:
    std::string nombre;
    std::string curp;
    std::string nacimiento;
    int edad, year, prestamo, deducible;
};


//Creamos la clase Casa que hereda de Poliza
class Casa : public Poliza{
public:

    //Constructor de la clase casa, en el cual comienzo poniendo sus atributos y despues llamamos al constructor de la clase base = Poliza
    Casa (std::string nombre, std::string curp, std::string nacimiento, int year, int edad, int prestamo, int deducible, float medida, int antiguedad, int postal, int Nexterior, std::string pais, std::string estado, std::string colonia, std::string calle)
            : Poliza (nombre, curp, nacimiento, year, edad, prestamo, deducible){
        //Inicializacion de atributos de Casa
        this -> medida = medida;
        this -> antiguedad = antiguedad;
        this -> postal = postal;
        this -> Nexterior = Nexterior;
        this -> pais = pais;
        this -> estado = estado;
        this -> colonia = colonia;
        this -> calle = calle;
    }

    //Funcion para solicitar Datos de Poliza de Casa
    void SetDatos() {
        //Aqui llamamos a la funcion SetDatos de la clase base o la base madre Poliza
        Poliza::SetDatos();

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

            // Aqui imprimimos_todo lo que se escribio en los datos principales de la clase Poliza, agregando los de la poliza de casa
            std::cout << "El cliente " << getNombre() << " con " << getEdad() << " anios de edad, de CURP " << getCurp()
                      << " con un prestamo de $" << getPrestamo() << " y su deducible de $" << getDeducible()
                      << " se ha registrado para una poliza de Casa con los siguientes datos:" << std::endl;
            std::cout << "Medida de casa en m2: " << medida << std::endl;
            std::cout << "Anio en que se construyo la casa: " << antiguedad << std::endl;
            std::cout << "Direccion de la Casa: " << pais << ", " << estado << ", " << postal << ", " << colonia
                      << ", "<< calle << ", " << Nexterior << std::endl;
            std::cout << "Folio de Poliza: " << Folio(*this) << std::endl;
        }
    }
//Agregamos a un private para que los datos no puedan ser modificados
private:
    float medida;
    int antiguedad, postal, Nexterior;
    std::string pais, estado, colonia, calle;

};


//Creamos la clase Carro que hereda de Poliza
class Carro : public Poliza{
public:

    //Constructor de la clase carro, en el cual comienzo poniendo sus atributos y despues llamamos al constructor de la clase base = Poliza
    Carro (std::string nombre, std::string curp, std::string nacimiento, int year, int edad, int prestamo, int deducible, std::string marca, std::string modelo, int km, int anio, int serial)
            : Poliza (nombre, curp, nacimiento, year, edad, prestamo, deducible){
        //Inicializacion de atributos de Carro
        this -> marca = marca;
        this -> modelo = modelo;
        this -> km = km;
        this -> anio = anio;
        this -> serial = serial;
    }

    //Funcion para solicitar Datos de Poliza de Carro
    void SetDatos(){
        //Aqui llamamos a la funcion SetDatos de la clase base o la base madre Poliza
        Poliza::SetDatos();

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

        //Aqui imprimimos_todo lo que se escribio en los datos principales de la clase Poliza, agregando los de la poliza de carro
        std::cout << "El cliente " << getNombre() << " con " << getEdad() << " anios de edad, de CURP " << getCurp()
                  << " con un prestamo de $" << getPrestamo() << " y su deducible de $" << getDeducible()
                  << " se ha registrado para una poliza de Casa con los siguientes datos:" << std::endl;
        std::cout << "Marca: " << marca << std::endl;
        std::cout << "Modelo: " << modelo << std::endl;
        std::cout << "Kilometraje: " << km << std::endl;
        std::cout << "Anio: " << anio << std::endl;
        std::cout << "Numero de Serie: " << serial << std::endl;
        std::cout << "Folio de Poliza: " << Folio(*this) << std::endl;
    }
//Agregamos a un private para que los datos no puedan ser modificados
private:
    int km, anio, serial;
    std::string marca, modelo;
};

//Creamos la clase Vida que hereda de Poliza
class Vida : public Poliza {
public:

    //Constructor de la clase Vida, en el cual comienzo poniendo sus atributos y despues llamamos al constructor de la clase base = Poliza
    Vida (std::string nombre, std::string curp, std::string nacimiento, int year, int edad, int prestamo, int deducible, std::string sangre, std::string* enfermedades, int num)
            : Poliza (nombre, curp, nacimiento, year, edad, prestamo, deducible){
        //Inicializacion de atributos de Vida
        this -> sangre = sangre;
        this -> enfermedades = enfermedades;
        this -> num = num;

    }

    //Aqui hacemos un constructor adicional para el caso donde no se proporcionan enfermedades
    Vida(std::string nombre, std::string curp, std::string nacimiento, int year, int edad, int prestamo, int deducible)
            : Poliza(nombre, curp, nacimiento, year, edad, prestamo, deducible), enfermedades(nullptr), num(0) {}

    // Destructor para liberar la memoria de enfermedades
    ~Vida(){
        delete[] enfermedades;
        enfermedades = new std::string [num];
    }

    //Funcion para solicitar la cantidad y nombre de enfermedades
    void setEnfermedades(){
        while (true){
            std::cout << "Numero de enfermedades: ";
            std::string numStr;
            std::getline(std::cin, numStr);

            //Verifica si la entrada es un numero valido y no esta vacia
            if (std::all_of (numStr.begin(), numStr.end(), ::isdigit) && !numStr.empty()){
                // Convierte la cadena a un entero y asigna el valor a "num"
                num = std::stoi(numStr);
                break;
            } else {
                // Muestra un mensaje de error si la entrada no es válida
                std::cerr << "Ingresa un numero de enfermedades valido" << std::endl;
            }
        }

        // Libera la memoria asignada previamente al arreglo "enfermedades"
        delete[] enfermedades;
        // Asigna dinámicamente un nuevo arreglo de cadenas de longitud "num"
        enfermedades = new std::string[num];
        // Muestra un mensaje solicitando al usuario ingresar los nombres de las enfermedades una por una
        std::cout << "Nombre de enfermedades una por una: " << std::endl;

        // Utiliza un bucle para solicitar y almacenar cada nombre de enfermedad en el arreglo
        for(int i = 0; i < num; ++i){
            std::cout << "Enfermedad " << i + 1 << ": ";
            std::getline(std::cin, enfermedades[i]);
        }
    }

    //Funcion para mostrar las enfermedades del paciente
    void DatosEnfermedad() const {
        std::cout << "Enfermedades del paciente" << std::endl;
        for (int i = 0; i < num; ++i) {
            std::cout << "Enfermedad " << i + 1 << ": " << enfermedades[i] << std::endl;
        }
    }

    //Funcion para solicitar Datos de Poliza de Vida
    void SetDatos(){
        //Aqui llamamos a la funcion SetDatos de la clase base o la base madre Poliza
        Poliza::SetDatos();

        std::cout << "Accediste a la poliza de Vida, ingresa los datos necesarios" << std::endl;
        std::cout << "Tipo de Sangre: " << std::endl;
        std::cin >> sangre;
        setEnfermedades(); //Agregamos la funcion para que pida los datos de enfermedades

        //Aqui imprimimos_todo lo que se escribio en los datos principales de la clase Poliza, agregando los de la poliza de Vida
        std::cout << "El cliente " << getNombre() << " con " << getEdad() << " anios de edad, de CURP " << getCurp()
                  << " con un prestamo de $" << getPrestamo() << " y su deducible de $" << getDeducible()
                  << " se ha registrado para una poliza de Casa con los siguientes datos:" << std::endl;
        std::cout << "Tipo de Sangre del cliente: " << sangre << std::endl;
        DatosEnfermedad(); //Agregamos la funcion para que lo imprima
        std::cout << "Folio de Poliza: " << Folio(*this) << std::endl;
    }

//Agregamos a un private para que los datos no puedan ser modificados
private:
    std::string sangre;
    std::string* enfermedades;
    int num;
};

//Funcion principal que se usara como un menu para que el usuario interactue y cree las polizas necesarias
void Principal(){

    int elegir;

    std::cout << "Elije la Poliza que deseas usar:" << std::endl;
    std::cout << "1.Poliza de Casa" << std::endl;
    std::cout << "2.Poliza de Carro" << std::endl;
    std::cout << "3.Poliza de Vida" << std::endl;
    std::cout << "4.Salir" << std::endl;
    std::cin >> elegir;

    //Usamos un switch para tener diferentes opciones de polizas
    switch(elegir) {

        // Crear una instancia de Casa y llamar a SetDatos para solicitar la información
        case 1: {
            Casa casa("nombre", "curp", "nacimiento", 2023, 30, 100000, 5000, 120.5, 1990, 12345, 567, "Mexico", "Estado", "Colonia", "Calle");
            casa.SetDatos();
            break;
        }

            // Crear una instancia de Carro y llamar a SetDatos para solicitar la información
        case 2: {
            Carro carro("nombre", "curp", "nacimiento", 2023, 30, 100000, 5000, "Toyota", "Corolla", 50000, 2020, 987654);
            carro.SetDatos();
            break;
        }

            // Crear una instancia de Vida y llamar a SetDatos para solicitar la información
        case 3: {
            Vida vida("nombre", "curp", "nacimiento", 2023, 30, 100000, 5000, "O+", nullptr, 0);
            vida.SetDatos();
            break;
        }

            // Creamos una instancia de salida, para que el usuario pueda salir del programa
        case 4: {
            exit(0);
        }

            // En caso de no seleccionar una de las 4 opciones anteriores aparecera esto
        default:
            std::cout << "Opcion Invalida";
    }
}




#endif //POLIZA_DE_SEGUROS_POLIZA_H