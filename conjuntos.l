%option noyywrap
%{
#include "parser.tab.h"
#include "token_stack.h"
#include <string>
#define PUSH_TOKEN(x) gTokenStack.push(std::string(x))
%}

%%
"Concat"        { PUSH_TOKEN(yytext); return CMD_BIN; }
"Union"         { PUSH_TOKEN(yytext); return CMD_BIN; }
"Intersection"  { PUSH_TOKEN(yytext); return CMD_BIN; }
"Clear"         { PUSH_TOKEN(yytext); return CMD_MONO; }
"Delete"        { PUSH_TOKEN(yytext); return CMD_MONO; }
"ShowSets"      { PUSH_TOKEN(yytext); return CMD_NONE; }
"ShowSet"       { PUSH_TOKEN(yytext); return CMD_MONO; }
"Sets"          { PUSH_TOKEN(yytext); return CMD_NONE; }
"Set"           { PUSH_TOKEN(yytext); return CMD_SET; }
":="            { return ASSIGN; }
";"             { return SMC; }
"{"             { return OPENKEY; }
"}"             { return CLOSEKEY; }
","             { return COLON; }
[a-zA-Z0-9]+    { PUSH_TOKEN(yytext); return VAR; }
<<<<<<< HEAD
[ \t\n]+        ;  /* ignora espacio */
.               { std::cerr<<"Unknown: "<<yytext<<"\n"; }
=======
[ \t\n]+        ;  /* Ignora espacios y tabulaciones */
.               { std::cerr << "Unknown token: " << yytext << std::endl; }
>>>>>>> 2ea9472 (Calculator compilation files added)
%%

