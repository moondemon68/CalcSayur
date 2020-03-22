#ifndef ADDEXPRESSION_H
#define ADDEXPRESSION_H

#include "BinaryExpression.h"

class AddExpression : public BinaryExpression {
public:
    /**
     * Konstruktor untuk AddExpression.
     *
     * @param Pointer ekspresi x
     * @param Pointer ekspresi y
     */
    AddExpression(Expression* x, Expression* y);
    /**
     * Menyelesaikan penjumlahan
     *
     * @return hasil penjumlahan ekspresi x dan y
     */
    double solve();
};

#endif // ADDEXPRESSION_H
