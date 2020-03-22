#ifndef TERMINALEXPRESSION_H
#define TERMINALEXPRESSION_H

#include "Expression.h"

class TerminalExpression : public Expression {
protected:
    double x;
public:
    /**
     * Konstruktor untuk TerminalExpression.
     *
     * @param double x
     */
    TerminalExpression(double x);
    /**
     * @return double x
     */
    double solve();
};

#endif // TERMINALEXPRESSION_H
