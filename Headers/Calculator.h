#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Button.h"
#include "Solver.h"


#include <QWidget>
#include <QQueue>
#include <QStack>
#include <QList>
#include <QLineEdit>
#include <QGridLayout>
#include <QErrorMessage>
#include <QSet>

class Calculator : public QWidget
{
    Q_OBJECT
public:
    /**
     * Konstruktor untuk Calculator.
     *
     * @param Pointer QWidget parent
     *
     * Membuat tampilan GUI kalkulator
     */
    Calculator(QWidget *parent = nullptr);

private slots:
    /**
     * Method digit_onClick.
     *
     * Melakukan aksi jika digit ditekan
     */
    void digit_onClick();

    /**
     * Method point_onClick.
     *
     * Melakukan aksi jika koma (titik pada tampilan kalkulator) ditekan
     * @throw jika tanda koma tidak didahului dan diakhiri dengan suatu angka
     */
    void point_onClick();

    /**
     * Method binaryOperator_onClick.
     *
     * Melakukan aksi jika operator binary ditekan
     *
     * @throw jika operator binary tidak didahului dan diakhiri dengan suatu angka
     */
    void binaryOperator_onClick();

    /**
     * Method unaryOperator_onClick.
     *
     * Melakukan aksi jika operator unary ditekan
     *
     * @throw jika ada dua operator unary berturut-turut
     * @throw jika ada unary operator setelah sebuah angka
     */
    void unaryOperator_onClick();

    /**
     * Method equal_onClick.
     *
     * Melakukan aksi jika tombol sama dengan (=) ditekan
     *
     * @throw jika ekspresi tidak diakhiri dengan sebuah angka
     * @throw jika pada ekspresi ada tanda kurung yang tidak ditutup
     */
    void equal_onClick();

    /**
     * Method ans_onClick.
     *
     * Melakukan aksi jika tombol ans ditekan
     */
    void ans_onClick();

    /**
     * Method MC_onClick.
     *
     * Melakukan aksi jika tombol MC ditekan
     */
    void MC_onClick();

    /**
     * Method MR_onClick.
     *
     * Melakukan aksi jika tombol MR ditekan
     *
     * @throw jika memori Queue kosong
     */
    void MR_onClick();

    /**
     * Method clear_onClick.
     *
     * Melakukan aksi jika tombol clear ditekan
     */
    void clear_onClick();

    /**
     * Method parenthesis_onClick.
     *
     * Melakukan aksi jika tombol tanda kurung ditekan
     *
     * @throw jika ada kurung buka setelah angka
     * @throw jika tanda kurung tutup berlebihan
     */
    void parenthesis_onClick();

private:
    Button *createButton(const QString &text, const char *member);
    bool afterEqual;
    bool nextNegative;
    QQueue<double> Memory;
    QString currentNum;
    QString previousAns;
    QList<QString> Tokens;
    int lastToken;  // 0 - nothing, 1 - unary, 2 - binary, 3 - number
    int countParenthesis;
    QLineEdit *display;
    enum { NumDigitButtons = 10 };
    Button *digitButtons[NumDigitButtons];
};

#endif // CALCULATOR_H
