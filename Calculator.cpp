#include "Calculator.h"

Calculator::Calculator(QWidget *parent) : QWidget(parent) {
    // Initialize variables
    currentNum = "0";
    currentUnary = "";
    previousAns = "";
    afterEqual = true;

    // Initialize display
    display = new QLineEdit("");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(15);

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
    setLayout(mainLayout);

    setWindowTitle("CalcSayur");
}

void Calculator::digit_onClick() {
    if (afterEqual) display->clear();
    Button *clickedButton = qobject_cast<Button*>(sender());
    QString digit = clickedButton->text();
    currentNum += digit;
    if (display->text() == "0") display->setText(digit);
    display->setText(display->text() + digit);
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
    if (!clickedButton) return;
    try {
        if (Operands.size() == Operators.size()) {
            Operands.push(calculateUnary());
            QString op = clickedButton->text();
            Operators.push(op);
            display->setText(display->text() + op);
            afterEqual = false;
        } else {
            QString err = "Tidak boleh ada 2 binary operator yang berurutan";
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
        if (currentUnary != "") {
            QString err = "Unary operator tidak boleh berulang";
            throw err;
        }
        currentUnary = op;
        display->setText(display->text() + op);
        afterEqual = false;
    } catch (QString error) {
        QErrorMessage* E = new QErrorMessage();
        E->showMessage(error);
    }
}

void Calculator::equal_onClick() {
    currentNum = QString::number(calculateUnary());
    while (!Operands.empty()) {    // Operators and Operands have same size
        double Num = Operands.pop();
        QString Op = Operators.pop();
        currentNum = QString::number(calculateBinary(Num, Op));
    }
    display->setText(currentNum);
    previousAns = currentNum;
    currentNum = "0";
    currentUnary = "";
    afterEqual = true;
}

void Calculator::ans_onClick() {
    currentNum = previousAns;
    display->setText(display->text() + currentNum);
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
        afterEqual = false;
    } catch (QString error) {
        QErrorMessage* E = new QErrorMessage();
        E->showMessage(error);
    }
}

void Calculator::clear_onClick() {
    currentNum = "0";
    currentUnary = "";
    Operators.clear();
    Operands.clear();
    display->clear();
    afterEqual = false;
}

Button* Calculator::createButton(const QString &text, const char *member) {
    Button* button = new Button(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

double Calculator::calculateBinary(double Num, QString op) {
    Expression* E;
    if (op == "+") {
        E = new AddExpression(new TerminalExpression(Num), new TerminalExpression(currentNum.toDouble()));
    } else if (op == "-") {
        E = new SubtractExpression(new TerminalExpression(Num), new TerminalExpression(currentNum.toDouble()));
    } else if (op == "x") {
        E = new MultiplyExpression(new TerminalExpression(Num), new TerminalExpression(currentNum.toDouble()));
    } else if (op == ":") {
        E = new DivideExpression(new TerminalExpression(Num), new TerminalExpression(currentNum.toDouble()));
    } else {    // harusnya ga masuk sini
        E = new TerminalExpression(currentNum.toDouble());
    }
    return E->solve();
}

double Calculator::calculateUnary() {
    Expression* E;
    if (currentUnary == "sin") {
        E = new SinExpression(new TerminalExpression(currentNum.toDouble()));
    } else if (currentUnary == "cos") {
        E = new CosExpression(new TerminalExpression(currentNum.toDouble()));
    } else if (currentUnary == "tan") {
        E = new TanExpression(new TerminalExpression(currentNum.toDouble()));
    } else if (currentUnary == "sqr") {
        E = new SqrExpression(new TerminalExpression(currentNum.toDouble()));
    } else if (currentUnary == "sqrt") {
        E = new SqrtExpression(new TerminalExpression(currentNum.toDouble()));
    } else {
        E = new TerminalExpression(currentNum.toDouble());
    }
    currentUnary = "";
    currentNum = "0";
    return E->solve();
}
