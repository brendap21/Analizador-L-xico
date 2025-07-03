#include <iostream>
extern int yyparse();

int main() {
    std::cout << "CALCULADORA DE CONJUNTOS..." << std::endl;
    yyparse();
    return 0;
}

