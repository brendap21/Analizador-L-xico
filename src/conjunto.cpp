#include "conjunto.h"

Conjunto::Conjunto(const std::string& nombre) : nombre_(nombre) {}

void Conjunto::agregar(const std::string& e) {
    elems_.insert(e);
}

void Conjunto::vaciar() {
    elems_.clear();
}

void Conjunto::mostrar() const {
    std::cout << nombre_ << " := {";
    bool primera = true;
    for (auto const& e : elems_) {
        if (!primera) std::cout << ",";
        std::cout << e;
        primera = false;
    }
    std::cout << "}" << std::endl;
}

std::string Conjunto::getNombre() const { return nombre_; }
std::set<std::string> Conjunto::getElementos() const { return elems_; }

Conjunto Conjunto::Union(const Conjunto& A, const Conjunto& B, const std::string& nuevoNombre) {
    Conjunto r(nuevoNombre);
    r.elems_ = A.elems_;
    r.elems_.insert(B.elems_.begin(), B.elems_.end());
    return r;
}

Conjunto Conjunto::Interseccion(const Conjunto& A, const Conjunto& B, const std::string& nuevoNombre) {
    Conjunto r(nuevoNombre);
    for (auto const& e : A.elems_)
        if (B.elems_.count(e))
            r.elems_.insert(e);
    return r;
}

Conjunto Conjunto::Concat(const Conjunto& A, const Conjunto& B, const std::string& nuevoNombre) {
    Conjunto r(nuevoNombre);
    for (auto const& x : A.elems_)
        for (auto const& y : B.elems_)
            r.elems_.insert(x + y);
    return r;
}

