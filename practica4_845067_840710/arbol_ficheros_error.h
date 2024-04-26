/**
 * Autor: Jorge Jaime Modrego       Nip: 845067 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentran todos las
 *          excepciones que se pueden lanzar.
**/

#pragma once 

#include <cstring>
#include<exception>

// Clase abstracta
class arbol_ficheros_error {
public:
    virtual const char* what() const noexcept = 0;
};

// Clase para excepciones cuando un archivo no existe
class archivo_inexistente : public arbol_ficheros_error {
public:
    const char* what() const noexcept override {
        return "Element doesn't exist";
    }
};

// Clase para excepciones cuando un archivo ya existe
class nombre_repetido : public arbol_ficheros_error {
public:
    const char* what() const noexcept override {
        return "Element already exists";
    }
};

// Clase para excepciones cuando se intenta crear un archivo con un peso negativo
class peso_negativo : public arbol_ficheros_error {
public:
    const char* what() const noexcept override {
        return "Invalid parameter: negative size";
    }
};

// Clase para excepciones cuando se intenta acceder a un fichero en vez de un directorio 
class no_es_directorio : public arbol_ficheros_error {
public:
    const char* what() const noexcept override {
        return "It is not a directory";
    }
};

// Clase para excepciones cuando se intenta crear un archivo con un nombre no valido por poseer '/'
class nombre_no_valido : public arbol_ficheros_error {
public:
    const char* what() const noexcept override {
        return "Invalid name: it contains '/'";
    }
};