#include "ej3.hpp"
#include <iostream>

Integer::Integer(int v) : value(v) {}

shared_ptr<Number> Integer::Addition(shared_ptr<Number> i) {
    shared_ptr<Integer> n = dynamic_pointer_cast<Integer>(i);

    if(n){
        return make_shared<Integer>(value + n->value);
    }
    return nullptr;
}

shared_ptr<Number> Integer::Subtration(shared_ptr<Number> i){
    shared_ptr<Integer> n = dynamic_pointer_cast<Integer>(i);

    if(n){
        return make_shared<Integer>(value - n->value);
    }
    return nullptr;
}

shared_ptr<Number> Integer::Multiplication(shared_ptr<Number> i){
    shared_ptr<Integer> n = dynamic_pointer_cast<Integer>(i);

    if(n){
        return make_shared<Integer>(value * n->value);
    }
    return nullptr;
}

shared_ptr<Number> Integer::Division(shared_ptr<Number> i){
    shared_ptr<Integer> n = dynamic_pointer_cast<Integer>(i);

    if(n && n!=0){
        return make_shared<Integer>(value / n->value);
    }
    return nullptr;
}

Real::Real(double v) : value(v) {}

shared_ptr<Number> Real::Addition(shared_ptr<Number> r) {
    shared_ptr<Real> n = dynamic_pointer_cast<Real>(r);

    if(n){
        return make_shared<Real>(value + n->value);
    }
    return nullptr;
}

shared_ptr<Number> Real::Subtration(shared_ptr<Number> r){
    shared_ptr<Real> n = dynamic_pointer_cast<Real>(r);

    if(n){
        return make_shared<Real>(value - n->value);
    }
    return nullptr;
}

shared_ptr<Number> Real::Multiplication(shared_ptr<Number> r){
    shared_ptr<Real> n = dynamic_pointer_cast<Real>(r);

    if(n){
        return make_shared<Real>(value * n->value);
    }
    return nullptr;
}

shared_ptr<Number> Real::Division(shared_ptr<Number> r){
    shared_ptr<Real> n = dynamic_pointer_cast<Real>(r);

    if(n && n!=0){
        return make_shared<Real>(value / n->value);
    }
    return nullptr;
}