//
// Created by Sun,Minqi on 2021/5/27.
//

#include "CompositeBuilder.h"
ActualBuilder Person::create() {
    return ActualBuilder();
}

std::ostream &operator<<(std::ostream &os, Person &obj) {
    return os
            << "street_address: " << obj.street_address
            << " post_code: " << obj.post_code
            << " company_name: " << obj.company_name
            << " annual_income: " << obj.annual_income;
}

LiveBuilder BuilderBase::lives() const {
    return LiveBuilder(person);
}

WorkBuilder BuilderBase::works() const {
    return WorkBuilder(person);
}