#ifndef TOKEN_STACK_H
#define TOKEN_STACK_H

#include <vector>
#include <string>

// Pila simple para pasar lexemas del lexer al parser
class TokenStack {
private:
    std::vector<std::string> stack_;
public:
    // Inserta un token al tope
    void push(const std::string& tok);
    // Saca y retorna el token del tope (o "" si está vacía)
    std::string pop();
    // Cuántos tokens hay en la pila
    std::size_t size() const;
};

// Instancia global accesible desde parser y lexer
extern TokenStack gTokenStack;

#endif // TOKEN_STACK_H

