#include "gestorconjuntos.h"
#include <iostream>

void GestorConjuntos::crear(const std::string& nombre) {
    mapa_.emplace(nombre, Conjunto(nombre));
}

void GestorConjuntos::vaciar(const std::string& nombre) {
    if (existe(nombre)) mapa_.at(nombre).vaciar();
}

void GestorConjuntos::eliminar(const std::string& nombre) {
    mapa_.erase(nombre);
}

void GestorConjuntos::guardar(const Conjunto& c) {
    mapa_[c.getNombre()] = c;
}

bool GestorConjuntos::existe(const std::string& nombre) const {
    return mapa_.find(nombre) != mapa_.end();
}

Conjunto GestorConjuntos::obtener(const std::string& nombre) const {
    return mapa_.at(nombre);
}

void GestorConjuntos::mostrarUno(const std::string& nombre) const {
    if (existe(nombre)) mapa_.at(nombre).mostrar();
    else std::cout << "Set " << nombre << " does not exist" << std::endl;
}

void GestorConjuntos::listar() const {
    bool primero = true;
    for (auto const& p : mapa_) {
        if (!primero) std::cout << ",";
        std::cout << p.first;
        primero = false;
    }
    std::cout << std::endl;
}

void GestorConjuntos::mostrarTodos() const {
    for (auto const& p : mapa_)
        p.second.mostrar();
}

