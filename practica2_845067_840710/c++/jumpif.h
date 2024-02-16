#pragma once
#include <stack>
#include "instruccion.h"
#include <iostream>
#include <string>

class Jumpif : public Instruccion {
private:
    // Atributos de la clase Jumpif
    int num;
public:
    //Constructor
    Jumpif(std::stack<int>* p, int _num):
        Instruccion(p, "add"), num(_num)
    {}
    ~Jumpif(){}
    // desapila la cima de la pila, y si su valor es mayor o igual que cero salta la ejecución del
    // programa a la línea <l> (parámetro de la instrucción)
    void ejecuta(int& pc) override {
        int a = pila->top();
        pila->pop();
        if(a >= 0){ pc = num; }
        else { pc++; }
    }   
};