/**
 * Autor: Jorge Jaime Modrego       Nip: 845067 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentran todos la 
 *       implementacion de la clase Shell que hara 
 *       de interprete de comandos
**/

#pragma once

#include <string>
#include <iomanip>
#include <map>
#include <iostream>
#include <memory>
#include <list>
#include <string>

#include "archivos.h"
#include "arbol_ficheros_error.h"

class Shell{
protected:
    std::shared_ptr<Directorio> ruta_actual;    // Ruta actual del shell
    std::shared_ptr<Directorio> raiz;           // Ruta raiz del shell

public:

    Shell() {
        ruta_actual = std::make_shared<Directorio>("root", nullptr);    // Se crea el directorio raiz
        ruta_actual->aniadir_referencia(ruta_actual);                   // Se crea el enlace "." al directorio raiz, es decir asi mismo
        raiz = ruta_actual;
    }

    /**
     * Comprueba si el nombre del archivo es valido. Para que un nombre sea valido
     * no puede contener el caracter "/"
     * @param nombre: Nombre del archivo
     * @return: Devuelve true si el nombre es valido, false en caso contrario
    */
    bool comprobar_nombre(std::string nombre){
        return nombre.find('/') == nombre.npos;  // Find devuelve un iterador. Si no encuentra el caracter devuelve npos
    }

    /**
     * Comprueba si la ruta es valida. Para que una ruta sea valida el 
     * ultimo caracter no puede ser "/". Si no es valida, se quitara dicho caracter y devolvera 
     * resultante
     * @param path: Ruta a comprobar
     * @return: Devuelve la ruta sin el ultimo caracter si este es "/"
    */
    std::string comprobar_ruta(std::string path){
        size_t posicion = path.find_last_of('/');       // Busca el ultimo caracter "/" del "string"
        if(((path.size()-1) == posicion) && posicion != 0){
            return path.substr(0,posicion);
        }
        return path;
    }

    /**
     * Devuelve la ruta completa, en forma de string, desde la raiz hasta el directorio 
     * actual <ruta_actual>
     * @return: Devuelve la ruta completa desde la raiz hasta el directorio actual
    */
    std::string pwd() const {
        std::string path;
        std::shared_ptr<Directorio> padre = ruta_actual;
        while(padre != nullptr){
            if (padre->nombre() != "root")
                path = "/" + padre->nombre() + path;
            padre = std::dynamic_pointer_cast<Directorio>(padre->existe(".."));
        }
        return path;
    }

    /**
     * Divide la ruta en dos partes, la primera sera la ruta y la segunda el nombre del archivo 
     * con el que se quiere trabajar
     * @param path: Ruta a dividir
     * @param dir: Variable donde se guardara los directorios a los que hay que acceder antes
     *             Este parametro es de salida
     * @param archivo: Variable donde se guardara el nombre del archivo con el que se va a
     *                 a trabajar. Este parametro es de salida
    */
    void dividir_ruta(std::string path, std::string& dir, std::string& archivo){
        std::size_t ultima = path.find_last_of("/");    // Busca el ultimo caracter "/" del "string"
        if(ultima == path.npos){           // Si no encuentra el caracter "/" significa que no hay directorios a los que acceder anters
            archivo = path;                // El archivo sera el nombre del archivo que se quiere trabajar
            dir = "";
        }
        else if(ultima == 0){              // Si el ultimo caracter es "/" significa que se quiere acceder al directorio raiz
            archivo = path.substr(ultima+1);
            dir = "/";              
        }
        else{                                   // Si no es ninguno de los casos anteriores, se divide la ruta en dos partes
            archivo = path.substr(ultima+1);    // Este es el archivo con el que se quiere trabajar
            dir = path.substr(0, ultima);       // Estos son los directorios a los que hay que acceder antes para encontrar el archivo
        }
    }

    /**
     * Devuelve una lista con todos los archivos del directorio actual <ruta_actual>.
     * Esta lista se mostrara en forma de tabla con 2 columnas una para el nombre
     * @return Devueve una lista con todos los archivos del directorio actual
    */
    std::string ls() const {
        std::stringstream output;
        output << std::setw(20) << std::left << "Nombre";
        output << std::endl << "-------------------------------------" << std::endl;
        output << ruta_actual->mostrar_archivos(false);
        return output.str();
    }

    /**
     * Devuelve una lista con todos los archivos del directorio actual <ruta_actual> junto
     * con sus pesos correspondientes.
     * Esta lista se mostrara en forma de tabla con 2 columnas una para el nombre y otra 
     * para el peso
     * @return Devueve una lista con todos los archivos del directorio actual y sus pesos
    */
    std::string du() const {
        std::stringstream output;
        output << std::setw(20) << std::left << "Nombre";
        output << std::setw(20) << std::left << "Peso";
        output << std::endl << "-------------------------------------" << std::endl;
        output << ruta_actual->mostrar_archivos(true);
        return output.str();
    }

