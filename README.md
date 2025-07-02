# ANALIZADOR LÉXICO

## El presente analizador Léxico acepta el siguiente tipo de entradas: 

### Definición de conjuntos:
  #### Set Nom := {a,b,cde,1,3xy};
  #### Set L := {a,b,c};

### Mostrar conjuntos:
  #### Sets;
<<<<<<< HEAD
=======
  #### ShowsSets;
>>>>>>> 605012f (Correction Compilation Errors)
  #### ShowSets; (también se acepta ShowsSets)

### Operaciones entre conjuntos:
  #### Union Nom,L;
  #### Nom interseccion L;
  #### También acepta la variación con Interseccion (con mayúscula)
  #### Interseccion Nom,L;

### Crear conjuntos nuevos con resultado de operación:
  #### SetUnion X,Nom,L;
  #### SetInterseccion Y,Nom,L;
  
### Vaciar o borrar conjuntos:
  #### ClearSet Nom;
  #### Delete Nom;
### Imprimir conjuntos específicos:
  #### PrintSetNom;
  #### PrintSeA;

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

### Luego escribe una entrada en el programa, por ejemplo: 

#### Set Nom := {a,b,3xy};
#### Set L := {a,b,c};
#### Sets;
<<<<<<< HEAD
=======
#### ShowsSets;
>>>>>>> 605012f (Correction Compilation Errors)
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
