#include <stack>
#include <iostream>
#include "sumaProg.h"
#include "cuentaAtras.h"
#include "factorial.h"

int main(){
    std::stack<int>* pila = new std::stack<int>;
    std::cout << "Ejecución de la suma de dos números" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    Suma sum(pila);
    sum.listarse(std::cout);
    std::cout << std::endl;
    sum.ejecutar(std::cout);
    
    std::cout << std::endl << std::endl << "Ejecución de la cuenta atrás" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    Cuenta cuenta(pila);
    cuenta.listarse(std::cout);
    std::cout << std::endl;
    cuenta.ejecutar(std::cout);



    std::cout << std::endl << std::endl << "Ejecución del factorial" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    Factorial fact(pila);
    fact.listarse(std::cout);
    std::cout << std::endl;
    fact.ejecutar(std::cout);
}