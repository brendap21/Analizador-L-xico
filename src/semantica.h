#ifndef SEMANTICA_H
#define SEMANTICA_H

#include <vector>
#include <string>

// Funciones que el parser invoca
void crearConjunto(const std::string& N, const std::vector<std::string>& elems);
void hacerUnion(const std::string& A, const std::string& B);
void hacerInterseccion(const std::string& A, const std::string& B);
void hacerConcat(const std::string& A, const std::string& B);

void guardarUnion(const std::string& N, const std::string& A, const std::string& B);
void guardarInterseccion(const std::string& N, const std::string& A, const std::string& B);
void guardarConcat(const std::string& N, const std::string& A, const std::string& B);

void vaciarConjunto(const std::string& N);
void eliminarConjunto(const std::string& N);
void listarConjuntos();
void mostrarTodos();
void mostrarConjunto(const std::string& N);

#endif // SEMANTICA_H

