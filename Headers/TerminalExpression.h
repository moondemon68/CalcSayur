#ifndef TERMINALEXPRESSION_H
#define TERMINALEXPRESSION_H

#include "Expression.h"

class TerminalExpression : public Expression {
protected:
    double x;
public:
    TerminalExpression(double x);
    /* Konstruktor yang menerima sebuah angka bertipe double */
    double solve();
};

#endif // TERMINALEXPRESSION_H
