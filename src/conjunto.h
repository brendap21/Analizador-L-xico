#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <set>
#include <string>
#include <iostream>

// Clase que representa un conjunto nombrado de cadenas
class Conjunto {
private:
    std::string nombre_;
    std::set<std::string> elems_;
public:
    explicit Conjunto(const std::string& nombre);
    void agregar(const std::string& e);
    void vaciar();
    void mostrar() const;
    std::string getNombre() const;
    std::set<std::string> getElementos() const;

    static Conjunto Union(const Conjunto& A, const Conjunto& B, const std::string& nuevoNombre);
    static Conjunto Interseccion(const Conjunto& A, const Conjunto& B, const std::string& nuevoNombre);
    static Conjunto Concat(const Conjunto& A, const Conjunto& B, const std::string& nuevoNombre);
};

#endif // CONJUNTO_H

