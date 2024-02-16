#pragma once
#include <stack>
#include "instruccion.h"
#include <iostream>
#include <string>

class Swap : public Instruccion {

public:
    //Cosntructor
    Swap(std::stack<int>* p) : Instruccion(p, "swap"){}
    ~Swap(){}
    // intercambia dos elementos en la cima de la pila (desapila dos valores y los reapila en orden inverso)
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