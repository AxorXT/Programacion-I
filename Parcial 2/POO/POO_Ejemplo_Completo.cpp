#include <iostream>
#include <string>

class Animal{
    public:

        Animal(std::string nombre, std::string comida){
            this -> nombre = nombre;
            this -> comida = comida;
        }

        std::string getNombre(){
            return this -> nombre;
        }

        std::string getComida(){
            return this -> comida;
        }

        void setNombre(std::string nombre){
            this -> nombre = nombre;
        }

        void setComida(std::string comida){
            this -> comida =comida;
        }


    private:
        std::string nombre;
        std::string comida;

    protected:
    friend class Mono;
    virtual std::string getNombreCientifico() {
        return this->nombre;
    }
};

//Herencia del simio
class Simios : public Animal{
    public:

    Simios(std::string nombre, std::string comida, std::string Tipo) : Animal(nombre, comida){
        this -> Tipo = Tipo;
    }
    std::string getTipo(){
        return this -> Tipo;
    }
    void setTipo(std::string tipo){
        this -> Tipo = Tipo;
    }
    private:
    std::string Tipo;
};

//Encapsulamiento Mono 
class Mono {
    public:
    std::string getNombreCientifico(Animal animal) {
        return animal.getNombreCientifico();
    }
};

//Polimorfismo
class Chango {
    public:
    void sonido() {
        std::cout << "Sonido de animal" << std::endl;
    }
};

class Capuchino : public Chango {
    public:
    void sonido() {
        std::cout << "Capuchino: AJU AJU" << std::endl;
    }
};

class Orangutan : public Chango {
    public:
    void sonido(){
        std::cout << "Orangutan: JIJIJA JIJIJA" << std::endl;
    }
};

//Sobrecarga de Funciones
class Operaciones {
    public:
        int suma(int a, int b) {
            std::cout << "Años de Chimpance:";
            return a + b;
        }
        int suma(int a, int b, int c) {
            std::cout << "Años de Capuchino:";
            return a + b + c;
        }
        int suma(int a, int b, int c, int d) {
            std::cout << "Años de Orangutan:";
            return a + b + c + d;
        }
        int suma(int a, int b, int c, int d, int e) {
            std::cout << "Años Totales de los simios:";
            return a + b + c + d + e;
        }
};

//Sobrecarga de Operadores
class Vector {
    public:
        Vector(int x, int y) {
            this->x = x;
            this->y = y;
        }

        Vector operator+(Vector v) {
            return Vector(this->x + v.x, this->y + v.y);
        }

        Vector operator-(Vector v) {
            return Vector(this->x - v.x, this->y - v.y);
        }
        Vector operator*(Vector v) {
            return Vector(this->x * v.x, this->y * v.y);
        }
        Vector operator/(Vector v) {
            return Vector(this->x / v.x, this->y / v.y);
        }

    private:
        int x;
        int y;
};

int main(){
    Animal simio("El simio", " come platano");
    std::cout << simio.getNombre();
    std::cout << simio.getComida() << std::endl;

    simio.setNombre("Primate");
    std::cout << simio.getNombre();

    Simios chimpance(" Chimpance", " come platano", "Tipo de simio: chimpance");
    std::cout << chimpance.getNombre();
    std::cout << chimpance.getComida() << std::endl;
    std::cout << chimpance.getTipo() << std::endl;

    Mono primate;
    std::cout << primate.getNombreCientifico(simio) << std::endl;
    
    Chango chango;
    chango.sonido();
    Capuchino capuchino;
    capuchino.sonido();
    Orangutan orangutan;
    orangutan.sonido();
    
     Operaciones operaciones;
    std::cout << operaciones.suma(11,2) << std::endl;
    std::cout << operaciones.suma(1,8,3) << std::endl;
    std::cout << operaciones.suma(6,2,3,7) << std::endl;
    std::cout << operaciones.suma(10,10,10,10,3) << std::endl;
    
    Vector v1(1,2);
    Vector v2(3,4);

    Vector r = v1+v2;

    return 0;
}
