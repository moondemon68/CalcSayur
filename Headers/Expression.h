#ifndef EXPRESSION_H
#define EXPRESSION_H


class Expression {
public:
    /**
     * Konstruktor untuk Expression.
     *
     */
    Expression();
    /**
     *
     * abstract method yang merupakan polymorphism
     */
    virtual double solve() = 0;
};

#endif // EXPRESSION_H
