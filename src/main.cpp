#include <iostream>
extern int yyparse();

int main() {
    std::cout << "Iniciando calculadora de conjuntos..." << std::endl;
    yyparse();
    return 0;
}

