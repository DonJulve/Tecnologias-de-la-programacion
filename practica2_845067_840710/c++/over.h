/**
 * Autor: Jorge Jaime Modrego   Nip: 845067 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentra la implemetacion
 *       de la instruccion "Over" en c++
**/
#pragma once
#include <stack>
#include "instruccion.h"
#include <iostream>
#include <string>

class Over : public Instruccion {
public:
    //Constructor    
    Over(std::stack<int>* p) : Instruccion (p, "over"){}

    //Destructor
    ~Over(){}

    // Copia el valor que está tras la cima de la pila, desapila dos valores, 
    // apila el segundo desapilado, después el primero y por último el segundo otra vez
    void ejecuta(int& pc) override {
        int a = pila->top();
        pila->pop();
        int b = pila->top();
        pila->pop();
        pila->push(b);
        pila->push(a);
        pila->push(b);
        pc++;
    }
};