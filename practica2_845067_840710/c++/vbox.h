/**
 * Autor: Alejandro Benedi Andrés   Nip: 843826 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentra la definicion y la implemtenacion
 * de un interprete en c++ para poder ejecutar los 3 programas de test.
**/

#pragma once
#include <vector>
#include "instruccion.h"
#include <iostream>

class Vbox
{
private:
    int pc;             // El pc (Program counter)  es el que va indicar que instruccion ejecutar
    std::stack<int> p;
public:
    Vbox() : pc(0), p() { };
    ~Vbox() {
        pc = 0;
    }

    /**
     * Este metodo es el encargado de ejecutar los programas.
     * Inicialmente mostrara las instrucciones del programa.
     * Posteriormente mostrara la propia ejecucion del programa
     */
    void ejecutar(const std::vector<Instruccion*> prog){
        std::cout << "Programa: " << std::endl;
        for(int i=0; i<prog.size(); i++){
            std::cout << i << "   " << prog[i]->listar() << std::endl;
        }
        std::cout << "\nEjecucion: " << std::endl;
        while(pc < prog.size()){
            prog[pc]->op(p, pc);        // Tanto la <p> com <pc> estam pasador por referencia, 
        }                                   // es decir será la instruccion quien modifica ambas variables
    }
};

