# CalculadoraSemantica

Módulo completo para crear y operar con conjuntos:

- **Set X := {a,b,c};**
- **Sets;** / **ShowSets;**
- **ShowSet X;**
- **Union A, B;**
- **Intersection A, B;**
- **Concat A, B;**
- **Set Y := A Union B;**
- **Set Z := A Concat B;**
- **Clear X;**
- **Delete X;**

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

```bash
flex conjuntos.l
bison -d parser.y
# Incluir las cabeceras dentro de `src`
g++ -std=c++17 -I src lex.yy.c parser.tab.c src/*.cpp -o calculadora -lfl
```
