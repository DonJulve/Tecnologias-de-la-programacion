#pragma once
#include <stack>
#include <iostream>
#include <string>
#include "instruccion.h"


class Write : public Instruccion {
public:
    // Constructor
    Write(std::stack<int>* p):
        Instruccion(p, "write")
    {}
    ~Write(){}
    // desapila un valor de la pila y lo muestra por la salida estándar (pantalla) al usuario
    void ejecuta(int& pc) override {
        int a = pila->top();
        pila->pop();
        pc++;
        std::cout << "El número es: " << a << std::endl;
    }   
};