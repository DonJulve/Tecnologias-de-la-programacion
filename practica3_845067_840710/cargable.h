//---------------------------------------------------------------------------
// File: cargable.h
// Authors: Javier Julve Yubero (840710) y Jorge Jaime Modrego(845067)
// Date: Marzo 2024
//---------------------------------------------------------------------------
#pragma once

#include <sstream>
#include <iostream>
#include <vector>
#include <string>

// Clase Cargable que representa un elemento que puede ser cargado en un contenedor y que servirá como herencia para el resto del tipo de
// elementos que se pueden cargar en un vehiculo
class Cargable {
protected: 
    double v; // volumen del elemento
    double p; // peso del elemento
    std::string n; // nombre del elemento
    std::string _tipo; // tipo de elemento (estándar,ser vivo o toxico)
public:
    // Constructor
    Cargable(const std::string& nombre, double volumen, double peso, const std::string& tipo) :
    v(volumen), p(peso), n(nombre), _tipo(tipo)
    {}

    // Método que devuelve el nombre del elemento
    std::string nombre() const {
        return this->n;
    }

    // Método que devuelve el volumen  del elemento
    virtual double volumen() const {
        return this->v;
    }

    // Método que devuelve el peso  del elemento
    virtual double peso() {
        return this->p;
    }

    // Método que devuelve el tipo  del elemento
    std::string tipo() const {
        return this->_tipo;
    }

    // Método que escribe el nombre del elemento junto a su volumen y su peso
    virtual std::string write(std::string esp) {
        std::stringstream st;
        st << esp << n << " [" << volumen() << " m3] [" << peso() << " kg] " << std::endl;
        return st.str();
    }
};