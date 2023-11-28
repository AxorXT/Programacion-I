#include <iostream>
#include <string>

class Animal{
    public:

        Animal(std::string nombre){
            this -> nombre = nombre;
        }

        void AnimalComiendo(){
            std::cout << "El animal " << nombre << " esta comiendo platano" << std::endl;
        }

    private:
        std::string nombre;
};

class Simios : public Animal{
    public:
    
    Simios(std::string nombre, std::string Tipo) : Animal(nombre){
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

int main(){
    Simios simio("Simio", "mono");
    simio.AnimalComiendo();
    
    Simios chimpance("Chimpance", "Tipo de simio: chimpance");
    std::cout << chimpance.getTipo() << std::endl;

    return 0;
}
