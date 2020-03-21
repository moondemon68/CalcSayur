#include "SqrtExpression.h"
#include <math.h>

SqrtExpression::SqrtExpression(Expression* x) : UnaryExpression(x) {
    //
}

double SqrtExpression::solve() {
    try {
        if (x->solve() < 0) {
            QString err = "Value Error";
            throw err;
        }
    } catch (QString error) {
        QErrorMessage* E = new QErrorMessage();
        E->showMessage(error);
    }
    
    return sqrt(x->solve());
}
