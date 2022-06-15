#include "expression.h"

bool comp_ptr(Expression const* left, Expression const* right) {
    return (*((int*)left) == *((int*)right));
}

