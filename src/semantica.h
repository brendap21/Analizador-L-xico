#ifndef SEMANTICA_H
#define SEMANTICA_H

#include <vector>
#include <string>

// Declaración de yylex para el parser generado por bison
int yylex();

// Funciones que el parser invoca directamente:
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

// Compatibilidad con nombres usados en versiones anteriores del parser
inline void mostrarConjuntos()                                { mostrarTodos(); }
inline void realizarUnion(const std::string& A, const std::string& B)
                                                              { hacerUnion(A, B); }
inline void realizarInterseccion(const std::string& A, const std::string& B)
                                                              { hacerInterseccion(A, B); }
inline void realizarConcat(const std::string& A, const std::string& B)
                                                              { hacerConcat(A, B); }
inline void guardarResultadoUnion(const std::string& N, const std::string& A, const std::string& B)
                                                              { guardarUnion(N, A, B); }
inline void guardarResultadoInterseccion(const std::string& N, const std::string& A, const std::string& B)
                                                              { guardarInterseccion(N, A, B); }
inline void guardarResultadoConcat(const std::string& N, const std::string& A, const std::string& B)
                                                              { guardarConcat(N, A, B); }

#endif // SEMANTICA_H

