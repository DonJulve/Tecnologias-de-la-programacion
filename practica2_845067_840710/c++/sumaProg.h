#pragma once
#include <stack>
#include <iostream>
#include "programa.h"
#include "read.h"
#include "write.h"
#include "add.h"


class Suma: public Programa {
public:

    // Ejecuta el programa que suma dos numeros
    Suma(std::stack<int>* p)
        :Programa(p, 4, 0)
    {
            instrucciones[0] = new Read(p);
            instrucciones[1] = new Read(p);
            instrucciones[2] = new Add(p);
            instrucciones[3] = new Write(p);
         
    }

    //Destructor
    ~Suma() 
    {}
};