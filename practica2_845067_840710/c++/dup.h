#pragma once
#include <stack>
#include "instruccion.h"
#include <iostream>
#include <string>

class Dup : public Instruccion {
public:
    //Constructor
    Dup(std::stack<int>* p):
        Instruccion(p, "dup")
    {}
    ~Dup(){}
    // duplica la cima de la pila (desapila su valor y lo reapila dos veces)
    void ejecuta(int& pc) override {
        int a = pila->top();
        pila->pop();
        pila->push(a);
        pila->push(a);
        pc++;
    }   
};