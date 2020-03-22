#include "Calculator.h"
#include <iostream>

Calculator::Calculator(QWidget *parent) : QWidget(parent) {
    // Initialize variables
    currentNum = "";
    previousAns = "";
    afterEqual = true;
    nextNegative =false;
    lastToken = 0;
    countParenthesis = 0;
    Solver::initializeSet();

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
    if(nextNegative){
        currentNum = "-" + currentNum;
        nextNegative =false;
    }
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
        if ((lastToken == 2 || lastToken == 0 || lastToken == 1) && op == "-" && !nextNegative) {  // - jadi unary
            nextNegative = true;
            display->setText(display->text() + op);
            afterEqual = false;
        } else if (lastToken == 3) {
            if (currentNum != "") Tokens.push_back(currentNum);
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
            if (lastToken == 3 && currentNum != "") Tokens.push_back(currentNum);
            currentNum = "";
            lastToken = 0;
            if (countParenthesis > 0) {
                QString err = "Ada kurung yang tidak ditutup";
                throw err;
            }
            double result = Solver::calculateTokens(Tokens);
            Tokens.clear();
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
    currentNum = "";
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
        afterEqual = false;
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
