/**
 * Autor: Alejandro Benedi Andrés   Nip: 843826 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentra la definicion e implementacion 
 *       de todos los tipos de almacenes
**/

#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

#include "item.h"
#include "tipos_carga.h"

template <typename T>
class Almacen { 
protected:
    double capacidad_maxima; // Depende del volume
    double capacidad_actual; // Volumen que tiene en ese momento
    double _peso;            // Peso acumulado del almacen
    std::string _nombre;
    std::vector<T*> carga;   // En este vector se iran guardando todos los contenedores o productos

public:

    Almacen(double can, std::string nom) : capacidad_maxima (can), capacidad_actual(0.0), _nombre(nom), _peso(0) {}

    ~Almacen(){
        carga.clear();
    }

    // Devuelve el volumen del almacen
    double volumen() const {
        return capacidad_maxima;
    }

    // Devuelve el nombre del almacen
    std::string nombre() const{
        return _nombre;
    }
    
    // Devuelve el peso acumulado del almacen
    double peso() const {
        return _peso;
    }
    
    /**
     * Este metodo guarda en el vector <carga> los diferentes productos
     * y/o contenedores. Ademas este metodo permite ir actualizando el peso
     * del almacen
    */
    bool guardar(T* producto){
        if(producto->volumen() + capacidad_actual <= capacidad_maxima){
            capacidad_actual = producto->volumen() + capacidad_actual;
            _peso = _peso + producto->peso();
            carga.push_back(producto);
            return true;
        }
        return false;
    }

    
    /**
     * Muestra por pantalla el nombre, volumen y peso del almacen,asi como 
     * todos los productos  y/o contenedores almacenados dentro del alamcen.
     * Sigue el mismo formato que el ejemplo del "Main"
    */
    std::string mostrar() const {
        std::stringstream output;
        output << std::fixed <<  std::setprecision(1) <<  this->nombre() << " [" 
            << this->volumen() << " m3] [" << this->peso() << " kg]" << std::endl;
        for (auto i : this->carga){
            output << i->mostrar();
        }
        return output.str();
    }
};

template <typename T>
class Contenedor : public Almacen<T>, public Carga{
public:

    Contenedor(double capacidad) : Almacen<T>(capacidad, "Contenedor"), Carga("Contenedor", capacidad, 0.0) {}

    /**
     * Redefine el metodo peso de la clase "Item" ya que un contenedor se considera
     * como una carga estandar. Este metodo redefinido devuelve el peso de un contenedor
     * es decir, devuelve la suma de todos los productos y/o contenedores almacenados 
     * dentro del contenedor.
    */
    double peso() const override{
        double peso = 0;
        for (auto i : this->carga){
            peso = peso + i->peso();
        }
        return peso;
    }

    /**
     * Redefimimos el metodo de la clase "Item" ya que un contenedor es considerado 
     * como una carga estandar. Este metodo redefinido muestra por pantalla el nombre,
     * volumen, peso y tipo del contenedor, asi como todos los productos y/o contenedores
     * almacenados dentro del contenedor.
     * Sigue el mismo formato que el ejemplo de ejecucion del "Main"
    */
    std::string mostrar() const override {
        std::stringstream output;
        output << "  " << std::fixed << std::setprecision(1) <<  Carga::nombre() << " [" 
            << Carga::volumen() << " m3] [" << peso() << " kg] " << this->carga[0]->tipo() << std::endl;
        for ( auto i : this->carga ){
            output << "  " << i->mostrar();
        }
        return output.str();
    }
};

class Camion : public Almacen<Carga>{
public:
    Camion(double capacidad) : Almacen(capacidad, "Camion") {}
};

/**
 * Redefine el operador "<<" para poder imprimir toda la informacion del camion,
 * asi como todo los productos y/o que tenga almacenado
*/
std::ostream& operator<<(std::ostream& os, Camion ca) {
    os << ca.mostrar() << std::endl;
}


