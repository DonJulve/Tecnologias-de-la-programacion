#pragma once
#include <stack>
#include <iostream>
#include "instruccion.h"

class Programa {
protected:
    // Atributos de la clase Programa
    std::stack<int>* pila;
    Instruccion** instrucciones;
    int numInstr;
    int pc;
public:

    // Constructor
    Programa(std::stack<int>* p,int _numInstr, int _pc):
        pila(p),numInstr(_numInstr), pc(_pc)
    {
        instrucciones = new Instruccion*[_numInstr]; 
    }

    // Destructor
    ~Programa() {
        for(int i=0; i < numInstr; i++){
            delete instrucciones[i];
        }
        delete[] instrucciones;
    }

    // Método que ejecuta un programa
    void ejecutar(std::ostream &os){
        os << "Ejecución del programa: " << std::endl;
        while(pc < numInstr){
            instrucciones[pc]->ejecuta(pc);
        }
    }

    // Método que lista todas las instrucciones de un programa
    void listarse(std::ostream& os) const {
        for(int i=0; i < numInstr; i++){
            instrucciones[i]->representar(i);
        }
    }   
    
};