#include "NUMBER.hpp"

class Real : public Number{
    private:
        double value;
    public:
        //Constructor
        Real(double v);
    
        shared_ptr<Number> Addition(shared_ptr<Number> r) override;
        shared_ptr<Number> Subtration(shared_ptr<Number> r) override;
        shared_ptr<Number> Multiplication(shared_ptr<Number> r) override;
        shared_ptr<Number> Division(shared_ptr<Number> r) override;
        string toString() override;

        //GETTERS
        double getValue() const;

        //Destructor
        ~Real() override;
    };