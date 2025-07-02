%option noyywrap
%option nounput noinput

%{
#include <iostream>
#include <string>
#include <cstring>
#include "parser.tab.h"
%}

%%

SetUnion                    { return BIN; }
ClearSet                    { return SINGLE; }
Delete                      { return SINGLE; }
Union                       { return BIN; }
interseccion|Interseccion|Intersection   { return BIN; }
ShowSets|ShowsSets          { return NONE; }
ShowSet                     { return SINGLE; }
Sets                        { return NONE; }
Set                         { return SET; }

":="                        { return IGUAL; }
"{"                         { return ABRECONJUNTO; }
"}"                         { return CIERRACONJUNTO; }
";"                         { return PUNTOYCOMA; }
","                         { return COMMA; }

[a-zA-Z_][a-zA-Z0-9_]*|[0-9]+ {
                               yylval.str = strdup(yytext);
                               return VARIABLE;
                             }

[ \t\r\n]+                  ;
"//".*                      ;
.                           { std::cerr << "Unrecognized: " << yytext << "\n"; return 0; }

%%
