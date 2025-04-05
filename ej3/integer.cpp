#include "INTEGER.hpp"
#include "REAL.hpp"
#include "COMPLEX.hpp"
#include <iostream>

Integer::Integer(int v) : value(v) {}

shared_ptr<Number> Integer::Addition(shared_ptr<Number> i) {
    if (auto n = dynamic_pointer_cast<Integer>(i)) {
        return make_shared<Integer>(value + n->value);
    } else if (auto r = dynamic_pointer_cast<Real>(i)) {
        return make_shared<Real>(value + r->getValue());
    } else if (auto c = dynamic_pointer_cast<Complex>(i)) {
        return make_shared<Complex>(value + c->getReal(), c->getImag());
    } else {
        throw invalid_argument("Addition: Tipo incompatible");
    }
}

shared_ptr<Number> Integer::Subtration(shared_ptr<Number> i){
    if (auto n = dynamic_pointer_cast<Integer>(i)) {
        return make_shared<Integer>(value - n->value);
    } else if (auto r = dynamic_pointer_cast<Real>(i)) {
        return make_shared<Real>(value - r->getValue());
    } else if (auto c = dynamic_pointer_cast<Complex>(i)) {
        return make_shared<Complex>(value - c->getReal(), -c->getImag());
    } else {
        throw invalid_argument("Subtraction: Tipo incompatible");
    }
}

shared_ptr<Number> Integer::Multiplication(shared_ptr<Number> i){
    if (auto n = dynamic_pointer_cast<Integer>(i)) {
        return make_shared<Integer>(value * n->value);
    } else if (auto r = dynamic_pointer_cast<Real>(i)) {
        return make_shared<Real>(value * r->getValue());
    } else if (auto c = dynamic_pointer_cast<Complex>(i)) {
        double real = value * c->getReal();
        double imag = value * c->getImag();
        return make_shared<Complex>(real, imag);
    } else {
        throw invalid_argument("Multiplication: Tipo incompatible");
    }
}

shared_ptr<Number> Integer::Division(shared_ptr<Number> i){
    if (auto n = dynamic_pointer_cast<Integer>(i)) {
        if (n->value == 0) throw invalid_argument("División por cero");
        return make_shared<Integer>(value / n->value);
    } else if (auto r = dynamic_pointer_cast<Real>(i)) {
        if (r->getValue() == 0.0) throw invalid_argument("División por cero");
        return make_shared<Real>(value / r->getValue());
    } else if (auto c = dynamic_pointer_cast<Complex>(i)) {
        double denom = c->getReal()*c->getReal() + c->getImag()*c->getImag();
        if (denom == 0) throw invalid_argument("División por cero complejo");
        double real = value * c->getReal() / denom;
        double imag = -value * c->getImag() / denom;
        return make_shared<Complex>(real, imag);
    } else {
        throw invalid_argument("Division: Tipo incompatible");
    }
}

string Integer::toString(){
    return to_string(value);
}

int Integer::getValue(){return value;}

Integer::~Integer() {};