/**
 * Autor: Alejandro Benedi Andrés   Nip: 843826 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentra toda las definiciones en c++
 * de todas las instrucciones de la practica
**/

#pragma once
#include <stack>
#include <iostream>

class Instruccion {
protected:
    int parametro;          // Parametro de la instruccion si tiene 
    std::string nombre;     // Nombre de la instruccion
    bool tiene_parametro;   // Es "True" cuando tiene la instruccion tiene parametro
public:

    
    // Este constructor se usara si la instruccion tiene un parametro
    Instruccion(int num, std::string nom) : parametro(num), nombre(nom), tiene_parametro(true) { };
    
    // Este constructor se usara si la instruccion no tiene ninguna paramentro
    Instruccion(std::string nom) : nombre(nom), tiene_parametro(false) { };
    
    
    /**
     * Este metodo sera sobrescrito por cada instruccion diferente
     * Tanto la variable tipo "Stack" p y la variable de tipo "Int" pc
     * seran de entrada y de salida.
    */
    virtual void op(std::stack<int>& p, int& pc) const = 0;

    /**
     * Devuelve el nombre de la instruccion.Además de devolver el
     * nombre tambien se devolvera el parametro si la instruccion tiene.
     * Si la instruccion no tiene parametro tan solo se devolvera el nombre
     * de la instruccion
    */
    std::string listar() const;
    

};

// Instrucciones primer programa

/**
 * Se pide al usuario un numero y este es 
 * introducido en la pila
 */
class Read : public Instruccion {
public:
    void op(std::stack<int>& p, int& pc) const override;
    Read(std::string nom) : Instruccion(nom){ };
    
};

/**
 * Se desapilan 2 elementos, se calcula la suma y el resultado 
 * de esta se vuelve a apilar.
 */
class Add : public Instruccion {
public:
    void op(std::stack<int>& p, int& pc) const override;
    Add(std::string nom) : Instruccion(nom){ };
};

/**
 * Se desapila un elemento y se muestra por pantalla
 */
class Write : public Instruccion {
public:
    void op(std::stack<int>& p, int& pc) const override;
    Write(std::string nom) : Instruccion(nom){ };
};


// Instrucciones segundo programa

/*
 * Se apila el parametro de la instruccion
 */
class Push : public Instruccion {
public:
    void op(std::stack<int>& p, int& pc) const override;
    Push(int num, std::string nom) : Instruccion(num, nom){ };
};

/**
 * Duplica el elemnto que se encuentra en 
 * la cima de pila
 */
class Dup : public Instruccion {
public:
    void op(std::stack<int>& p, int& pc) const override;
    Dup(std::string nom) : Instruccion(nom){ };
};

/**
 * Si el numero que se encuentra en la cima es mayor
 * que 0, se salta a la instruccion que indique el parametro
 * de la instruccion
 */
class Jumpif : public Instruccion {
public:
    void op(std::stack<int>& p, int& pc) const override;
    Jumpif(int num, std::string nom) : Instruccion(num, nom){ };
};


// Instrucciones tercer programa

/**
 * Desapila 2 elementos, los multiplica y el resultado
 * se vuelve a introducir en la pila
 */
class Mul : public Instruccion {
public:
    void op(std::stack<int>& p, int& pc) const override;
    Mul(std::string nom) : Instruccion(nom){ };
};

/**
 * Intercambia de posicion 2 elementos de la pila 
 */
class Swap : public Instruccion {
public:
    void op(std::stack<int>& p, int& pc) const override;
    Swap(std::string nom) : Instruccion(nom){ };
};

/**
 * Copia el elemento que esta tran la cima de pila
 */
class Over : public Instruccion {
public:
    void op(std::stack<int>& p, int& pc) const override;
    Over(std::string nom) : Instruccion(nom){ };
};




