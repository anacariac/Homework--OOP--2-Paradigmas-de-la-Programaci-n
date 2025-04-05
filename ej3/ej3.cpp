#include "INTEGER.hpp"
#include "REAL.hpp"
#include "COMPLEX.hpp"
#include <iostream>


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

    cout << "-----------------------------" << endl;
    cout << "Operaciones entre tipos distintos:" << endl;

    // Integer + Real
    auto mix1 = i1->Addition(r1);
    cout << "Integer + Real: " << mix1->toString() << endl;

    // Real * Complex
    auto mix2 = r1->Multiplication(c1);
    cout << "Real * Complex: " << mix2->toString() << endl;

    // Complex - Integer
    auto mix3 = c1->Subtration(i2);
    cout << "Complex - Integer: " << mix3->toString() << endl;

    // Real / Integer
    auto mix4 = r1->Division(i2);
    cout << "Real / Integer: " << mix4->toString() << endl;

    // Complex + Real
    auto mix5 = c1->Addition(r2);
    cout << "Complex + Real: " << mix5->toString() << endl;

    return 0;
}