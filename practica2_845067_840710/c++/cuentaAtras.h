#pragma once
#include <stack>
#include <iostream>
#include "programa.h"
#include "read.h"
#include "write.h"
#include "add.h"
#include "push.h"
#include "jumpif.h"
#include "dup.h"

class Cuenta: public Programa {
public:

    //Método que ejecuta el programa que realiza una cuenta atrás
    Cuenta(std::stack<int>* p)
        :Programa(p, 7, 0)
    {
            instrucciones[0] = new Read(p);
            instrucciones[1] = new Dup(p);
            instrucciones[2] = new Write(p);
            instrucciones[3] = new Push(p, -1);
            instrucciones[4] = new Add(p);
            instrucciones[5] = new Dup(p);
            instrucciones[6] = new Jumpif(p, 1);
         
    }

    //Destructor
    ~Cuenta() 
    {}
};