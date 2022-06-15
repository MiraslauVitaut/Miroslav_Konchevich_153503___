#include "binaryoperation.h"

BinaryOperation::BinaryOperation(Expression const* left, char op, Expression const* right) :
    left(left), right(right), op(op)
{

}

BinaryOperation::~BinaryOperation()
{
    delete left;
    left = nullptr;

    delete right;
    right = nullptr;
}

double BinaryOperation::evaluate() const {
    if (op == '+')
        return (left->evaluate() + right->evaluate());
    else if (op == '-')
        return (left->evaluate() - right->evaluate());
    else if (op == '*')
        return (left->evaluate() * right->evaluate());
    else if (op == '/')
        return (left->evaluate() / right->evaluate());
    else
        cout << "No match Operand!" << endl;
}
