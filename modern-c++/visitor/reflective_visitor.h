//
// Created by Sun,Minqi on 2021/7/4.
//

#pragma once
#include "../util.h"
namespace visitor {
    struct Expression {
        virtual ~Expression() = default;
    };

    struct DoubleExpression : public Expression {
        double value;

        explicit DoubleExpression(const double value)
                : value{value} {}
    };

    struct AdditionExpression : Expression {
        Expression *left, *right;

        AdditionExpression(Expression *const left, Expression *const right)
                : left{left}, right{right} {}

        ~AdditionExpression() override {
            delete left;
            delete right;
        }
    };
    struct ExpressionPrinter{
        void print(Expression* exp_ptr) {
            if (auto ptr = dynamic_cast<DoubleExpression*>(exp_ptr)) {
                oss << ptr->value;
            } else if (auto ptr = dynamic_cast<AdditionExpression*>(exp_ptr)) {
                oss << "(";
                print(ptr->left);
                oss << "+";
                print(ptr->right);
                oss << ")";
            }
        }
        std::string str() {return oss.str();}
    private:
        std::ostringstream oss;
    };
}