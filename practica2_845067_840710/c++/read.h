#pragma once
#include <stack>
#include "instruccion.h"
#include <iostream>
#include <string>


class Read : public Instruccion {
public:
    //Constructor
    Read(std::stack<int>* p):
        Instruccion(p, "read")
    {}
    ~Read(){}
    // pide un valor al usuario por la entrada estándar (indicando al usuario de alguna forma que espera
    // una entrada de datos) y lo apila en la pila
    void ejecuta(int& pc) override {
        std::cout << "Introduce un número: ";
        int a;
        std::cin >> a;
        pila->push(a);
        pc++;
    }   
};