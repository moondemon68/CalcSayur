#include "AddExpression.h"

AddExpression::AddExpression(Expression* x, Expression* y) : BinaryExpression(x, y) {
    //
}

double AddExpression::solve() {
    return x->solve() + y->solve();
}
