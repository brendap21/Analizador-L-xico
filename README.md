<<<<<<< HEAD
# CalculadoraSemantica
=======
<<<<<<< HEAD
# ANALIZADOR LÉXICO
>>>>>>> 2ea9472 (Calculator compilation files added)

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
│ ├── main.cpp
│ ├── token_stack.h/.cpp
│ ├── conjunto.h/.cpp
│ ├── gestorconjuntos.h/.cpp
│ └── semantica.h/.cpp
├── conjuntos.l
├── parser.y
└── README.md

### Compilar

<<<<<<< HEAD
=======
### Símbolos:
  ### También reconoce por separado los símbolos que pueden estar en las instrucciones:
  #### >>
  #### :=
  #### {, }
  #### ,
  #### ;
  
### Variables / Identificadores como:
  #### Nom  
  #### L  
  #### X  
  #### Y
  
### Elementos de conjuntos:
  #### a  
  #### b  
  #### cde  
  #### 3xy  

### PARA COMPILAR EL PROGRAMA:
1. Ejecuta `flex conjuntos.l` para generar `lex.yy.c`.
2. Ejecuta `bison -d parser.y` para generar `parser.tab.c` y `parser.tab.h`.
3. Compila todo con `g++ lex.yy.c parser.tab.c -o analizador -lfl`.
   Si el ejecutable `analizador` existente produce errores inesperados,
   vuelve a compilarlo siguiendo los pasos anteriores para asegurarte de
   que esté sincronizado con los archivos fuente.

### Luego escribe una entrada en el programa, por ejemplo: 

#### Set Nom := {a,b,3xy};
#### Set L := {a,b,c};
#### Sets;
#### ShowSets;
#### (también se acepta ShowsSets)
#### Union Nom,L;
#### Nom interseccion L;
#### SetUnion X,Nom,L;
#### SetInterseccion Y,Nom,L;
#### ClearSet Nom;
#### PrintSetNom;
#### Delete Nom;
#### PrintSeA;
=======
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
│ ├── main.cpp
│ ├── token_stack.h/.cpp
│ ├── conjunto.h/.cpp
│ ├── gestorconjuntos.h/.cpp
│ └── semantica.h/.cpp
├── conjuntos.l
├── parser.y
└── README.md

### Compilar

>>>>>>> 2ea9472 (Calculator compilation files added)
```bash
flex conjuntos.l
bison -d parser.y
g++ -std=c++17 lex.yy.c parser.tab.c src/*.cpp -o calculadora -lfl
<<<<<<< HEAD
=======
>>>>>>> dfdd3b9 (Calculator project logic functions added)
>>>>>>> 2ea9472 (Calculator compilation files added)
