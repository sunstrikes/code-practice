//
// Created by Sun,Minqi on 2021/6/1.
//

#pragma once
#include "util.h"
namespace composite {

    struct Neuron{
        std::vector<Neuron*> in{}, out{};
        int _id;
        Neuron() {
            static int id = 1;
            _id = id++;
        }
        //如果这么实现特化, 只能完成neuron和neuron直接的链接, 无法实现和layer的链接
        template<class T>
        void connect_to(T& other) {
            for(Neuron& to: other) {
                //如果是neuron, 只返回一个, 如果是layer进行遍历
                out.emplace_back(&to);
                to.in.emplace_back(this);
            }
        }
        Neuron* begin() {return this;}
        Neuron* end() {return this + 1;}
        friend std::ostream& operator<<(std::ostream& os, const Neuron& obj){
            for (Neuron* n : obj.in) {
                os << n->_id << "\t-->\t[" << obj._id << "]" << std::endl;
            }

            for (Neuron* n : obj.out) {
                os << "[" << obj._id << "]\t-->\t" << n->_id << std::endl;
            }
            return os;
        }
    };

struct Layer: public std::vector<Neuron> {
        explicit Layer(int count) {
            while(count-- > 0) {
                emplace_back(Neuron{});
            }
        }
        //如果这么实现特化, 只能完成neuron和neuron直接的链接, 无法实现和layer的链接
        template<class T>
        void connect_to(T& other) {
            for(Neuron& from: *this) {
                for (Neuron &to: other) {
                    //如果是neuron, 只返回一个, 如果是layer进行遍历
                    from.out.emplace_back(&to);
                    to.in.emplace_back(&from);
                }
            }
        }
        friend std::ostream& operator<<(std::ostream& os, const Layer& obj) {
            for (const Neuron& neu: obj) {
                os << neu;
            }
            return os;
        }
    };
}