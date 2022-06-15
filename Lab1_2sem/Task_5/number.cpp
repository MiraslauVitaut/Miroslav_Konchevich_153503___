#include "number.h"

Number::Number(double value) : value(value)
{

}

Number::~Number()
{

}

double Number::evaluate() const
{
    return value;
}
