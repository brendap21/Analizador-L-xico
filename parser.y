%{
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "parser.tab.h"

void yyerror(const char *s);
int yylex();
%}

%union {
    char* str;
}

%token <str> VARIABLE
%token NONE SINGLE BIN SET
%token IGUAL PUNTOYCOMA ABRECONJUNTO CIERRACONJUNTO COMMA

%start program

%%

program:
      /* al arrancar imprimimos el primer prompt */
    | program statement
    ;

statement:
      NONE PUNTOYCOMA
        { std::cout << "Declaracion none valida\n"; }
    | SINGLE VARIABLE PUNTOYCOMA
        { std::cout << "Declaracion single valida\n"; }
    | VARIABLE BIN VARIABLE PUNTOYCOMA
        { std::cout << "Infijo valido\n"; }
    | SET VARIABLE IGUAL ABRECONJUNTO elementos CIERRACONJUNTO PUNTOYCOMA
        { std::cout << "Sintaxis de la declaracion Valida\n"; }
    ;

elementos:
      VARIABLE
    | elementos COMMA VARIABLE
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error de Sintaxis: %s\n", s);
}

int main(int argc, char **argv) {
    printf("Por favor, ingresa el código:\n\n");  // <-- Agregado
    return yyparse();
}
