# Analizador Léxico

## Entradas aceptadas

### Definición de conjuntos
```text
Set Nom := {a,b,cde,1,3xy};
Set L := {a,b,c};
```

### Mostrar conjuntos
```text
Sets;
ShowSets;    (también se acepta ShowsSets)
```

### Operaciones entre conjuntos
```text
Union Nom,L;
Nom interseccion L;
Interseccion Nom,L;   (también Intersectión en inglés)
Intersection Nom,L;
```

### Crear conjuntos nuevos con resultado de operación
```text
SetUnion X,Nom,L;
SetInterseccion Y,Nom,L;
```

### Vaciar o borrar conjuntos
```text
ClearSet Nom;
Delete Nom;
```

### Imprimir conjuntos específicos
```text
PrintSetNom;
PrintSeA;
```

### Símbolos reconocidos
```text
>>
:=
{ }
,
;
```

### Variables / Identificadores
```text
Nom
L
X
Y
```

### Elementos de conjuntos
```text
a
b
cde
3xy
```

## Compilación
1. Ejecuta `flex conjuntos.l` para generar `lex.yy.c`.
2. Ejecuta `bison -d parser.y` para generar `parser.tab.c` y `parser.tab.h`.
3. Compila todo con `g++ lex.yy.c parser.tab.c -o analizador -lfl`.
   Si el ejecutable `analizador` existente produce errores inesperados, vuelve a compilarlo siguiendo los pasos anteriores para asegurarte de que esté sincronizado con los archivos fuente.

## Ejemplo de ejecución
```text
Set Nom := {a,b,3xy};
Set L := {a,b,c};
Sets;
ShowSets;    (también ShowsSets)
Union Nom,L;
Nom interseccion L;
SetUnion X,Nom,L;
SetInterseccion Y,Nom,L;
ClearSet Nom;
PrintSetNom;
Delete Nom;
PrintSeA;
```
