# CalculadoraSemantica

## Módulo completo para crear y operar con conjuntos:

Set A := {a,b,c};
Set B := {b,c,d};
Sets;
ShowSets;
Union A,B;
Intersection A,B;
Concat A,B;
Set C := A Union B;
ShowSet C;
Clear A;
ShowSet A;
Delete B;
ShowSet B;
Sets;

### Estructura

CalculadoraConjuntos/
├── src/
│   ├── main.cpp
│   ├── token_stack.h/.cpp
│   ├── conjunto.h/.cpp
│   ├── gestorconjuntos.h/.cpp
│   └── semantica.h/.cpp
├── conjuntos.l
├── parser.y
└── README.md

### Compilar

flex conjuntos.l
bison -d parser.y
# Incluir las cabeceras dentro de `src`
g++ -std=c++17 -I src lex.yy.c parser.tab.c src/*.cpp -o calculadora -lfl
