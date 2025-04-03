#include "INTEGER.hpp"
#include "REAL.hpp"
#include "COMPLEX.hpp"
#include <iostream>

/*
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
*/
int main(){
    // Prueba con Integer
    auto i1 = make_shared<Integer>(10);
    auto i2 = make_shared<Integer>(3);

    cout << "Integer:" << endl;
    cout << "Suma: " << i1->Addition(i2)->toString() << endl;
    cout << "Resta: " << i1->Subtration(i2)->toString() << endl;
    cout << "Multiplicación: " << i1->Multiplication(i2)->toString() << endl;
    cout << "División: " << i1->Division(i2)->toString() << endl;
    cout << "-----------------------------" << endl;

    // Prueba con Real
    auto r1 = make_shared<Real>(5.5);
    auto r2 = make_shared<Real>(2.2);

    cout << "Real:" << endl;
    cout << "Suma: " << r1->Addition(r2)->toString() << endl;
    cout << "Resta: " << r1->Subtration(r2)->toString() << endl;
    cout << "Multiplicación: " << r1->Multiplication(r2)->toString() << endl;
    cout << "División: " << r1->Division(r2)->toString() << endl;
    cout << "-----------------------------" << endl;

    // Prueba con Complex
    auto c1 = make_shared<Complex>(3, 2);
    auto c2 = make_shared<Complex>(1, 4);

    cout << "Complex:" << endl;
    cout << "Suma: " << c1->Addition(c2)->toString() << endl;
    cout << "Resta: " << c1->Subtration(c2)->toString() << endl;
    cout << "Multiplicación: " << c1->Multiplication(c2)->toString() << endl;
    cout << "División: " << c1->Division(c2)->toString() << endl;
    return 0;
}