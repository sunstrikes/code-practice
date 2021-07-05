//
// Created by Sun,Minqi on 2021/7/5.
//

#pragma once
#include "../util.h"
namespace classic {
    struct SubtractionExpression;
    struct DoubleExpression;
    struct AdditionExpression;

    struct ExpressionVisitor {
        virtual void visit(DoubleExpression *de) = 0;

        virtual void visit(AdditionExpression *ae) = 0;

        virtual void visit(SubtractionExpression *se) = 0;
    };

    struct ExpressionPrinter : ExpressionVisitor {
        std::ostringstream oss;

        std::string str() const { return oss.str(); }

        void visit(DoubleExpression *de) override;

        void visit(AdditionExpression *ae) override;

        void visit(SubtractionExpression *se) override;
    };

    struct ExpressionEvaluator : ExpressionVisitor {
        double result{0};

        void visit(DoubleExpression *de) override;

        void visit(AdditionExpression *ae) override;

        void visit(SubtractionExpression *se) override;
    };

    struct Expression {
        virtual void accept(ExpressionVisitor *visitor) = 0;

        virtual ~Expression() = default;
    };

    struct DoubleExpression : Expression {
        double value;

        explicit DoubleExpression(const double value)
                : value{value} {}

        void accept(ExpressionVisitor *visitor) override {
            visitor->visit(this);
        }
    };

    struct AdditionExpression : Expression {
        Expression *left, *right;

        AdditionExpression(Expression *const left, Expression *const right)
                : left{left}, right{right} {}

        ~AdditionExpression() override {
            delete left;
            delete right;
        }

        void accept(ExpressionVisitor *visitor) override {
            visitor->visit(this);
        }
    };

    struct SubtractionExpression : Expression {
        Expression *left, *right;

        SubtractionExpression(Expression *const left, Expression *const right)
                : left{left}, right{right} {}

        ~SubtractionExpression() override {
            delete left;
            delete right;
        }

        void accept(ExpressionVisitor *visitor) override {
            visitor->visit(this);
        }
    };
}