    /**
     * Comprueba si el fichero existe en el directorio actual <ruta_actual>. Si existe
     * se cambia el peso del fichero, si no existe se crea un nuevo fichero
     * Si el peso es negativo o si el nombre no es valido se lanzara una excepcion
     * @param name: Nombre del fichero
     * @param size: Peso del fichero nuevo o peso a cambiar del fichero existente
    */
    void vi(std::string name, int size) {

        if(!comprobar_nombre(name))         // Comprueba si el nombre es valido
            throw nombre_no_valido();

        if (size < 0)                       // Compueba si el peso es negativo
            throw peso_negativo();
        
        std::shared_ptr<Fichero> fichero;
        fichero = std::dynamic_pointer_cast<Fichero>(ruta_actual->existe(name)); // Se crea el fichero
        if ( fichero == nullptr){
            fichero = std::make_shared<Fichero>(name, size);
            ruta_actual->aniadir_archivo(fichero);  // Se aniade el fichero nuevo
        }
        else{
            fichero->editar(size);                  // Se edita el fichero existente
            ruta_actual->actualizar_pesos();
        }
    }

    /**
     * Crea un nuevo directorio en el directorio actual <ruta_actual>. Si el nombre del 
     * directorio no es valido o si ya existe un directorio con el mismo nombre se lanzara
     * una excepcion
     * @param name: Nombre del directorio
    */
    void mkdir(std::string name){
        if(!comprobar_nombre(name))                 // Comprueba si el nombre es valido
            throw nombre_no_valido();

        if (ruta_actual->existe(name) != nullptr)   // Comprueba si el nombre ya existe
            throw nombre_repetido();

        std::shared_ptr<Directorio> dir = std::make_shared<Directorio> (name, ruta_actual);
        dir->aniadir_referencia(dir);               // aniade el directorio actual la nueva carpeta
        ruta_actual->aniadir_archivo(dir);
    }

    /**
     * Cambia el direcorio actual <ruta_actual> por el directorio que se le pasa por parametro en forma
     * de ruta. Si el directorio de la ruta no existe o se intenta acceder a un fichero se lanzara una 
     * excepcion.
     * @param path: Ruta del nuevo directorio actual
    */
    void cd(std::string path){
        std::shared_ptr<Directorio> ruta_inicial = ruta_actual;    // Se guarda la ruta inicial para luego volver a ella si es necesario
        path = comprobar_ruta(path);                // Se comprueba si la ruta es valida.Si no lo es,se modifica para que lo sea
        if ( path != pwd()){
            std::stringstream path_stream;
            std::shared_ptr<Archivos> elemento;
            path_stream << path;
            std::string directorio;
            while(std::getline(path_stream, directorio, '/')){
                if (directorio == ""){              // Si al principio hay una barra significa que se quiere acceder al directorio raiz
                    ruta_actual = raiz;
                }
                else{
                    elemento = ruta_actual->existe(directorio);
                    if (std::dynamic_pointer_cast<Directorio>(elemento) != nullptr){        // Si se apunta a un directorio
                        ruta_actual = std::dynamic_pointer_cast<Directorio>(ruta_actual->existe(directorio));
                        if(ruta_actual == nullptr && directorio == ".."){   // Si se quiere acceder al directorio padre y y estas en el directorio raiz
                            ruta_actual = raiz;                             // La ruta a la que accedes es la raiz
                        }
                    }
                    else if (std::dynamic_pointer_cast<Enlace>(elemento) != nullptr){       // Si se apunta a un enlace
                        ruta_actual = std::dynamic_pointer_cast<Directorio>(std::dynamic_pointer_cast<Enlace>(ruta_actual->existe(directorio))->link());
                        if(ruta_actual == nullptr){                       // Si se quiere acceder al directorio padre y y estas en el directorio raiz
                            ruta_actual = raiz;
                        }
                    }
                    else if (std::dynamic_pointer_cast<Fichero>(elemento) != nullptr){      // Si se apunta a un fichero, no se puede acceder
                        ruta_actual = ruta_inicial;     // Se vuelve a la ruta inicial
                        throw no_es_directorio();
                    }
                    else if (elemento == nullptr && directorio != ".."){   // Si no existe el directorio y no se quiere acceder al directorio padre
                        ruta_actual = ruta_inicial;    // Se vuelve a la ruta inicial
                        throw archivo_inexistente();
                    }
                }
            }
        }
    }

