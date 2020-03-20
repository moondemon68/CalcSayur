#include "Calculator.h"

Calculator::Calculator(QWidget *parent) : QWidget(parent) {
    // Initialize variables
    currentNum = "0";
    previousAns = 0;

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
    Button *clickedButton = qobject_cast<Button*>(sender());
    QString digit = clickedButton->text();
    if (currentNum == "0" && digit == "0") return;
    currentNum += digit;
    if (display->text() == "0") display->setText(digit);
    display->setText(display->text() + digit);
}

void Calculator::point_onClick() {
    try {
        if (currentNum.contains('.')) {
            QString err = "Sudah ada tanda desimal";
            throw err;
        } else {
            currentNum += '.';
            display->setText(display->text() + '.');
        }
    } catch (QString error) {
        QErrorMessage* E = new QErrorMessage();
        E->showMessage(error);
    }
}

void Calculator::binaryOperator_onClick() {
    Button *clickedButton = qobject_cast<Button*>(sender());
    if (!clickedButton) return;
    QString op = clickedButton->text();
    if (op == "+") {

    } else if (op == "-") {

    } else if (op == "x") {

    } else if (op == ":") {

    }
}

void Calculator::unaryOperator_onClick() {
    Button *clickedButton = qobject_cast<Button*>(sender());
    if (!clickedButton) return;
    QString op = clickedButton->text();
    if (op == "sin") {

    } else if (op == "cos") {

    } else if (op == "tan") {

    } else if (op == "sqrt") {

    } else if (op == "sqr") {

    }
}

void Calculator::equal_onClick() {

}

void Calculator::ans_onClick() {

}

void Calculator::MC_onClick() {
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
    } catch (QString error) {
        QErrorMessage* E = new QErrorMessage();
        E->showMessage(error);
    }
}

void Calculator::clear_onClick() {
    currentNum = "0";
    display->clear();
}

Button* Calculator::createButton(const QString &text, const char *member) {
    Button* button = new Button(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

void Calculator::calculate() {

}
