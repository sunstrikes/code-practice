//
// Created by Sun,Minqi on 2021/5/27.
//
#include "InnerFactory.h"
#include "AbstractFactory.h"
#include "FuncionalFactory.h"
using namespace std;

int main() {
    //InnerFactory
    cout << "InnerFactory res:" << endl;
    auto p1 = Points::Factory::newNormal(2, 3);
    cout << "Normal: " << p1 << endl;
    auto p2 = Points::Factory::newPolar(2, 3);
    cout << "Polar: " << p2 << endl;

    //AbstractFactory
    cout << "\nAbstractFactory res:" << endl;
    AbstractFactory::Factory abs_factory;
    abs_factory.make_drink("tea");
    abs_factory.make_drink("coffee");

    //functionalFactory
    cout << "\nFunctionalFactory res:" << endl;
    Functional::FunctionalFactory func_factory;
    func_factory.make_drink("tea");
    func_factory.make_drink("coffee");
    return 0;
}