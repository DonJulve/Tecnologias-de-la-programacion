/**
 * Autor: Alejandro Benedi Andrés   Nip: 843826 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentran todos las
 *          excepciones que se pueden lanzar.
**/

#pragma once 

#include <cstring>
#include<exception>

class arbol_ficheros_error {
public:
    virtual const char* what() const noexcept = 0;
};

class archivo_inexistente : public arbol_ficheros_error {
public:
    const char* what() const noexcept override {
        return "Element doesn't exist";
    }
};

class nombre_repetido : public arbol_ficheros_error {
public:
    const char* what() const noexcept override {
        return "Element already exists";
    }
};

class peso_negativo : public arbol_ficheros_error {
public:
    const char* what() const noexcept override {
        return "Invalid parameter: negative size";
    }
};

class no_es_directorio : public arbol_ficheros_error {
public:
    const char* what() const noexcept override {
        return "It is not a directory";
    }
};

class nombre_no_valido : public arbol_ficheros_error {
public:
    const char* what() const noexcept override {
        return "Invalid name: it contains '/'";
    }
};