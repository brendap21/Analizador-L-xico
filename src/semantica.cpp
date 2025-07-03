#include "semantica.h"
#include "gestorconjuntos.h"
#include "conjunto.h"

// Instancia única del gestor: almacena todos los conjuntos por nombre
static GestorConjuntos gestor;

// 1) Crear un conjunto con lista de elementos
void crearConjunto(const std::string& N, const std::vector<std::string>& elems) {
    Conjunto c(N);
    for (auto const& e : elems)
        c.agregar(e);
    gestor.guardar(c);
}

// 2) Operaciones que muestran el resultado en pantalla
void hacerUnion(const std::string& A, const std::string& B) {
    auto r = Conjunto::Union(gestor.obtener(A), gestor.obtener(B), "tmp");
    r.mostrar();
}

void hacerInterseccion(const std::string& A, const std::string& B) {
    auto r = Conjunto::Interseccion(gestor.obtener(A), gestor.obtener(B), "tmp");
    r.mostrar();
}

void hacerConcat(const std::string& A, const std::string& B) {
    auto r = Conjunto::Concat(gestor.obtener(A), gestor.obtener(B), "tmp");
    r.mostrar();
}

// 3) Operaciones que guardan el resultado bajo un nuevo nombre
void guardarUnion(const std::string& N, const std::string& A, const std::string& B) {
    auto r = Conjunto::Union(gestor.obtener(A), gestor.obtener(B), N);
    gestor.guardar(r);
}

void guardarInterseccion(const std::string& N, const std::string& A, const std::string& B) {
    auto r = Conjunto::Interseccion(gestor.obtener(A), gestor.obtener(B), N);
    gestor.guardar(r);
}

void guardarConcat(const std::string& N, const std::string& A, const std::string& B) {
    auto r = Conjunto::Concat(gestor.obtener(A), gestor.obtener(B), N);
    gestor.guardar(r);
}

// 4) Modificación y consulta directa vía gestor
void vaciarConjunto(const std::string& N) {
    gestor.vaciar(N);
}

void eliminarConjunto(const std::string& N) {
    gestor.eliminar(N);
}

void listarConjuntos() {
    gestor.listar();
}

void mostrarTodos() {
    gestor.mostrarTodos();
}

void mostrarConjunto(const std::string& N) {
    gestor.mostrarUno(N);
}

