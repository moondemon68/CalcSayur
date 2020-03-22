#include "Headers/NegativeExpression.h"
#include <math.h>

NegativeExpression::NegativeExpression(Expression* x) : UnaryExpression(x) {
    //
}

double NegativeExpression::solve() {
    return -1 * x->solve();
}
