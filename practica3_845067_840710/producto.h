//---------------------------------------------------------------------------
// File: producto.h
// Authors: Javier Julve Yubero (840710) y Jorge Jaime Modrego(845067)
// Date: Marzo 2023
//---------------------------------------------------------------------------
#include "carga.h"
#pragma once

class Producto : public Carga {
public:
    // Constructor
    Producto(const std::string& nombre, double _vol, double _pes)
    : Carga(nombre, _vol, _pes, "de Carga Estandar") {}
};