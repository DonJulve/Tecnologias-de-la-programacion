//---------------------------------------------------------------------------
// File: almacen.h
// Authors: Javier Julve Yubero (840710) y Jorge Jaime Modrego(845067)
// Date: Marzo 2023
//---------------------------------------------------------------------------
#include <vector>
#pragma once
template <typename T>
class Almacen {
protected:
    double cap; // capacidad del alamacén
    std::vector<T*> es; // vector de punteros a un tipo de dato genérico
public:
    //Constructor
    Almacen(double c) : cap(c) {}

    //Destructor
    virtual ~Almacen() {
        es.clear();
    }

    // Método que devuelve la capacidad del almacén
    double capacidad() const {
        return cap;
    }

    // Método que  guardará el elemento que se le pasa como argumento (sea un producto o un contenedor)
    // si cabe según su capacidad. Si el elemento es guardado, el método devolverá true, mientras que
    // si no hay capacidad libre suficiente, el elemento no se guardará y el método devolverá false
    bool guardar(T* e) {
        double vol = 0.0;
        for (auto i : es) {
            vol += i->volumen();
        }
        bool sePuede = vol + e->volumen() <= cap;
        if(sePuede) {
            T* aux = e;
            es.push_back(aux);
        }
        return sePuede;
    }
};