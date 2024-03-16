//---------------------------------------------------------------------------
// File: producto.h
// Authors: Javier Julve Yubero (840710) y Jorge Jaime Modrego(845067)
// Date: Marzo 2024
//---------------------------------------------------------------------------
#include "carga.h"
#pragma once

// Clase Producto que hereda de Carga, implementando su constructor por defecto y sus métodos virtuales
class Producto : public Carga {
public:
    // Constructor
    Producto(const std::string& nombre, double _vol, double _pes)
    : Carga(nombre, _vol, _pes, "de Carga Estandar") {}
};