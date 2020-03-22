#include "Headers/TanExpression.h"
#include <math.h>

TanExpression::TanExpression(Expression* x) : UnaryExpression(x) {
    //
}

double TanExpression::solve() {
    return tan(x->solve());
}

