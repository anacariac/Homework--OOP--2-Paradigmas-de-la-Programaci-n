#include "INTEGER.hpp"
#include "REAL.hpp"
#include "COMPLEX.hpp"
#include <iostream>

Complex::Complex(double r,double i) : real(r), imag(i) {}

shared_ptr<Number> Complex::Addition(shared_ptr<Number> other) {
    if (auto c = dynamic_pointer_cast<Complex>(other))
        return make_shared<Complex>(real+ c->real, imag + c->imag);
    else if (auto r = dynamic_pointer_cast<Real>(other))
        return make_shared<Complex>(real + r->getValue(), imag);
    else if (auto i = dynamic_pointer_cast<Integer>(other))
        return make_shared<Complex>(real + i->getValue(), imag);
    throw invalid_argument("Addition: Tipo incompatible");
}

shared_ptr<Number> Complex::Subtration(shared_ptr<Number> other) {
    if (auto c = dynamic_pointer_cast<Complex>(other))
        return make_shared<Complex>(real - c->real, imag - c->imag);
    else if (auto r = dynamic_pointer_cast<Real>(other))
        return make_shared<Complex>(real - r->getValue(), imag);
    else if (auto i = dynamic_pointer_cast<Integer>(other))
        return make_shared<Complex>(real - i->getValue(), imag);
    throw invalid_argument("Subtration: Tipo incompatible");
}

shared_ptr<Number> Complex::Multiplication(shared_ptr<Number> other) {
    if (auto c = dynamic_pointer_cast<Complex>(other))
        return make_shared<Complex>(real * c->real - imag * c->imag, real * c->imag + imag * c->real);
    else if (auto r = dynamic_pointer_cast<Real>(other))
        return make_shared<Complex>(real * r->getValue(), imag * r->getValue());
    else if (auto i = dynamic_pointer_cast<Integer>(other))
        return make_shared<Complex>(real * i->getValue(), imag * i->getValue());
    throw invalid_argument("Multiplication: Tipo incompatible");
}

shared_ptr<Number> Complex::Division(shared_ptr<Number> other) {
    if (auto c = dynamic_pointer_cast<Complex>(other)) {
        double a = real, b = imag;
        double c1 = c->real, d = c->imag;
        double denom = c1 * c1 + d * d;
        return make_shared<Complex>((a * c1 + b * d) / denom, (b * c1 - a * d) / denom);
    } else if (auto r = dynamic_pointer_cast<Real>(other)) {
        return make_shared<Complex>(real / r->getValue(), imag / r->getValue());
    } else if (auto i = dynamic_pointer_cast<Integer>(other)) {
        return make_shared<Complex>(real / i->getValue(), imag / i->getValue());
    }
    throw invalid_argument("Division: Tipo incompatible");
}

string Complex::toString(){
    return "("+ to_string(real) + " + " + to_string(imag) + "i)";
}

double Complex::getReal() const { return real; }
double Complex::getImag() const { return imag; }

Complex::~Complex() {};