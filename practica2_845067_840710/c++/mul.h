/**
 * Autor: Jorge Jaime Modrego   Nip: 845067 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentra la implemetacion
 *       de la instruccion "Mul" en c++
**/
#pragma once
#include <stack>
#include "instruccion.h"
#include <iostream>
#include <string>

class Mul : public Instruccion {
public:

    //Constructor
    Mul(std::stack<int>* p) : Instruccion(p, "mul"){}

    //Destructor
    ~Mul(){}

    //Desapila dos valores de la pila y apila el producto
    void ejecuta(int& pc) override {
        int a = pila->top();
        pila->pop();
        int b = pila->top();
        pila->pop();
        pila->push(a*b);
        pc++;
    }
};