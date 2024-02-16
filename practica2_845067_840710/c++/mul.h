#pragma once
#include <stack>
#include "instruccion.h"
#include <iostream>
#include <string>

class Mul : public Instruccion {
public:
    //Constructor
    Mul(std::stack<int>* p) : Instruccion(p, "mul"){}
    ~Mul(){}
    // desapila dos valores de la pila y apila su producto
    void ejecuta(int& pc) override {
        int a = pila->top();
        pila->pop();
        int b = pila->top();
        pila->pop();
        pila->push(a*b);
        pc++;
    }
};