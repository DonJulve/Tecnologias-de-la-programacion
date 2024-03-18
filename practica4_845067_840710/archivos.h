/**
 * Autor: Alejandro Benedi Andrés   Nip: 843826 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentran todos los
 *       la implementacion de la clase padre Archivos
 *        y de las 3 clases hijas (Directorio, Fichero, Enlace)
**/

#pragma once
#include <string>
#include <iomanip>
#include <map>
#include <iostream>
#include <memory>
#include <sstream>
#include <stack>

class Archivos {
protected:
    std::string _nombre;
    int _peso;

public:

    Archivos(std::string nombre, int peso) : _nombre(nombre), _peso(peso) { };

    ~Archivos(){};

    /**
     * Devuelve el peso del archivo.
     * Las clase hija "Enlace" sobreescribe esta funcion para devolver el peso del archivo al que apunta.
     * @return peso del archivo
     */
    virtual int peso(){
        return _peso;
    }

    /**
     * Devuelve el nombre del archivo.
     * @return nombre del archivo
    */
    std::string nombre(){
        return _nombre;
    }
};

class Directorio : public Archivos {
protected:
    std::map<std::string, std::shared_ptr<Archivos>> nodos; // Aqui se guardan todos los archivos del directorio (Directorio, Archivo, Enlace)

public:

    Directorio(std::string nombre, std::shared_ptr<Archivos> padre) : Archivos(nombre, 0) {
        nodos[".."] = padre;    // Por cada directorio se crea un "enlace" al directorio padre
    }

    /**
     * Actualiza el peso de todos los directorios padres y lo guarda en la variable <peso> de cada directorio
     * Esta funcion sera util para actualizar los pesos despues de crear o destruir un tipo de archivo.
     */
   void actualizar_pesos(){
        int peso_directorio = 0;
        for (auto const& i : this->nodos){
            if (i.second != nullptr and i.first != "." and i.first != ".."){
                peso_directorio += i.second->peso();
            }
        }
        this->_peso = peso_directorio;

        std::shared_ptr<Directorio> padre = std::dynamic_pointer_cast<Directorio>(existe(".."));
        if(padre != nullptr){
            padre->actualizar_pesos();
        }
    }
    
    /*
    int peso() override {
        int peso_directorio = 0;
        for (auto const& i : this->nodos){
            if (i.second != nullptr and i.first != "." and i.first != ".."){
                peso_directorio += i.second->peso();
            }
        }
        return peso_directorio;
    }
    */
    
   /**
    * Añade un archivo (enlace, directorio o fichero) al directorio actual (<ruta_actual>)
    * Tras ello se actualiza el peso de todos los directorios padres teniendo en cuenta el nuevo archivo creado
    * @param path_archivo: Puntero al archivo a añadir
   */
    void aniadir_archivo(std::shared_ptr<Archivos> path_archivo){
        nodos[path_archivo->nombre()] = path_archivo;       // Se añade al diccionario del directorio actual
        actualizar_pesos();                                 // Actualiza el peso de todos los directorios padres
    }
    
    /**
     * Muestra los archivos del directorio actual
     * @param con_peso: Si es true, muestra el peso de cada archivo
     * @return: Devuelve un string con los archivos del directorio actual y su peso (si se ha indicado)
     */
    std::string mostrar_archivos(bool con_peso){
        std::stringstream output;
        for (auto const& i : this->nodos){      // Se rrecorre el diccionario de archivos del directorio actual
            if ( i.second != nullptr and i.first != "." and i.first != ".."){
                output << std::setw(20) << std::left << i.first;
                if (con_peso){
                    output << std::setw(20) << std::left << i.second->peso();
                }
                output << std::endl;
            }
        }
        return output.str();
    }

    /**
     * Busca un archivo en el directorio actual
     * @param nombre_buscar: Nombre del archivo a buscar
     * @return: Devuelve un puntero al archivo buscado o un puntero nulo si no se encuentra
     */
    std::shared_ptr<Archivos> existe(std::string nombre_buscar){
        auto res = nodos.find(nombre_buscar);   // La funcion fin devuelve un iterador. Si no se encuentra el iterador quedara apuntando a nodos.end()
        if (res != nodos.end()){                // Si se encuentra el archivo
            return res->second;
        }
        else {
            return nullptr;
        }
    }

    /**
     * Añade un "enlace" al directorio actual, para poder llamarse a si mismo
     * @param puntero: Puntero al directorio actual
    */
    void aniadir_referencia(std::shared_ptr<Archivos> puntero){
        nodos["."] = puntero;
    }

    /**
     * Elimina archivo del directorio actual (<ruta_actual>)
     * Posteriormete actualiza pesos de los directorios padres
     * @param nombre: Nombre del archivo a eliminar
    */
    void elimimar(std::string nombre){
        nodos.erase(nombre);        // Elimina el archivo del diccionario
        actualizar_pesos();
    }
}; 

class Fichero : public Archivos {
public:

    Fichero(std::string nombre, int peso) : Archivos(nombre, peso) {}
    
    /**
     * Edita el peso del fichero
     * @param nuevo_peso: Nuevo peso del fichero
    */
    void editar(int nuevo_peso){
        this->_peso = nuevo_peso;
    }
    
}; 

class Enlace : public Archivos {
protected:

    std::shared_ptr<Archivos> archivo_apuntado; // Puntero al archivo

public:

    Enlace(std::string nombre, std::shared_ptr<Archivos> puntero) : Archivos(nombre, 0), archivo_apuntado(puntero) {}
    
    /**
     * Devuelve el peso del archivo apuntado
     * @return: Devuelve el peso del archivo apuntado
    */
    int peso() override {
        return archivo_apuntado->peso();
    }

    /**
     * Devuelve el puntero del archivo al que apunta
     * @return: Devuelve el puntero del archivo al que apunta
    */
    std::shared_ptr<Archivos> link() {
        return archivo_apuntado;
    }

}; 
