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

Complex::Complex(double r,double i) : Real(r), Imag(i) {}

shared_ptr<Number> Complex::Addition(shared_ptr<Number> r) {
    shared_ptr<Complex> n = dynamic_pointer_cast<Complex>(r);

    if(n){
        double new_real = Real + n->Real;
        double new_imag = Imag + n->Imag;
        return make_shared<Complex>(new_real, new_imag);
    }
    return nullptr;
}

shared_ptr<Number> Complex::Subtration(shared_ptr<Number> r){
    shared_ptr<Complex> n = dynamic_pointer_cast<Complex>(r);

    if(n){
        double new_real = Real - n->Real;
        double new_imag = Imag - n->Imag;
        return make_shared<Complex>(new_real, new_imag);
    }
    return nullptr;
}

shared_ptr<Number> Complex::Multiplication(shared_ptr<Number> r){
    shared_ptr<Complex> n = dynamic_pointer_cast<Complex>(r);

    if(n){
        double new_real = (Real*n->Real)-(Imag*n->Imag);
        double new_imag = (Real*n->Imag)+(Imag*n->Real);
        return make_shared<Complex>(new_real, new_imag);
    }
    return nullptr;
}


shared_ptr<Number> Complex::Division(shared_ptr<Number> r){
    shared_ptr<Complex> n = dynamic_pointer_cast<Complex>(r);

    if(n){
        double new_real = (Real*n->Real)-(Imag*n->Imag);
        double new_imag = (Imag*n->Real)-(Real*n->Imag);
        double den = (Imag*Imag)+(n->Imag*n->Imag);
        return make_shared<Complex>(new_real/den, new_imag/den);
    }
    return nullptr;
}
