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
interseccion|Interseccion   { return BIN; }
<<<<<<< HEAD
=======
ShowsSets                   { return NONE; }
>>>>>>> 605012f (Correction Compilation Errors)
ShowSets|ShowsSets          { return NONE; }
ShowSet                     { return SINGLE; }
Sets                        { return NONE; }
Set                         { return SET; }

":="                        { return IGUAL; }
"{"                         { return ABRECONJUNTO; }
"}"                         { return CIERRACONJUNTO; }
";"                         { return PUNTOYCOMA; }
","                         { return COMMA; }

<<<<<<< HEAD
[a-zA-Z0-9]+                 {
                               yylval.str = strdup(yytext);
                               return VARIABLE;
=======
[a-zA-Z][a-zA-Z0-9]*        {
[a-zA-Z0-9]+                 {
                               yylval.str = strdup(yytext);
                               return VARIABLE;
                            }
>>>>>>> 605012f (Correction Compilation Errors)
                             }

[ \t\r\n]+                  ;
"//".*                      ;
.                           { std::cerr << "Unrecognized: " << yytext << "\n"; return 0; }

%%
