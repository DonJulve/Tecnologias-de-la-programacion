//---------------------------------------------------------------------------
// File: camion.h
// Authors: Javier Julve Yubero (840710) y Jorge Jaime Modrego(845067)
// Date: Marzo 2023
//---------------------------------------------------------------------------
#include "almacen.h"
#include <string>
#include "carga.h"
#pragma once


class Camion : public Almacen<Carga> {
private:
    std::string n; // nombre del elemento ("Camión")
    double p; // peso del Camión
public:
    Camion(double cap) : Almacen<Carga>(cap), n("Camion"), p(0.0) {}

    // Método que devuelve el nombre del Camión
    std::string nombre() const {
        return n;
    }

    // Método que devuelve el peso del Camión, es decir, la suma de los elementos que contiene
    double peso() {
        double aux = 0.0;
        for (auto i : this-> es) {
            aux += i->peso();
        }
        p = aux;
        return aux; 
    }

    // Método que escribe el nombre, volumen y peso del camión, debajo los de sus elementos
    std::string write(std::string esp) {
        std::stringstream st;
        st << n << " [" << capacidad() << " m3] [" << peso() << " kg] " << std::endl;
        for ( auto i : this->es ) {
            st << esp << i->write(esp);
        }
        return st.str();
    }

    // Método para mostrar por pantalla todos los elementos
    friend std::ostream& operator<<(std::ostream& os, Camion& item) {
        os << item.write("  ");
        return os;
    }
};