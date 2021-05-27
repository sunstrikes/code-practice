//
// Created by Sun,Minqi on 2021/5/27.
//

#ifndef TEST_COMPOSITEBUILDER_H
#define TEST_COMPOSITEBUILDER_H
#include "../util.h"
class ActualBuilder;
class Person {
public:
// address
    std::string street_address, post_code;

// employment
    std::string company_name;
    int annual_income = 0;

    Person() = default;
    friend class ActualBuilder;
    static ActualBuilder create();
    friend std::ostream& operator<<(std::ostream& os, Person& obj);
};

class LiveBuilder;
class WorkBuilder;
class BuilderBase{
protected:
    Person& person;  //使用引用避免两个子类builder继承导致复制两个person
    explicit BuilderBase(Person& person): person(person) {}

public:
    operator Person() {
        return std::move(person);
    }
    LiveBuilder lives() const;
    WorkBuilder works() const;
};

class ActualBuilder: public BuilderBase{
    Person person;
public:
    explicit ActualBuilder(): BuilderBase(person) {}
};


class LiveBuilder: public BuilderBase{
    typedef LiveBuilder self;
public:
    explicit LiveBuilder(Person& p): BuilderBase(p) {}
    self& address(const std::string& address) {
        person.street_address = address;
        return *this;
    }
    self& post_code(const std::string& post_code) {
        person.post_code = post_code;
        return *this;
    }
};

class WorkBuilder: public BuilderBase{
    typedef WorkBuilder self;
public:
    explicit WorkBuilder(Person& p): BuilderBase(p) {}
    self& company(const std::string& company) {
        person.company_name = company;
        return *this;
    }
    self& income(const int income) {
        person.annual_income = income;
        return *this;
    }
};

#endif //TEST_COMPOSITEBUILDER_H
