/**
 * Autor: Jorge Jaime Modrego   Nip: 845067 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentra la implemetacion
 *       de la instruccion "Dup" en c++
**/
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

    //Destructor
    ~Dup(){}

    // Duplica la cima de la pila desapilando su valor y apilándolo dos veces
    void ejecuta(int& pc) override {
        int a = pila->top();
        pila->pop();
        pila->push(a);
        pila->push(a);
        pc++;
    }   
};