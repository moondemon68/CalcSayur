QT       += widgets

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES = \
    AddExpression.cpp \
    BinaryExpression.cpp \
    Button.cpp \
    Calculator.cpp \
    CosExpression.cpp \
    DivideExpression.cpp \
    Expression.cpp \
    MultiplyExpression.cpp \
    NegativeExpression.cpp \
    SinExpression.cpp \
    Solver.cpp \
    SqrExpression.cpp \
    SqrtExpression.cpp \
    SubtractExpression.cpp \
    TanExpression.cpp \
    TerminalExpression.cpp \
    UnaryExpression.cpp \
    main.cpp

HEADERS = \
    AddExpression.h \
    BinaryExpression.h \
    Button.h \
    Calculator.h \
    CosExpression.h \
    DivideExpression.h \
    Expression.h \
    MultiplyExpression.h \
    NegativeExpression.h \
    SinExpression.h \
    Solver.h \
    SqrExpression.h \
    SqrtExpression.h \
    SubtractExpression.h \
    TanExpression.h \
    TerminalExpression.h \
    UnaryExpression.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
