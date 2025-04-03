#include "NUMBER.hpp"

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
        string toString() override;
    };
    