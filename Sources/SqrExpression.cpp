#include "Headers/SqrExpression.h"

SqrExpression::SqrExpression(Expression* x) : UnaryExpression(x) {
    //
}

double SqrExpression::solve() {
    return x->solve() * x->solve();
}
