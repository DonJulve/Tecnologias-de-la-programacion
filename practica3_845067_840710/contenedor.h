//---------------------------------------------------------------------------
// File: contenedor.h
// Authors: Javier Julve Yubero (840710) y Jorge Jaime Modrego(845067)
// Date: Marzo 2024
//---------------------------------------------------------------------------
#include "carga.h"
#include "almacen.h"
#pragma once
// Clase Contenedor que hereda de Carga y Almacen, con tipo de dato T, implementando sus métodos virtuales
template <typename T>
class Contenedor : public Carga, public Almacen<T> {
public:
    // Constructor
    Contenedor(double capacidad) : Carga("Contenedor", capacidad, 0.0, "de Carga Estandar"),
    Almacen<T>(capacidad) {}

    // Método que devuelve el peso total del contenedor, es decir, la suma de todos sus elementos
    double peso() override {
        double aux = 0.0;
        for (auto i : this->es) {
            aux += i->peso();
        }
        p = aux;
        return aux; 
    }

    // Método que escribe Contenedor seguido de su volumen, peso y tipo, debajo escribe los de los elementos que contiene
    std::string write(std::string esp) override {
        std::stringstream st;
        st << esp << n << " [" << volumen() << " m3] [" << peso() << " kg] " << this->es.front()->tipo() << std::endl;
        for ( auto i : this->es ) {
            st << esp << i->write("    ");
        }
        return st.str();
    }
};
