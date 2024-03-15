//---------------------------------------------------------------------------
// File: carga.h
// Authors: Javier Julve Yubero (840710) y Jorge Jaime Modrego(845067)
// Date: Marzo 2023
//---------------------------------------------------------------------------
#pragma once
#include "cargable.h"

class Carga: public Cargable {
public:
    // Constructor
    Carga(const std::string& nombre, double _vol, double _pes, const std::string& tipo) 
    : Cargable(nombre, _vol, _pes, "de Carga Estandar")
    {}

};