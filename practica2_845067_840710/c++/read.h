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

    //Destructor
    ~Read(){}

    // Pide un valor al usuario por terminal y lo apila en la pila
    void ejecuta(int& pc) override {
        std::cout << "Introduce un número: ";
        int a;
        std::cin >> a;
        pila->push(a);
        pc++;
    }   
};