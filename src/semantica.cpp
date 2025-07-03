#include "semantica.h"
#include "gestorconjuntos.h"
#include "conjunto.h"

static GestorConjuntos gestor;

void crearConjunto(const std::string& N, const std::vector<std::string>& elems) {
    Conjunto c(N);
    for (auto const& e : elems) c.agregar(e);
    gestor.guardar(c);
}

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

