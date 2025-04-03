#include "REAL.hpp"
#include <iostream>

Real::Real(double v) : value(v) {}

shared_ptr<Number> Real::Addition(shared_ptr<Number> r) {
    shared_ptr<Real> n = dynamic_pointer_cast<Real>(r);
    if (!n) throw invalid_argument("Addition: Tipo incompatible");

    if(n){
        return make_shared<Real>(value + n->value);
    }
    return nullptr;
}

shared_ptr<Number> Real::Subtration(shared_ptr<Number> r){
    shared_ptr<Real> n = dynamic_pointer_cast<Real>(r);
    if (!n) throw invalid_argument("Subtration: Tipo incompatible");

    if(n){
        return make_shared<Real>(value - n->value);
    }
    return nullptr;
}

shared_ptr<Number> Real::Multiplication(shared_ptr<Number> r){
    shared_ptr<Real> n = dynamic_pointer_cast<Real>(r);
    if (!n) throw invalid_argument("Multiplication: Tipo incompatible");

    if(n){
        return make_shared<Real>(value * n->value);
    }
    return nullptr;
}

shared_ptr<Number> Real::Division(shared_ptr<Number> r){
    shared_ptr<Real> n = dynamic_pointer_cast<Real>(r);
    if (!n) throw invalid_argument("Division: Tipo incompatible");

    if(n && n!=0){
        return make_shared<Real>(value / n->value);
    }
    return nullptr;
}

string Real::toString(){
    return to_string(value);
}