    /**
     * Crea un enlace simbolico en el directorio actual <ruta_actual> que apunta al archivo que se le pasa
     * por parametro en forma de ruta. Si el archivo no existe o se lanzara
     * una excepcion
     * @param path: Ruta del archivo (Directorio, Fichero o Enlace) al que apuntara el enlace
     * @param name: Nombre del enlace
    */
    void ln(std::string path, std::string name){
        if(!comprobar_nombre(name))                     // Comprueba si el nombre es valido
            throw nombre_no_valido();
        
        if (ruta_actual->existe(name) != nullptr)       // Comprueba si el nombre ya existe
            throw nombre_repetido();

        path = comprobar_ruta(path);                                // Comprueba si la ruta es valida. Si no lo se cambia para que lo sea
        std::shared_ptr<Directorio> ruta_inicial = ruta_actual;     // Se guarda la ruta inicial para luego volver a ella
        std::string archivo_enlazado;
        std::string dir;
        dividir_ruta(path, dir, archivo_enlazado);                  // Se dividie la ruta en <dir> y <archivo_enlazado>
        cd(dir);                    // Se cambia al directorio donde se encuentra el <archivo_enlazado>
        std::shared_ptr<Archivos> puntero = ruta_actual->existe(archivo_enlazado);
        if (std::dynamic_pointer_cast<Directorio>(puntero) != nullptr){ // Si se apunta a un directorio
            if(puntero == nullptr && archivo_enlazado == (".."))        // Si se quiere enlazar al directorio padre y y estas en el directorio raiz
                puntero = raiz;                                         // El directorio al que se enlaza es la raiz
        }
        else if(std::dynamic_pointer_cast<Enlace>(puntero) != nullptr){ // Si se apunta a un enlace
            puntero = std::dynamic_pointer_cast<Enlace>(puntero)->link();
            if(puntero == nullptr)          // Si se quiere enlazar al directorio padre y y estas en el directorio raiz
                puntero = raiz;             // El directorio al que se enlaza es la raiz
        }
        else if (puntero == nullptr && archivo_enlazado != ".."){       // Si no se apunta a nada, es decir el archivo no existe
            ruta_actual = ruta_inicial;                                 // Se vuelve a la ruta inicial
            throw archivo_inexistente();
        }

        if(puntero == nullptr && archivo_enlazado == (".."))        // Si se quiere enlazar al directorio padre y y estas en el directorio raiz
                puntero = raiz;                                     // El directorio al que se enlaza es la raiz
        
        std::shared_ptr<Enlace> nuevo_enlace = std::make_shared<Enlace>(name, puntero);
        ruta_inicial->aniadir_archivo(nuevo_enlace);
        ruta_actual = ruta_inicial;         // Se vuelve a la ruta inicial

    }
    
    /**
     * Muestra el peso del archivo que se le pasa por parametro en forma de ruta. Si el archivo no 
     * existe se lanzara una excepcion
     * @param path: Ruta del archivo (Directorio, Fichero o Enlace)
     * @return peso del archivo
    */
    int stat(std::string path){
        path = comprobar_ruta(path);
        std::shared_ptr<Directorio> ruta_inicial = ruta_actual;
        std::string archivo_buscado;
        std::string dir;
        dividir_ruta(path, dir, archivo_buscado);       // Se dividie la ruta en directorio a acceder y en archivo a buscar
        cd(dir);            // Se accede a todos los directorios para llegar al archivo buscado
        std::shared_ptr<Archivos> puntero = ruta_actual->existe(archivo_buscado);
        ruta_actual = ruta_inicial;             // Se vuelve a la ruta inicial
        if(puntero != nullptr){                 // Comprueba si existe el archivo
            std::cout << "Peso" << std::endl;   // Muestra el peso del archivo
            std::cout << "-------------" << std::endl;
            return puntero->peso();
        }
        else {
            throw archivo_inexistente();
        }
    }

    /**
     * Borra el archivo (Directorio, Fichero o Enlace) que se le pasa por parametro en forma de ruta. 
     * Si el archivo no existe se lanzara una excepcion
     * @param path: Ruta del archivo (Directorio, Fichero o Enlace)
    */
    void rm(std::string path){
        path = comprobar_ruta(path);                // Comprueba si la ruta es valida. Si no lo, se modifica para que lo sea
        std::shared_ptr<Directorio> ruta_inicial = ruta_actual;
        std::string archivo_borrar;
        std::string dir;
        dividir_ruta(path, dir, archivo_borrar);    // Se dividie la ruta en directorio a acceder y en archivo a buscar 
        cd(dir);                                    // Se accede a todos los directorios para llegar al archivo buscado
        std::shared_ptr<Archivos> puntero = ruta_actual->existe(archivo_borrar);
        if(puntero != nullptr){                     // Comprueba si existe el archivo
            ruta_actual->elimimar(archivo_borrar);  // Se elimina el archivo
        }
        else {
            ruta_actual = ruta_inicial;             // Se vuelva a la ruta inicial
            throw archivo_inexistente();
        }
        ruta_actual = ruta_inicial;                 // Se vuelve a la ruta inicial
    }
};
