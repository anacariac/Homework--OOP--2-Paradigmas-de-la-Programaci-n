#pragma once
#include <string>
#include <memory>
using namespace std;

class Number{
    public:
        //Metodos virtuales puros a implementar
        virtual shared_ptr<Number> Addition(shared_ptr<Number> n) = 0;
        virtual shared_ptr<Number> Subtration(shared_ptr<Number> n) = 0;
        virtual shared_ptr<Number> Multiplication(shared_ptr<Number> n) = 0;
        virtual shared_ptr<Number> Division(shared_ptr<Number> n) = 0;
        virtual string toString() =0;

        //Destructor virtual
        virtual ~Number() {};
    };