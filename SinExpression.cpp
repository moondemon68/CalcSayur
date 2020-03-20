#include "SinExpression.h"
#include <math.h>

SinExpression::SinExpression(Expression* x) : UnaryExpression(x) {
    //
}

double SinExpression::solve() {
    return sin(x->solve());
}
