#include <QtTest>
#include <QCoreApplication>

// add necessary includes here
#include "../CalcSayur/Headers/AddExpression.h"
#include "../CalcSayur/Headers/BinaryExpression.h"
#include "../CalcSayur/Headers/Button.h"
#include "../CalcSayur/Headers/Calculator.h"
#include "../CalcSayur/Headers/CosExpression.h"
#include "../CalcSayur/Headers/DivideExpression.h"
#include "../CalcSayur/Headers/Expression.h"
#include "../CalcSayur/Headers/MultiplyExpression.h"
#include "../CalcSayur/Headers/SinExpression.h"
#include "../CalcSayur/Headers/Solver.h"
#include "../CalcSayur/Headers/SqrtExpression.h"
#include "../CalcSayur/Headers/SubtractExpression.h"
#include "../CalcSayur/Headers/TanExpression.h"
#include "../CalcSayur/Headers/TerminalExpression.h"
#include "../CalcSayur/Headers/UnaryExpression.h"

class Testing : public QObject
{
    Q_OBJECT

public:
    Testing();
    ~Testing();

private slots:
    // Terminal Expression
    void test_TerminalExpression();

    // Unary Expressions
    void test_SinExpression();
    void test_CosExpression();
    void test_TanExpression();
    void test_SqrtExpression();
    void test_SqrExpression();

    // Binary Expressions
    void test_AddExpression();
    void test_SubtractExpression();
    void test_MultiplyExpression();
    void test_DivideExpression();

    // Solver Functions
    void test_calculateBinary();
    void test_calculateUnary();
    void test_calculateTokens();
    void test_isNumber();
    void test_isUnary();
    void test_isBinary();
    void test_priority();

};

Testing::Testing()
{
    Solver::initializeSet();
}

Testing::~Testing()
{

}

// Terminal Expression
void Testing::test_TerminalExpression() {
    Expression* E = new TerminalExpression(6);
    QVERIFY(E->solve() == 6);
}

// Unary Expressions
void Testing::test_SinExpression() {
    Expression* E = new SinExpression(new TerminalExpression(0));
    QVERIFY(E->solve() == 0);
}
void Testing::test_CosExpression() {
    Expression* E = new CosExpression(new TerminalExpression(0));
    QVERIFY(E->solve() == 1);
}
void Testing::test_TanExpression() {
    Expression* E = new TanExpression(new TerminalExpression(0));
    QVERIFY(E->solve() == 0);
}
void Testing::test_SqrtExpression() {
    Expression* E = new SqrtExpression(new TerminalExpression(9));
    QVERIFY(E->solve() == 3);
}
void Testing::test_SqrExpression() {
    Expression* E = new SqrExpression(new TerminalExpression(3));
    QVERIFY(E->solve() == 9);
}

// Binary Expressions
void Testing::test_AddExpression() {
    Expression* E = new AddExpression(new TerminalExpression(2), new TerminalExpression(3));
    QVERIFY(E->solve() == 5);
}
void Testing::test_SubtractExpression() {
    Expression* E = new SubtractExpression(new TerminalExpression(2), new TerminalExpression(3));
    QVERIFY(E->solve() == -1);
}
void Testing::test_MultiplyExpression() {
    Expression* E = new MultiplyExpression(new TerminalExpression(2), new TerminalExpression(3));
    QVERIFY(E->solve() == 6);
}
void Testing::test_DivideExpression() {
    Expression* E = new DivideExpression(new TerminalExpression(6), new TerminalExpression(3));
    QVERIFY(E->solve() == 2);
}

// Solver Functions
void Testing::test_calculateBinary() {
    QVERIFY(Solver::calculateExpression("3", "x", "15") == 45);
}
void Testing::test_calculateUnary() {
    QVERIFY(Solver::calculateExpression("sqrt", "9") == 3);
}
void Testing::test_calculateTokens() {
    QList<QString> Tokens;
    Tokens.push_back("(");
    Tokens.push_back("6");
    Tokens.push_back("-");
    Tokens.push_back("3");
    Tokens.push_back(")");
    Tokens.push_back("x");
    Tokens.push_back("7");
    QVERIFY(Solver::calculateTokens(Tokens) == 21);
}
void Testing::test_isNumber() {
    QVERIFY(Solver::isNumber("242") == true);
}
void Testing::test_isUnary() {
    QVERIFY(Solver::isUnary("sqrt") == true);
}
void Testing::test_isBinary() {
    QVERIFY(Solver::isUnary("*") == false);
}
void Testing::test_priority() {
    QVERIFY(Solver::priority("x") > Solver::priority("+"));
}

QTEST_MAIN(Testing)

#include "tst_testing.moc"
