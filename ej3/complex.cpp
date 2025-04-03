#include "COMPLEX.hpp"
#include <iostream>

Complex::Complex(double r,double i) : Real(r), Imag(i) {}

shared_ptr<Number> Complex::Addition(shared_ptr<Number> r) {
    shared_ptr<Complex> n = dynamic_pointer_cast<Complex>(r);
    if (!n) throw invalid_argument("Addition: Tipo incompatible");

    if(n){
        double new_real = Real + n->Real;
        double new_imag = Imag + n->Imag;
        return make_shared<Complex>(new_real, new_imag);
    }
    return nullptr;
}

shared_ptr<Number> Complex::Subtration(shared_ptr<Number> r){
    shared_ptr<Complex> n = dynamic_pointer_cast<Complex>(r);
    if (!n) throw invalid_argument("Subtration: Tipo incompatible");

    if(n){
        double new_real = Real - n->Real;
        double new_imag = Imag - n->Imag;
        return make_shared<Complex>(new_real, new_imag);
    }
    return nullptr;
}

shared_ptr<Number> Complex::Multiplication(shared_ptr<Number> r){
    shared_ptr<Complex> n = dynamic_pointer_cast<Complex>(r);
    if (!n) throw invalid_argument("Multiplication: Tipo incompatible");

    if(n){
        double new_real = (Real*n->Real)-(Imag*n->Imag);
        double new_imag = (Real*n->Imag)+(Imag*n->Real);
        return make_shared<Complex>(new_real, new_imag);
    }
    return nullptr;
}


shared_ptr<Number> Complex::Division(shared_ptr<Number> r){
    shared_ptr<Complex> n = dynamic_pointer_cast<Complex>(r);
    if (!n) throw invalid_argument("Division: Tipo incompatible");
    double den = (n->Real*n->Real) +(n->Imag*n->Imag);
    if (den == 0) throw invalid_argument("Division por cero");

    if(n){
        double new_real = (Real*n->Real)-(Imag*n->Imag);
        double new_imag = (Imag*n->Real)-(Real*n->Imag);
        return make_shared<Complex>(new_real/den, new_imag/den);
    }
    return nullptr;
}

string Complex::toString(){
    return "("+ to_string(Real) + " + " + to_string(Imag) + "i)";
}
