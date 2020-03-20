#include "SqrtExpression.h"
#include <math.h>

SqrtExpression::SqrtExpression(Expression* x) : UnaryExpression(x) {
    //
}

double SqrtExpression::solve() {
    return sqrt(x->solve());
}
