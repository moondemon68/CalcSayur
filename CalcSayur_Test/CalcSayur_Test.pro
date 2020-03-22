QT += testlib
QT += gui
QT += widgets
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

INCLUDEPATH += ../CalcSayur/

HEADERS = \
    ../CalcSayur_Project/Headers/AddExpression.h \
    ../CalcSayur_Project/Headers/BinaryExpression.h \
    ../CalcSayur_Project/Headers/Button.h \
    ../CalcSayur_Project/Headers/Calculator.h \
    ../CalcSayur_Project/Headers/CosExpression.h \
    ../CalcSayur_Project/Headers/DivideExpression.h \
    ../CalcSayur_Project/Headers/Expression.h \
    ../CalcSayur_Project/Headers/MultiplyExpression.h \
    ../CalcSayur_Project/Headers/SinExpression.h \
    ../CalcSayur_Project/Headers/Solver.h \
    ../CalcSayur_Project/Headers/SqrExpression.h \
    ../CalcSayur_Project/Headers/SqrtExpression.h \
    ../CalcSayur_Project/Headers/SubtractExpression.h \
    ../CalcSayur_Project/Headers/TanExpression.h \
    ../CalcSayur_Project/Headers/TerminalExpression.h \
    ../CalcSayur_Project/Headers/UnaryExpression.h

SOURCES += tst_testing.cpp \
    ../CalcSayur_Project/Sources/AddExpression.cpp \
    ../CalcSayur_Project/Sources/BinaryExpression.cpp \
    ../CalcSayur_Project/Sources/Button.cpp \
    ../CalcSayur_Project/Sources/Calculator.cpp \
    ../CalcSayur_Project/Sources/CosExpression.cpp \
    ../CalcSayur_Project/Sources/DivideExpression.cpp \
    ../CalcSayur_Project/Sources/Expression.cpp \
    ../CalcSayur_Project/Sources/MultiplyExpression.cpp \
    ../CalcSayur_Project/Sources/SinExpression.cpp \
    ../CalcSayur_Project/Sources/Solver.cpp \
    ../CalcSayur_Project/Sources/SqrExpression.cpp \
    ../CalcSayur_Project/Sources/SqrtExpression.cpp \
    ../CalcSayur_Project/Sources/SubtractExpression.cpp \
    ../CalcSayur_Project/Sources/TanExpression.cpp \
    ../CalcSayur_Project/Sources/TerminalExpression.cpp \
    ../CalcSayur_Project/Sources/UnaryExpression.cpp \
