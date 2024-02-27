/**
 * Autor: Alejandro Benedi Andrés   Nip: 843826 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentra la definicion e implemtenracion
 *       de la clase Item asi como sus metodos.
**/

#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>


class Item { // De esta clase saldran los 3 tipos de cargas
protected:
    const std::string _nombre;
    double _volumen;
    double _peso;
public:

    Item(const std::string& nom, double v, double p) : _nombre(nom), _volumen(v), _peso(p) {} ;
    
    //Devuelve el nombre del item
    std::string nombre() const{
        return _nombre;
    }

    //Devuelve el volumen del item
    double volumen() const{
        return _volumen;
    }

    //Devuelve el peso del item
    virtual double peso() const {
        return _peso;
    }

    /**
     * Devuelve el tipo de item. Sera util para saber de que 
     * tipo de carga de un contenedor
    */
    virtual std::string tipo() const{
        return "";
    }

    /**
     * Mostrara por pantalla el nombre, volumen, y peso.
     * Sigue el mismo formato que ejemplo de ejecucuión del "Main"
    */
    virtual std::string mostrar() const {
        std::stringstream output;
        output << "    " << std::fixed <<  std::setprecision(1) <<  this->nombre() << " [" 
            << this->volumen() << " m3] [" << this->peso() << " kg]" << std::endl;
        return output.str();
    }
};




