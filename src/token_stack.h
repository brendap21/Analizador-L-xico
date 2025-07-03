#ifndef TOKEN_STACK_H
#define TOKEN_STACK_H

#include <vector>
#include <string>

// Pila simple para pasar lexemas del lexer al parser
class TokenStack {
private:
    std::vector<std::string> stack_;  // almacena los textos de los tokens
				      //  vector donde guardamos cada lexema (por ejemplo "Union", "Nom", "3xy").

public:
    // empuja token al final del vector (tope de la pila).
    void push(const std::string& tok);

    // si hay algo, saca y devuelve el último elemento (LIFO); si está vacía, devuelve "".
    std::string pop();

    // Devuelve cuántos tokens hay actualmente en la pila,  útil para bucles que extraen varios tokens.
    std::size_t size() const;
};

// declara que habrá una instancia global llamada gTokenStack usada tanto en el lexer como en el parser.
extern TokenStack gTokenStack;

#endif // TOKEN_STACK_H

