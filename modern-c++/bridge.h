//
// Created by SunStriKE on 2018/5/1.
//

#ifndef MODERN_C_BRIDGE_H
#define MODERN_C_BRIDGE_H


#include <bits/shared_ptr.h>
#include <iostream>

class imp{
public:
    imp(){std::cout<<"imp()"<<std::endl;}
    ~imp(){std::cout<<"~imp()"<<std::endl;}
    void print(){std::cout<<"imp print"<<std::endl;}
};
class sample {
public:
    sample():_pimp(new imp){std::cout<<"sample()"<<std::endl;}
    ~sample(){
        std::cout<<"~sample()"<<std::endl;
    }
    void print(){
        _pimp->print();
    }
private:
    std::shared_ptr<imp> _pimp;
};


#endif //MODERN_C_BRIDGE_H
