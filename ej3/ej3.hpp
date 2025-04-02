#pragma once
#include <string>
#include <memory>
using namespace std;

class Number{
public:
    virtual shared_ptr<Number> Addition(shared_ptr<Number> n) = 0;
    virtual shared_ptr<Number> Subtration(shared_ptr<Number> n) = 0;
    virtual shared_ptr<Number> Multiplication(shared_ptr<Number> n) = 0;
    virtual shared_ptr<Number> Division(shared_ptr<Number> n) = 0;
    virtual string toString() =0;
    virtual ~Number() {};
};

class Integer : public Number{
private:
    int value;
public:
    Integer(int v);

    shared_ptr<Number> Addition(shared_ptr<Number> i) override;
    shared_ptr<Number> Subtration(shared_ptr<Number> i) override;
    shared_ptr<Number> Multiplication(shared_ptr<Number> i) override;
    shared_ptr<Number> Division(shared_ptr<Number> i) override;
};

class Real : public Number{
private:
    double value;
public:
    Real(double v);

    shared_ptr<Number> Addition(shared_ptr<Number> r) override;
    shared_ptr<Number> Subtration(shared_ptr<Number> r) override;
    shared_ptr<Number> Multiplication(shared_ptr<Number> r) override;
    shared_ptr<Number> Division(shared_ptr<Number> r) override;
};

class Complex : public Number{
private:
    double Real;
    double Imag;
public:
    Complex(double r , double i);

    shared_ptr<Number> Addition(shared_ptr<Number> c) override;
    shared_ptr<Number> Subtration(shared_ptr<Number> c) override;
    shared_ptr<Number> Multiplication(shared_ptr<Number> c) override;
    shared_ptr<Number> Division(shared_ptr<Number> c) override;
};
