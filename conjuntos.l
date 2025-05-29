%{
#include <stdio.h>
%}

/*--------------------------------------------------------------------------------*/
/* DECLARACION DE EXPRESIONES REGULARES */
/*--------------------------------------------------------------------------------*/

DIGITO      [0-9]
LETRA       [a-zA-Z]

/* Empieza con una letra ({LETRA}). Puede tener letras o números después (({LETRA}|{DIGITO})*) */
/* Ejemplos válidos: Nom, abc123, Set1, X9. Se usa para reconocer nombres de variables o conjuntos. */
ID          {LETRA}({LETRA}|{DIGITO})*

/* Cualquier cosa que pueda ir dentro de un conjunto. */
/* Solo números: 123, Solo letras: abc, Número seguido de letras: 3xy, 85a */
/* Esta regla permite detectar los elementos de los conjuntos como {a,b,3xy} */
ELEMENTO    {DIGITO}+|{LETRA}+|{DIGITO}{LETRA}+

%%

/*--------------------------------------------------------------------------------*/
/* DECLARACION DE REGLAS LEXICAS */
/*--------------------------------------------------------------------------------*/

/*yytext es una variable automática que guarda el texto que se reconocio*/
/*Cada vez que detecta alguna palabra como SetUnion o PrintSetNom, imprime un mensaje indicando qué comando fue detectado.*/

/*Reconoce exactamente la palabra SetUnion.
Esta palabra se usa para hacer cosas como:
SetUnion X,Nom,L;
Acción: Imprime Union: SetUnion. Es un comando especial que crea un nuevo conjunto como unión de otros dos.*/
SetUnion           {printf("Union: %s\n", yytext);}

/*Reconoce el comando para mostrar todos los conjuntos existentes. Imprime Show: ShowsSets */
ShowsSets          {printf("Show: %s\n", yytext);}

/*Comando para vaciar el contenido de un conjunto, pero sin eliminar su nombre. Ejemplo: ClearSet Nom; Imprime Clear: ClearSet */
ClearSet           {printf("Clear: %s\n", yytext);}

/*Comando especIfico que intenta imprimir un conjunto llamado Nom. Imprime PrintSetNom: PrintSetNom */
PrintSetNom        {printf("PrintSetNom: %s\n", yytext);}

/*Comando especIIfico que intenta imprimir un conjunto llamado SeA. Imprime PrintSetNom: PrintSeA */
PrintSeA           {printf("PrintSeA: %s\n", yytext);}

/*Usa una alternativa (|) para aceptar minúsculas o mayúsculas. Detecta el comando para la intersección entre conjuntos; Imprime Interseccion: interseccion */
interseccion|Interseccion {printf("Interseccion: %s\n", yytext);}

/*Detecta la palabra Union (sin crear un nuevo conjunto). Imprime Union: Union. Ejemplo: Union Nom,L; */
Union              {printf("Union: %s\n", yytext);}

/*Comando para mostrar el listado actual de nombres de conjuntos. Imprime Sets: Sets */
Sets               {printf("Sets: %s\n", yytext);}

/*Detecta el uso de la palabra clave Set para definir un conjunto. Ejemplo: Set Nom := {a,b,c}; Imprime Definir set: Set */
Set                {printf("Definir set: %s\n", yytext);}

/*Borra por completo un conjunto y su nombre. Imprime Delete: Delete */
Delete             {printf("Delete: %s\n", yytext);}

/*--------------------------------------------------------------------------------*/
/* Simbolos especiales*/
/*--------------------------------------------------------------------------------*/

/*Cada vez que se encuentra un simbolo (como :=, {, ;, etc.), se imprime un mensaje.*/
/*Detecta el símbolo de salida (puede ser tipo consola). Imprime >>: >> */
">>"               {printf(">>: %s\n", yytext);}

/*Detecta el símbolo de asignacion. Ejemplo: Set Nom := {a,b}; Imprime Igual: := */
":="               {printf("Igual: %s\n", yytext);}

/*Detectan apertura y cierre de conjunto. Imprimen: Abre Conjunto: { y Cierra Conjunto: } */
"{"                {printf("Abre Conjunto: %s\n", yytext);}
"}"                {printf("Cierra Conjunto: %s\n", yytext);}

/*Detectan el final de una instrucción y separación de elementos en listas. Imprimen: Semicolon: ; y Coma: , */
";"                {printf("Punto y Coma: %s\n", yytext);}
","                {printf("Comma: %s\n", yytext);}


/*--------------------------------------------------------------------------------*/
/*Identificadores y elementos:*/
/*--------------------------------------------------------------------------------*/

/*Si reconoce una palabra como Nom, L, etc. → la considera una variable*/
/*Si reconoce algo como 3xy, 123, abc → lo trata como un elemento de conjunto*/

/*Usa la Regla ID de arriba, Reconoce cualquier nombre válido de conjunto o variable. */
{ID}               {printf("Variable: %s\n", yytext);}

/*Usa la regla Elemento de arriba, Detecta cosas como 3xy, abc, 123  */
{ELEMENTO}         {printf("Elemento: %s\n", yytext);}


"//".*             {/* Ignora los comentarios estilo // esto es comentario, no imprime nada. */}
[ \t\n]+           {/* Ignora todos los estapacios, tabs y saltos de linea */}


/*Cualquier otra cosa no reconocida:*/
/*Si algo no coincide con ninguna regla anterior, se imprime como desconocido.*/
.                  {printf("Unrecognized: %s\n", yytext);}

%%

/*yywrap() → evita que Flex busque otro archivo al final (es necesario por compatibilidad)*/

int yywrap() {
    return 1;
}

/*inicia el análisis léxico llamando a yylex(), que recorre el archivo línea por línea aplicando las reglas*/
int main() {
    yylex();
    return 0;
    printf("Por favor, ingresa el codigo."); 
}