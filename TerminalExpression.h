#ifndef TERMINALEXPRESSION_H
#define TERMINALEXPRESSION_H

#include "Expression.h"

class TerminalExpression : public Expression {
protected:
    double x;
public:
    TerminalExpression(double x);
    double solve();
};

#endif // TERMINALEXPRESSION_H
