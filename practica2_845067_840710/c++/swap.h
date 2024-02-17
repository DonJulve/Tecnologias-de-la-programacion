#pragma once
#include <stack>
#include "instruccion.h"
#include <iostream>
#include <string>

class Swap : public Instruccion {

public:
    //Constructor
    Swap(std::stack<int>* p) : Instruccion(p, "swap"){}

    //Destructor
    ~Swap(){}

    // Intercambia dos elementos en la cima de la pila desapilando dos valores
    // y apilándolos en el orden inverso
    void ejecuta(int& pc) override {
        int a = pila->top();
        pila->pop();
        int b = pila->top();
        pila->pop();
        pila->push(a);
        pila->push(b);
        pc++;
    }    
};