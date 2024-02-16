
#pragma once
#include <stack>
#include "instruccion.h"
#include <iostream>
#include <string>

class Add : public Instruccion {
public:
    //Constructor
    Add(std::stack<int>* p):
        Instruccion(p, "add")
    {}
    ~Add(){}
    // Método que desapila dos valores de la pila y apila su suma
    void ejecuta(int& pc) override {
        int a = pila->top();
        pila->pop();
        int b = pila->top();
        pila->pop();
        pila->push(a+b);
        pc++;
    }   
};