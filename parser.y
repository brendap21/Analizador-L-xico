%{
#include "semantica.h"
#include "token_stack.h"
#include <iostream>
extern TokenStack gTokenStack;

void yyerror(const char *s) {
    std::cerr << "Syntax error: " << s << std::endl;
}
%}

%token VAR
%token CMD_SET CMD_NONE CMD_MONO CMD_BIN
%token ASSIGN SMC OPENKEY CLOSEKEY COLON

%%

program:
    /* vacío */
  | program statement
  ;

statement:
    decl_stmt
  | op0_stmt
  | op1_stmt
  | op2_stmt
  ;

op0_stmt:
    CMD_NONE SMC {
        std::string cmd = gTokenStack.pop();
        if (cmd=="ShowSets") mostrarTodos();
        else if(cmd=="Sets")  listarConjuntos();
    }
  ;

op1_stmt:
    CMD_MONO VAR SMC {
        std::string t = gTokenStack.pop();
        std::string cmd = gTokenStack.pop();
        if(cmd=="Clear")    vaciarConjunto(t);
        else if(cmd=="Delete") eliminarConjunto(t);
        else if(cmd=="ShowSet") mostrarConjunto(t);
    }
  ;

op2_stmt:
    VAR CMD_BIN VAR SMC {
        std::string B = gTokenStack.pop();
        std::string cmd = gTokenStack.pop();
        std::string A = gTokenStack.pop();
        if(cmd=="Union")        hacerUnion(A,B);
        else if(cmd=="Intersection") hacerInterseccion(A,B);
        else if(cmd=="Concat")  hacerConcat(A,B);
    }
  | CMD_BIN VAR COLON VAR SMC {
        std::string B = gTokenStack.pop();
        std::string A = gTokenStack.pop();
        std::string cmd = gTokenStack.pop();
        if(cmd=="Union")        hacerUnion(A,B);
        else if(cmd=="Intersection") hacerInterseccion(A,B);
        else if(cmd=="Concat")  hacerConcat(A,B);
    }
  ;

decl_stmt:
    CMD_SET VAR ASSIGN OPENKEY elements CLOSEKEY SMC {
        std::vector<std::string> elems;
        while(gTokenStack.size()>1)
            elems.push_back(gTokenStack.pop());
        std::string name = gTokenStack.pop();
        crearConjunto(name, elems);
    }
  | CMD_SET VAR ASSIGN VAR CMD_BIN VAR SMC {
        std::string B = gTokenStack.pop();
        std::string cmd = gTokenStack.pop();
        std::string A = gTokenStack.pop();
        std::string name = gTokenStack.pop();
        if(cmd=="Union")        guardarUnion(name,A,B);
        else if(cmd=="Intersection") guardarInterseccion(name,A,B);
        else if(cmd=="Concat")  guardarConcat(name,A,B);
    }
  | CMD_SET VAR ASSIGN CMD_BIN VAR COLON VAR SMC {
        std::string B = gTokenStack.pop();
        std::string A = gTokenStack.pop();
        std::string cmd = gTokenStack.pop();
        std::string name = gTokenStack.pop();
        if(cmd=="Union")        guardarUnion(name,A,B);
        else if(cmd=="Intersection") guardarInterseccion(name,A,B);
        else if(cmd=="Concat")  guardarConcat(name,A,B);
    }
  ;

elements:
    VAR
  | elements COLON VAR
  ;

%%

