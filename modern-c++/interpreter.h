//
// Created by Sun,Minqi on 2021/6/22.
//

#pragma once
#include "util.h"
namespace interpreter {
    struct Context{
        std::string _input;
        std::string _output;
    };
    class AbstractExpression{
    public:
        virtual void interpret(Context* context) = 0;
    };
    class TerminalExpression: public AbstractExpression{
    public:
        void interpret(Context* context) override {
            std::cout << "Interpret: " << context->_input << " Terminal To: " << context->_output << std::endl;
        }
    };
    class NonTerminalExpression: public AbstractExpression {
        AbstractExpression* _expression;
    public:
        explicit NonTerminalExpression(AbstractExpression* expression) {
            _expression = expression;
        }
        void interpret(Context* context) override {
            std::cout << "Interpret: " << context->_input << " NonTerminal To: " << context->_output << std::endl;
            _expression->interpret(context);
        }
    };
}
