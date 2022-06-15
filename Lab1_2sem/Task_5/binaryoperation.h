#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H
#include <iostream>

#include "expression.h"
using namespace std;

class BinaryOperation : Expression
{
public:
    BinaryOperation(Expression const* left, char op, Expression const* right);
    ~BinaryOperation();
    double evaluate() const;

private:
    Expression const* left;
    Expression const* right;
    char op;
};

#endif // BINARYOPERATION_H
