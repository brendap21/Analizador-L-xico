#ifndef GESTORCONJUNTOS_H
#define GESTORCONJUNTOS_H

#include "conjunto.h"
#include <map>
#include <string>

// Gestiona todos los Conjunto en memoria
class GestorConjuntos {
private:
    std::map<std::string, Conjunto> mapa_;  
    // Mapa de nombre de conjunto → objeto Conjunto

public:
    // Crea un nuevo Conjunto vacío con ese nombre
    void crear(const std::string& nombre);

    // Vacía el contenido de un Conjunto existente
    void vaciar(const std::string& nombre);

    // Elimina por completo el Conjunto del almacén
    void eliminar(const std::string& nombre);

    // Inserta o reemplaza un Conjunto ya construido
    void guardar(const Conjunto& c);

    // Comprueba si existe un Conjunto con ese nombre
    bool existe(const std::string& nombre) const;

    // Recupera una copia del Conjunto (lanza excepción si no existe)
    Conjunto obtener(const std::string& nombre) const;

    // Imprime un único Conjunto (o mensaje de error si no existe)
    void mostrarUno(const std::string& nombre) const;

    // Lista solo los nombres de todos los conjuntos, separados por comas
    void listar() const;

    // Imprime todos los conjuntos (nombre + contenido) en orden de clave
    void mostrarTodos() const;
};

#endif // GESTORCONJUNTOS_H

