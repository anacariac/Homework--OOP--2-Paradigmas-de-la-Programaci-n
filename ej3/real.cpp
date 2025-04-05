#include "INTEGER.hpp"
#include "REAL.hpp"
#include "COMPLEX.hpp"
#include <iostream>

Real::Real(double v) : value(v) {}

shared_ptr<Number> Real::Addition(shared_ptr<Number> other) {
    if (auto r = dynamic_pointer_cast<Real>(other))
        return make_shared<Real>(value + r->value);
    else if (auto i = dynamic_pointer_cast<Integer>(other))
        return make_shared<Real>(value + i->getValue());
    else if (auto c = dynamic_pointer_cast<Complex>(other))
        return make_shared<Complex>(value + c->getReal(), c->getImag());
    throw invalid_argument("Addition: Tipo incompatible");
}

shared_ptr<Number> Real::Subtration(shared_ptr<Number> other) {
    if (auto r = dynamic_pointer_cast<Real>(other))
        return make_shared<Real>(value - r->value);
    else if (auto i = dynamic_pointer_cast<Integer>(other))
        return make_shared<Real>(value - i->getValue());
    else if (auto c = dynamic_pointer_cast<Complex>(other))
        return make_shared<Complex>(value - c->getReal(), -c->getImag());
    throw invalid_argument("Subtration: Tipo incompatible");
}

shared_ptr<Number> Real::Multiplication(shared_ptr<Number> other) {
    if (auto r = dynamic_pointer_cast<Real>(other))
        return make_shared<Real>(value * r->value);
    else if (auto i = dynamic_pointer_cast<Integer>(other))
        return make_shared<Real>(value * i->getValue());
    else if (auto c = dynamic_pointer_cast<Complex>(other))
        return make_shared<Complex>(value * c->getReal(), value * c->getImag());
    throw invalid_argument("Multiplication: Tipo incompatible");
}

shared_ptr<Number> Real::Division(shared_ptr<Number> other) {
    if (auto r = dynamic_pointer_cast<Real>(other))
        return make_shared<Real>(value / r->value);
    else if (auto i = dynamic_pointer_cast<Integer>(other))
        return make_shared<Real>(value / i->getValue());
    else if (auto c = dynamic_pointer_cast<Complex>(i)) {
        double denom = c->getReal()*c->getReal() + c->getImag()*c->getImag();
        if (denom == 0) throw invalid_argument("División por cero complejo");
        double real = value * c->getReal() / denom;
        double imag = -value * c->getImag() / denom;
        return make_shared<Complex>(real, imag);
    }
    throw invalid_argument("Division: Tipo incompatible");
}

string Real::toString(){
    return to_string(value);
}

double Real::getValue() const { return value; }

Real::~Real() {};