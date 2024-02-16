#pragma once
#include <stack>
#include <iostream>
#include "programa.h"
#include "mul.h"
#include "swap.h"
#include "over.h"
#include "push.h"
#include "read.h"
#include "add.h"
#include "dup.h"
#include "jumpif.h"
#include "write.h"


class Factorial : public Programa {
public:
    // Programa que haya el factorial de un número
    Factorial(std::stack<int>* p) : Programa(p,14,0){
        instrucciones[0] = new Push(p,1);
        instrucciones[1] = new Read(p);
        instrucciones[2] = new Swap(p);
        instrucciones[3] = new Over(p);
        instrucciones[4] = new Mul(p);
        instrucciones[5] = new Swap(p);
        instrucciones[6] = new Push(p,-1);
        instrucciones[7] = new Add(p);
        instrucciones[8] = new Dup(p);
        instrucciones[9] = new Push(p,-2);
        instrucciones[10] = new Add(p);
        instrucciones[11] = new Jumpif(p,2);
        instrucciones[12] = new Swap(p);
        instrucciones[13] = new Write(p);
    }
    ~Factorial(){}
};