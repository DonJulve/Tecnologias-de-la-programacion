/**
 * Autor: Jorge Jaime Modrego   Nip: 845067 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentra el "Main". En el
 * se crean y se mandan a ejecutar los 3 programas test
**/
#include <stack>
#include <iostream>
#include "sumaProg.h"
#include "cuentaAtras.h"
#include "factorial.h"

// Programa principal en el que se listan y se ejecutan las instrucciones 
// de los 3 programas de la práctica
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