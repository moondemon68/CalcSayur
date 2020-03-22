#include "Calculator.h"
#include <iostream>

Calculator::Calculator(QWidget *parent) : QWidget(parent) {
    // Initialize variables
    currentNum = "";
    previousAns = "";
    afterEqual = true;
    lastToken = 0;
    countParenthesis = 0;

    // Initialize operator sets
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

    // Initialize display
    display = new QLineEdit("");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(30);

    // Initialize display font size
    QFont font = display->font();
    font.setPointSize(font.pointSize() + 8);
    display->setFont(font);

    // Initialize buttons
    for (int i = 0; i < NumDigitButtons; i++) {
        digitButtons[i] = createButton(QString::number(i), SLOT(digit_onClick()));
    }
    Button *pointButton = createButton(".", SLOT(point_onClick()));
    Button *addButton = createButton("+", SLOT(binaryOperator_onClick()));
    Button *subtractButton = createButton("-", SLOT(binaryOperator_onClick()));
    Button *multiplyButton = createButton("x", SLOT(binaryOperator_onClick()));
    Button *divideButton = createButton(":", SLOT(binaryOperator_onClick()));
    Button *sqrtButton = createButton("sqrt", SLOT(unaryOperator_onClick()));
    Button *sinButton = createButton("sin", SLOT(unaryOperator_onClick()));
    Button *cosButton = createButton("cos", SLOT(unaryOperator_onClick()));
    Button *tanButton = createButton("tan", SLOT(unaryOperator_onClick()));
    Button *sqrButton = createButton("sqr", SLOT(unaryOperator_onClick()));
    Button *equalButton = createButton("=", SLOT(equal_onClick()));
    Button *ansButton = createButton("ans", SLOT(ans_onClick()));
    Button *MCButton = createButton("MC", SLOT(MC_onClick()));
    Button *MRButton = createButton("MR", SLOT(MR_onClick()));
    Button *clearButton = createButton("clear", SLOT(clear_onClick()));
    Button *openParenthesis = createButton("(", SLOT(parenthesis_onClick()));
    Button *closeParenthesis = createButton(")", SLOT(parenthesis_onClick()));

    // Add buttons to layout
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSizeConstraint(QGridLayout::SetFixedSize);
    mainLayout->addWidget(display, 0, 0, 1, 6);
    mainLayout->addWidget(MCButton, 1, 0, 1, 2);
    mainLayout->addWidget(MRButton, 1, 2, 1, 2);
    mainLayout->addWidget(clearButton, 1, 4, 1, 2);
    mainLayout->addWidget(digitButtons[7], 2, 0);
    mainLayout->addWidget(digitButtons[8], 2, 1);
    mainLayout->addWidget(digitButtons[9], 2, 2);
    mainLayout->addWidget(digitButtons[4], 3, 0);
    mainLayout->addWidget(digitButtons[5], 3, 1);
    mainLayout->addWidget(digitButtons[6], 3, 2);
    mainLayout->addWidget(digitButtons[1], 4, 0);
    mainLayout->addWidget(digitButtons[2], 4, 1);
    mainLayout->addWidget(digitButtons[3], 4, 2);
    mainLayout->addWidget(digitButtons[0], 5, 0);
    mainLayout->addWidget(pointButton, 5, 1);
    mainLayout->addWidget(ansButton, 5, 2);
    mainLayout->addWidget(divideButton, 2, 3);
    mainLayout->addWidget(multiplyButton, 3, 3);
    mainLayout->addWidget(subtractButton, 4, 3);
    mainLayout->addWidget(addButton, 5, 3);
    mainLayout->addWidget(equalButton, 5, 5);
    mainLayout->addWidget(sqrtButton, 2, 4);
    mainLayout->addWidget(sinButton, 3, 4);
    mainLayout->addWidget(cosButton, 4, 4);
    mainLayout->addWidget(tanButton, 5, 4);
    mainLayout->addWidget(sqrButton, 2, 5);
    mainLayout->addWidget(openParenthesis, 3, 5);
    mainLayout->addWidget(closeParenthesis, 4, 5);
    setLayout(mainLayout);

    setWindowTitle("CalcSayur");
}

void Calculator::digit_onClick() {
    if (afterEqual) display->clear();
    Button *clickedButton = qobject_cast<Button*>(sender());
    QString digit = clickedButton->text();
    currentNum += digit;
    display->setText(display->text() + digit);
    lastToken = 3;
    afterEqual = false;
}

void Calculator::point_onClick() {
    if (afterEqual) display->clear();
    try {
        if (currentNum.contains('.')) {
            QString err = "Sudah ada tanda desimal";
            throw err;
        } else {
            currentNum += '.';
            display->setText(display->text() + '.');
            afterEqual = false;
        }
    } catch (QString error) {
        QErrorMessage* E = new QErrorMessage();
        E->showMessage(error);
    }
}

