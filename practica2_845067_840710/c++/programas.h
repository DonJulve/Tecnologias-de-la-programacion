/**
 * Autor: Alejandro Benedi Andrés   Nip: 843826 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentra toda las definiciones e 
 * implementeaciones en c++ de los 3 programas para testear
 * las instrucciones asi como la llamada al interprete para la 
 * ejecucion de estos.
**/

#pragma once
#include "instruccion.h"
#include "vbox.h"
#include <vector>   // La libreria "Vector" permite crear un vector dinamico con facilidad

class Programas{
protected:
    std::vector<Instruccion*> v;    // Al usar la libreria "Vector" no es necesario otra
                                    // variable que gruarde el numero de instrucciones del vector 
public:
    ~Programas(){
        v.clear();
    }

    // Llama a la clase interprete para ejecutar el programa
    void ejecutar_programa(){
        Vbox Interprete;
        Interprete.ejecutar(v);
    };
};

/**
 * Este programa pide al usario 2 numeros enteros y mostrará por pantalla
 * la suma de los 2 numeros introducidos
 * Tras declarar todas las instrucciones necesarias el programa es ejecutado
 */
class Sumar : public Programas {
public:
    Sumar() {
        v.push_back(new Read("Read"));
        v.push_back(new Read("Read"));
        v.push_back(new Add("Add"));
        v.push_back(new Write("Write"));
    }
 
};

/**
 * Este programa pide al usuario un número ( entero y positivo ) y 
 * mostrará por pantalla una cuenta atrás desde ese número, de uno en uno hasta 
 * llegar a cero.
 * Tras declarar todas las instrucciones necesarias el programa es ejecutado
 */
class Cuenta_atras : public Programas {
public:
    Cuenta_atras(){
        v.push_back(new Read("Read"));
        v.push_back(new Dup("Dup"));
        v.push_back(new Write("Write"));
        v.push_back(new Push(-1,"Push"));
        v.push_back(new Add("Add"));
        v.push_back(new Dup("Dup"));
        v.push_back(new Jumpif(1,"Jumpif"));
    }
    
};

/**
 * Este programa pide al usuario un numero entero y mostrara en pantalla el 
 * factorial del numero introducido.
 * Tras declarar todas las instrucciones necesarias el programa es ejecutado
 */
class Factorial : public Programas {
public:
    Factorial(){
        v.push_back(new Push(1,"Push"));
        v.push_back(new Read("Read"));
        v.push_back(new Swap("Swap"));
        v.push_back(new Over("Over"));
        v.push_back(new Mul("Mul"));
        v.push_back(new Swap("Swap"));
        v.push_back(new Push(-1,"Push"));
        v.push_back(new Add("Add"));
        v.push_back(new Dup("Dup"));
        v.push_back(new Push(-2,"Push"));
        v.push_back(new Add("Add"));
        v.push_back(new Jumpif(2,"Jumpif"));
        v.push_back(new Swap("Swap"));
        v.push_back(new Write("Write"));
    }
    
};