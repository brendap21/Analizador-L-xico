#include "gestorconjuntos.h"
#include <iostream>

// 1) Crear un conjunto vacío con el nombre dado
void GestorConjuntos::crear(const std::string& nombre) {
    mapa_.emplace(nombre, Conjunto(nombre));
}

// 2) Vaciar un conjunto existente
void GestorConjuntos::vaciar(const std::string& nombre) {
    if (existe(nombre))
        mapa_.at(nombre).vaciar();
}

// 3) Eliminar definitivamente un conjunto
void GestorConjuntos::eliminar(const std::string& nombre) {
    mapa_.erase(nombre);
}

// 4) Guardar o actualizar un Conjunto ya construido
void GestorConjuntos::guardar(const Conjunto& c) {
    mapa_[c.getNombre()] = c;
}

// 5) Comprobar existencia de nombre en el mapa
bool GestorConjuntos::existe(const std::string& nombre) const {
    return mapa_.find(nombre) != mapa_.end();
}

// 6) Obtener copia del Conjunto (para leer o procesar)
Conjunto GestorConjuntos::obtener(const std::string& nombre) const {
    return mapa_.at(nombre);
}

// 7) Mostrar un conjunto específico, o notificar si no existe
void GestorConjuntos::mostrarUno(const std::string& nombre) const {
    if (existe(nombre))
        mapa_.at(nombre).mostrar();
    else
        std::cout << "Set " << nombre << " does not exist" << std::endl;
}

// 8) Listar nombres de todos los conjuntos, en una sola línea
void GestorConjuntos::listar() const {
    bool primero = true;
    for (auto const& p : mapa_) {
        if (!primero) std::cout << ",";
        std::cout << p.first;
        primero = false;
    }
    std::cout << std::endl;
}

// 9) Mostrar todos los conjuntos completos: nombre y contenido
void GestorConjuntos::mostrarTodos() const {
    for (auto const& p : mapa_)
        p.second.mostrar();
}

