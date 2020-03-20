#include "TerminalExpression.h"

TerminalExpression::TerminalExpression(double x) {
    this->x = x;
}

double TerminalExpression::solve() {
    return this->x;
}
