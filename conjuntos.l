%{
#include <stdio.h>
%}

/* Expresiones Regulares */
DIGITO      [0-9]
LETRA       [a-zA-Z]
ID          {LETRA}({LETRA}|{DIGITO})*
ELEMENTO    {DIGITO}+|{LETRA}+|{DIGITO}{LETRA}+

%%

SetUnion           { printf("Union: %s\n", yytext); }        /* SetUnion X,Nom,L; */
ShowsSets          { printf("Show: %s\n", yytext); }         /* ShowsSets */
ClearSet           { printf("Clear: %s\n", yytext); }        /* ClearSet Nom; */
PrintSetNom        { printf("PrintSetNom: %s\n", yytext); }  /* PrintSetNom */
PrintSeA           { printf("PrintSeA: %s\n", yytext); }     /* PrintSeA */
interseccion|Interseccion { printf("Interseccion: %s\n", yytext); }  /* Interseccion */
Union              { printf("Union: %s\n", yytext); }        /* Union Nom,L; */
Sets               { printf("Sets: %s\n", yytext); }         /* Sets */
Set                { printf("Definir set: %s\n", yytext); }  /* Set Nom := {a,b,c}; */
Delete             { printf("Delete: %s\n", yytext); }       /* Delete Nom; */

">>"               { printf(">>: %s\n", yytext); }           /* símbolo de consola */
":="               { printf("Igual: %s\n", yytext); }        /* asignación */
"{"                { printf("Abre Conjunto: %s\n", yytext); }
"}"                { printf("Cierra Conjunto: %s\n", yytext); }
";"                { printf("Punto y Coma: %s\n", yytext); }
","                { printf("Comma: %s\n", yytext); }

{ID}               { printf("Variable: %s\n", yytext); }     /* Nombres de conjunto o variable */
{ELEMENTO}         { printf("Elemento: %s\n", yytext); }     /* Elementos como 3xy, abc, 123 */

"//".*             {/* Ignora comentarios estilo línea */}
[ \t\n]+           {/* Ignora espacios, tabs, saltos de línea */}

.                  { printf("Unrecognized: %s\n", yytext); } /* Todo lo no reconocido */

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Por favor, ingresa el código:\n\n");
    yylex();
    return 0;
}
