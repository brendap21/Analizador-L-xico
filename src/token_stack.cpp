#include "token_stack.h"

// Aquí definimos la instancia global
TokenStack gTokenStack;

// Añade un token al final del vector
void TokenStack::push(const std::string& tok) {
    stack_.push_back(tok);
}

// Retira y devuelve el último token
std::string TokenStack::pop() {
    if (stack_.empty()) 
        return "";               // evita pop en vector vacío
    std::string top = stack_.back();
    stack_.pop_back();
    return top;
}

// Retorna el tamaño actual de la pila
std::size_t TokenStack::size() const {
    return stack_.size();
}

//¿Por qué es útil esta pila?
//Separación de responsabilidades: el lexer extrae texto y etiqueta tokens, pero no decide acciones semánticas. Solo anota el lexema en esta pila.

//El parser, al reconocer una regla completa, sabe cuántos tokens necesita (p. ej. 3 para A Union B;) y popea esas cadenas en el orden correcto para pasarlas a las funciones de semántica.

//Así no mezclas código de Flex con lógica de Bison ni con la lógica de C++ puro, manteniendo cada capa limpia y enfocada en su tarea.







