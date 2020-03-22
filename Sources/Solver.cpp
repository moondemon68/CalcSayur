#include "Headers/Solver.h"

// Initialize operator sets
QSet<QString> Solver::binaryOperator;
QSet<QString> Solver::unaryOperator;

void Solver::initializeSet() {
    binaryOperator.insert("+");
    binaryOperator.insert("-");
    binaryOperator.insert("x");
    binaryOperator.insert(":");

    unaryOperator.insert("sin");
    unaryOperator.insert("cos");
    unaryOperator.insert("tan");
    unaryOperator.insert("sqrt");
    unaryOperator.insert("sqr");
    unaryOperator.insert("-");
}

double Solver::calculateBinary(QString left, QString op, QString right) {
    Expression* E;
    if (op == "+") {
        E = new AddExpression(new TerminalExpression(left.toDouble()), new TerminalExpression(right.toDouble()));
    } else if (op == "-") {
        E = new SubtractExpression(new TerminalExpression(left.toDouble()), new TerminalExpression(right.toDouble()));
    } else if (op == "x") {
        E = new MultiplyExpression(new TerminalExpression(left.toDouble()), new TerminalExpression(right.toDouble()));
    } else if (op == ":") {
        E = new DivideExpression(new TerminalExpression(left.toDouble()), new TerminalExpression(right.toDouble()));
    } else {    // harusnya ga masuk sini
        QString err = "Unexpected error";
        throw err;
    }
    return E->solve();
}

double Solver::calculateUnary(QString op, QString num) {
    Expression* E;
    if (op == "sin") {
        E = new SinExpression(new TerminalExpression(num.toDouble()));
    } else if (op == "cos") {
        E = new CosExpression(new TerminalExpression(num.toDouble()));
    } else if (op == "tan") {
        E = new TanExpression(new TerminalExpression(num.toDouble()));
    } else if (op == "sqr") {
        E = new SqrExpression(new TerminalExpression(num.toDouble()));
    } else if (op == "sqrt") {
        E = new SqrtExpression(new TerminalExpression(num.toDouble()));
    } else {
        E = new TerminalExpression(num.toDouble());
    }
    return E->solve();
}

double Solver::calculateTokens(QList<QString> Tokens) {
    for (auto x : Tokens) std::cerr << x.toUtf8().constData() << " ";

    QStack<QString> Value;
    QStack<QString> Operator;
    while (!Tokens.empty()) {
        QString cur = Tokens.front();
        Tokens.pop_front();

        if (cur == "(") {
            Operator.push(cur);
        } else if (cur == ")") {
            while (Operator.top() != "(") {
                process(Value, Operator.top());
                Operator.pop();
            }
            Operator.pop();
        } else if (isBinary(cur)) {
            while (!Operator.empty() && priority(Operator.top()) >= priority(cur)) {
                process(Value, Operator.top());
                Operator.pop();
            }
            Operator.push(cur);
        } else if (isUnary(cur)) {
            while (!Operator.empty() && priority(Operator.top()) > priority(cur)) {
                process(Value, Operator.top());
                Operator.pop();
            }
            Operator.push(cur);
        } else {
            Value.push(cur);
        }
    }

    while (!Operator.empty()) {
        process(Value, Operator.top());
        Operator.pop();
    }

    double ans = Value.front().toDouble();

    std::cerr << " = " << ans;
    std::cerr << std::endl;

    return ans;
}

bool Solver::isNumber(QString token) {
    return (!unaryOperator.contains(token) && !binaryOperator.contains(token));
}

bool Solver::isUnary(QString token) {
    return unaryOperator.contains(token);
}

bool Solver::isBinary(QString token) {
     return binaryOperator.contains(token);
}

int Solver::priority(QString token) {
    if (token == "(" || token == ")") return 0;
    else if (token == "+" || token == "-") return 1;
    else if (token == "x" || token == ":") return 2;
    else return 3;
}

void Solver::process(QStack<QString>& Value, QString op) {
    if (isBinary(op)) {
        QString right = Value.top();
        Value.pop();
        QString left = Value.top();
        Value.pop();
        QString res = QString::number(calculateBinary(left, op, right));
        Value.push(res);
    } else {
        QString num = Value.top();
        Value.pop();
        num = QString::number(calculateUnary(op, num));
        Value.push(num);
    }
}
