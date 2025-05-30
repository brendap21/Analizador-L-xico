# ANALIZADOR LEXICO

## El presente analizador Léxico Acepta el siguiente tipo de entradas: 

### Definición de conjuntos:
  #### Set Nom := {a,b,cde,1,3xy};
  #### Set L := {a,b,c};

### Mostrar conjuntos:
  #### Sets;
  #### ShowsSets;

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
#### Abre MSYS2 MINGW64 y abre la carpeta donde se ubica el archivo conjuntos.l 
#### Escribe: gcc lex.yy.c -o conjuntos.exe
#### Escribe: flex conjuntos.l
#### Escribe: ./conjuntos.exe

### Luego escribe una entrada en el programa, por ejemplo: 

#### Set Nom := {a,b,3xy};
#### Set L := {a,b,c};
#### Sets;
#### ShowsSets;
#### Union Nom,L;
#### Nom interseccion L;
#### SetUnion X,Nom,L;
#### SetInterseccion Y,Nom,L;
#### ClearSet Nom;
#### PrintSetNom;
#### Delete Nom;
#### PrintSeA;
