#include "DivideExpression.h"

DivideExpression::DivideExpression(Expression* x, Expression* y) : BinaryExpression(x, y) {
    //
}

double DivideExpression::solve() {
    try {
        if (y->solve() == 0) {
            throw "Division by zero";
        }
    } catch (QString error) {
        QErrorMessage* E = new QErrorMessage();
        E->showMessage(error);
    }
    return x->solve() / y->solve();
}
