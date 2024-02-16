#pragma once
#include <stack>
#include <iostream>
#include <string>

//Clase abstracta ya que tiene algún método virtual puro
class Instruccion {
protected:
    // atributos de la clase Instruccion
    std::stack<int>* pila;
    std::string instruccion;
public:
    //Constructor
    Instruccion(std::stack<int>* p,std::string i):
    pila(p), instruccion(i)
    {}
    //Destructor
    ~Instruccion() {}
    // Método que asigna al atributo instruccion la variable ins
    void asignar(std::string ins){
        instruccion = ins;
    }
    // Método que escribe por la salida standard el número de instrucción y la instrucción a ejecutar
    void representar(int i){
        std::cout << i << " " << this->instruccion << std::endl;
    }
    // Método virtual puro
    virtual void ejecuta(int &pc) = 0;
};