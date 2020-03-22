QT       += widgets

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES = \
    Sources/AddExpression.cpp \
    Sources/BinaryExpression.cpp \
    Sources/Button.cpp \
    Sources/Calculator.cpp \
    Sources/CosExpression.cpp \
    Sources/DivideExpression.cpp \
    Sources/Expression.cpp \
    Sources/MultiplyExpression.cpp \
    Sources/NegativeExpression.cpp \
    Sources/SinExpression.cpp \
    Sources/Solver.cpp \
    Sources/SqrExpression.cpp \
    Sources/SqrtExpression.cpp \
    Sources/SubtractExpression.cpp \
    Sources/TanExpression.cpp \
    Sources/TerminalExpression.cpp \
    Sources/UnaryExpression.cpp \
    Sources/main.cpp

HEADERS = \
    Headers/AddExpression.h \
    Headers/BinaryExpression.h \
    Headers/Button.h \
    Headers/Calculator.h \
    Headers/CosExpression.h \
    Headers/DivideExpression.h \
    Headers/Expression.h \
    Headers/MultiplyExpression.h \
    Headers/NegativeExpression.h \
    Headers/SinExpression.h \
    Headers/Solver.h \
    Headers/SqrExpression.h \
    Headers/SqrtExpression.h \
    Headers/SubtractExpression.h \
    Headers/TanExpression.h \
    Headers/TerminalExpression.h \
    Headers/UnaryExpression.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
