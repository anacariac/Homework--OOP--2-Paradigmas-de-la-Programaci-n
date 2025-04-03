#include "INTEGER.hpp"
#include <iostream>

Integer::Integer(int v) : value(v) {}

shared_ptr<Number> Integer::Addition(shared_ptr<Number> i) {
    shared_ptr<Integer> n = dynamic_pointer_cast<Integer>(i);
    if (!n) throw invalid_argument("Addition: Tipo incompatible");

    if(n){
        return make_shared<Integer>(value + n->value);
    }
    return nullptr;
}

shared_ptr<Number> Integer::Subtration(shared_ptr<Number> i){
    shared_ptr<Integer> n = dynamic_pointer_cast<Integer>(i);
    if (!n) throw invalid_argument("Subtration: Tipo incompatible");

    if(n){
        return make_shared<Integer>(value - n->value);
    }
    return nullptr;
}

shared_ptr<Number> Integer::Multiplication(shared_ptr<Number> i){
    shared_ptr<Integer> n = dynamic_pointer_cast<Integer>(i);
    if (!n) throw invalid_argument("Multiplication: Tipo incompatible");

    if(n){
        return make_shared<Integer>(value * n->value);
    }
    return nullptr;
}

shared_ptr<Number> Integer::Division(shared_ptr<Number> i){
    shared_ptr<Integer> n = dynamic_pointer_cast<Integer>(i);
    if (!n) throw invalid_argument("Division: Tipo incompatible");

    if(n && n->value!=0){
        return make_shared<Integer>(value / n->value);
    }
    return nullptr;
}
string Integer::toString(){
    return to_string(value);
}
