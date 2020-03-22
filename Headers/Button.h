#ifndef BUTTON_H
#define BUTTON_H

#include <QToolButton>

class Button : public QToolButton
{
    Q_OBJECT
public:
    /**
     * Constructor Button.
     *
     * Men-generate tombol pada tampilan GUI kalkulator
     */
    explicit Button(const QString &text, QWidget *parent = nullptr);

    /**
     * Mengatur ukuran button.
     */
    QSize sizeHint() const override;
};

#endif // BUTTON_H
