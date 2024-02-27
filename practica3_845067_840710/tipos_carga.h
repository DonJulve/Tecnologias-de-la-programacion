/**
 * Autor: Alejandro Benedi Andrés   Nip: 843826 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentra las especificaciones
 *       e implementacion de las los tipos de carga que puede
 *       tener los almacenes.
**/

#pragma once
#include "item.h"
#include <iostream>

class Carga : public Item {
public:

    Carga(const std::string& nom, double v, double p) : Item(nom, v, p) {}

    /**
     * Devuelve el tipo de carga. Sera de gran utilidad para
     * saber el tipo de carga de un contenedor
    */
    std::string tipo() const override{
        return "de Carga Estandar";
    }
};

class Toxico : public Item {
public:

    Toxico(const std::string& nom, double v, double p) : Item(nom, v, p) {}
    
    /**
     * Devuelve el tipo de carga. Sera de gran utilidad para
     * saber el tipo de carga de un contenedor
    */
    std::string tipo() const override{
        return "de Productos Toxicos";
    }
};

class SerVivo : public Item {
public:

    SerVivo(const std::string& nom, double v, double p) : Item(nom, v, p) {}
    
    /**
     * Devuelve el tipo de carga. Sera de gran utilidad para
     * saber el tipo de carga de un contenedor
    */
    std::string tipo() const override{
        return "de Seres Vivos";
    }
};

class Producto : public Carga {
public:

    Producto(const std::string& nom, double v, double p) : Carga(nom, v, p) {}

    std::string mostrar() const {
        std::stringstream output;
        output << "  " << std::fixed <<  std::setprecision(1) <<  this->nombre() << " [" 
            << this->volumen() << " m3] [" << this->peso() << " kg]" << std::endl;
        return output.str();
    }
};
