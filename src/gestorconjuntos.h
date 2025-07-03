#ifndef GESTORCONJUNTOS_H
#define GESTORCONJUNTOS_H

#include "conjunto.h"
#include <map>
#include <string>

// Gestiona todos los Conjunto en memoria
class GestorConjuntos {
private:
    std::map<std::string, Conjunto> mapa_;
public:
    void crear(const std::string& nombre);
    void vaciar(const std::string& nombre);
    void eliminar(const std::string& nombre);
    void guardar(const Conjunto& c);

    bool existe(const std::string& nombre) const;
    Conjunto obtener(const std::string& nombre) const;

    void mostrarUno(const std::string& nombre) const;
    void listar() const;
    void mostrarTodos() const;
};

#endif // GESTORCONJUNTOS_H

