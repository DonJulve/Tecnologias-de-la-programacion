/**
 * Autor: Jorge Jaime Modrego   Nip: 845067 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentra toda las definiciones 
 *       de los metodos de la clase padre de las "Instrucciones"
 *       De esta "super clase" saldran todas las instrucciones 
 *       de la practica
**/
#pragma once
#include <stack>
#include <iostream>
#include <string>

//Clase abstracta que tiene algún método virtual puro
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

    // Método que asigna al atributo instruccion la variable instr
    void asignar(std::string instr){
        instruccion = instr;
    }

    // Método que escribe por la salida estandar el número de instrucción y la instrucción a ejecutar
    void representar(int i){
        std::cout << i << " " << this->instruccion << std::endl;
    }

    // Método virtual puro
    virtual void ejecuta(int &pc) = 0;
};