//---------------------------------------------------------------------------
// File: servivo.h
// Authors: Javier Julve Yubero (840710) y Jorge Jaime Modrego(845067)
// Date: Marzo 2023
//---------------------------------------------------------------------------
#pragma once
#include "cargable.h"

class SerVivo : public Cargable {
public:
    // Constructor
    SerVivo(const std::string& nombre, double _vol, double _pes) 
    : Cargable(nombre, _vol, _pes, "de Seres Vivos") {}

};
