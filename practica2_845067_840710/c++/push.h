/**
 * Autor: Jorge Jaime Modrego   Nip: 845067 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentra la implemetacion
 *       de la instruccion "Push" en c++
**/
#pragma once
#include <stack>
#include "instruccion.h"
#include <iostream>
#include <string>

class Push : public Instruccion {
private:
    // Atributo de la clase Push
    int num;
public:

    // Constructor
    Push(std::stack<int>* p, int _num):
        Instruccion(p, "push"), num(_num)
    {}

    // Destructor
    ~Push(){}

    // Apila el atributo num en la pila
    void ejecuta(int& pc) override {
        pila->push(num);
        pc++;
    }   
};