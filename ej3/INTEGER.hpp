#include "NUMBER.hpp"

class Integer : public Number{
    private:
        int value;
    public:
        //Constructor
        Integer(int v);
    
        shared_ptr<Number> Addition(shared_ptr<Number> i) override;
        shared_ptr<Number> Subtration(shared_ptr<Number> i) override;
        shared_ptr<Number> Multiplication(shared_ptr<Number> i) override;
        shared_ptr<Number> Division(shared_ptr<Number> i) override;
        string toString() override;

        //GETTERS
        int getValue();

        //Destructor
        ~Integer() override;
    };