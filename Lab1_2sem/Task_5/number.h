#ifndef NUMBER_H
#define NUMBER_H

#include "expression.h"

class Number : Expression
{

public:
    Number(double value);
    ~Number();
    double evaluate() const;

private:
    double value;
};

#endif // NUMBER_H
