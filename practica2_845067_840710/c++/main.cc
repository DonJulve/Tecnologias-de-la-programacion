#include <stack>
#include <iostream>
#include "sumaProg.h"
#include "cuentaAtras.h"

int main(){
    std::cout << "Ejecución de la suma de dos números" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::stack<int>* pila = new std::stack<int>;
    Cuenta sum(pila);
    sum.listarse(std::cout);
    sum.ejecutar(std::cout);
}