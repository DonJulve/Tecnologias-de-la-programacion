//---------------------------------------------------------------------------
// File: toxico.h
// Authors: Javier Julve Yubero (840710) y Jorge Jaime Modrego(845067)
// Date: Marzo 2024
//---------------------------------------------------------------------------
#pragma once
#include "cargable.h"

// Clase Toxico que hereda de Cargable, implementando su constructor por defecto y sus métodos virtuales
class Toxico : public Cargable {
public:
    // Constructor
    Toxico(const std::string& nombre, double _vol, double _pes) 
    : Cargable(nombre, _vol, _pes, "de Productos Toxicos") {}

};