#include "token_stack.h"

TokenStack gTokenStack;

void TokenStack::push(const std::string& tok) {
    stack_.push_back(tok);
}

std::string TokenStack::pop() {
    if (stack_.empty()) return "";
    std::string top = stack_.back();
    stack_.pop_back();
    return top;
}

std::size_t TokenStack::size() const {
    return stack_.size();
}

