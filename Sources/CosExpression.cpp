#include "Headers/CosExpression.h"
#include <math.h>

CosExpression::CosExpression(Expression* x) : UnaryExpression(x) {
    //
}

double CosExpression::solve() {
    return cos(x->solve());
}
