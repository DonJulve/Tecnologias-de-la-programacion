//---------------------------------------------------------------------------
// File: carga.h
// Authors: Javier Julve Yubero (840710) y Jorge Jaime Modrego(845067)
// Date: Marzo 2024
//---------------------------------------------------------------------------
#pragma once
#include "cargable.h"

// Clase Carga que hereda de Cargable, implementando su constructor por defecto
class Carga: public Cargable {
public:
    // Constructor
    Carga(const std::string& nombre, double _vol, double _pes, const std::string& tipo) 
    : Cargable(nombre, _vol, _pes, "de Carga Estandar")
    {}

};