void Calculator::binaryOperator_onClick() {
    if (afterEqual) display->clear();
    Button *clickedButton = qobject_cast<Button*>(sender());
    QString op = clickedButton->text();
    if (!clickedButton) return;
    try {
        if ((lastToken == 2 || lastToken == 0) && op == "-") {  // - jadi unary
            Tokens.push_back(op);
            display->setText(display->text() + op);
            lastToken = 2;
            afterEqual = false;
        } else if (lastToken == 3) {
            Tokens.push_back(currentNum);
            currentNum = "";
            Tokens.push_back(op);
            display->setText(display->text() + op);
            lastToken = 2;
            afterEqual = false;
        } else if (lastToken == 2) {
            QString err = "Tidak boleh ada 2 binary operator yang berurutan";
            throw err;
        } else if (lastToken == 1) {
            QString err = "Tidak boleh ada binary operator setelah unary operator";
            throw err;
        } else if (lastToken == 0) {
            QString err = "Belum ada angka";
            throw err;
        }
    } catch (QString error) {
        QErrorMessage* E = new QErrorMessage();
        E->showMessage(error);
    }
}

void Calculator::unaryOperator_onClick() {
    if (afterEqual) display->clear();
    Button *clickedButton = qobject_cast<Button*>(sender());
    if (!clickedButton) return;
    QString op = clickedButton->text();
    try {
        if (lastToken == 0 || lastToken == 2) {
            QString op = clickedButton->text();
            Tokens.push_back(op);
            display->setText(display->text() + op);
            lastToken = 1;
            afterEqual = false;
        } else if (lastToken == 1) {
            QString err = "Tidak boleh ada 2 unary operator yang berurutan";
            throw err;
        } else if (lastToken == 3) {
            QString err = "Tidak boleh ada unary operator setelah suatu angka";
            throw err;
        }
    } catch (QString error) {
        QErrorMessage* E = new QErrorMessage();
        E->showMessage(error);
    }
}

void Calculator::equal_onClick() {
    if (afterEqual == true) return; // equal sign berkali - kali
    try {
        if (lastToken == 0 || lastToken == 3) {
            if (lastToken == 3) Tokens.push_back(currentNum);
            currentNum = "";
            lastToken = 0;
            if (countParenthesis > 0) {
                QString err = "Ada kurung yang tidak ditutup";
                throw err;
            }
            double result = calculateTokens();
            previousAns = QString::number(result);
            display->setText(QString::number(result));
            afterEqual = true;
        } else {
            QString err = "Akhir dari ekspresi harus merupakan angka";
            throw err;
        }
    } catch (QString error) {
        QErrorMessage* E = new QErrorMessage();
        E->showMessage(error);
    }
}

void Calculator::ans_onClick() {
    if (afterEqual) display->clear();
    currentNum = previousAns;
    lastToken = 3;
    display->setText(display->text() + currentNum);
    afterEqual = false;
}

void Calculator::MC_onClick() {
    currentNum = display->text();
    Memory.enqueue(currentNum.toDouble());
    currentNum = "";
    display->clear();
}

void Calculator::MR_onClick() {
    try {
        if (Memory.empty()) {
            QString err = "Queue memori kosong";
            throw err;
        }
        currentNum = QString::number(Memory.dequeue());
        display->setText(display->text() + currentNum);
        lastToken = 3;
        afterEqual = false;
    } catch (QString error) {
        QErrorMessage* E = new QErrorMessage();
        E->showMessage(error);
    }
}

void Calculator::clear_onClick() {
    currentNum = "0";
    lastToken = 0;
    countParenthesis = 0;
    afterEqual = true;
    Tokens.clear();
    display->clear();
    afterEqual = false;
}

void Calculator::parenthesis_onClick() {
    if (afterEqual) display->clear();
    Button *clickedButton = qobject_cast<Button*>(sender());
    if (!clickedButton) return;
    QString parenthesis = clickedButton->text();
    try {
        if (parenthesis == "(") {
            if (lastToken != 3) {
                countParenthesis++;
            } else {
                QString err = "Tidak boleh ada kurung buka setelah angka";
                throw err;
            }
        } else {
            if (countParenthesis <= 0) {
                QString err = "Kelebihan kurung tutup";
                throw err;
            }
            if (lastToken == 3) {
                Tokens.push_back(currentNum);
                currentNum = "";
            }
            countParenthesis--;
        }
        Tokens.push_back(parenthesis);
        display->setText(display->text() + parenthesis);
        //lastToken = 0;
    } catch (QString error) {
        QErrorMessage* E = new QErrorMessage();
        E->showMessage(error);
    }
}

Button* Calculator::createButton(const QString &text, const char *member) {
    Button* button = new Button(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

double Calculator::calculateBinary(QString left, QString op, QString right) {
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
        std::cerr << left.toUtf8().constData() << op.toUtf8().constData() << right.toUtf8().constData() << std::endl;
        QString err = "Unexpected error";
        throw err;
    }
    return E->solve();
}

double Calculator::calculateUnary(QString op, QString num) {
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
    } else if (op == "-") {
        E = new NegativeExpression(new TerminalExpression(num.toDouble()));
    } else {
        E = new TerminalExpression(num.toDouble());
    }
    return E->solve();
}

bool Calculator::isNumber(QString token) {
    return (!unaryOperator.contains(token) && !binaryOperator.contains(token));
}

bool Calculator::isUnary(QString token) {
    return unaryOperator.contains(token);
}

bool Calculator::isBinary(QString token) {
    return binaryOperator.contains(token);
}

int Calculator::priority(QString token) {
    if (token == "(" || token == ")") return 0;
    else if (token == "+" || token == "-") return 1;
    else if (token == "*" || token == ":") return 2;
    else return 3;
}

void Calculator::process(QStack<QString>& Value, QString op) {
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

double Calculator::calculateTokens() {
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
            std::cerr<<"hai"<<std::endl;
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
