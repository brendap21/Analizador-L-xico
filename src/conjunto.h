#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <set>
#include <string>
#include <iostream>

// Clase que representa un conjunto nombrado de cadenas
class Conjunto {
private:
    std::string nombre_;              // Nombre identificador del conjunto
    std::set<std::string> elems_;     // Contiene los elementos únicos

public:
    Conjunto() = default;             // Constructor por defecto (necesario para map::operator[])
    explicit Conjunto(const std::string& nombre);  // Construye un conjunto con nombre

    void agregar(const std::string& e);   // Inserta un elemento
    void vaciar();                         // Elimina todos los elementos
    void mostrar() const;                 // Imprime en formato "nombre := {e1,e2,...}"
    std::string getNombre() const;        // Devuelve el nombre
    std::set<std::string> getElementos() const;  // Devuelve copia del set interno

    // Operaciones de conjuntos que devuelven un nuevo Conjunto con el nombre dado:
    static Conjunto Union(const Conjunto& A, const Conjunto& B, const std::string& nuevoNombre);
    static Conjunto Interseccion(const Conjunto& A, const Conjunto& B, const std::string& nuevoNombre);
    static Conjunto Concat(const Conjunto& A, const Conjunto& B, const std::string& nuevoNombre);
};

#endif // CONJUNTO_H

