#include "qcontinuebutton.h"

QContinueButton::QContinueButton(QWidget* parent)
{
    setText("Continue");
    setAlignment(Qt::AlignCenter);
    setStyleSheet("QContinueButton { background-color: rgb(143,122,102); border-radius: 10px; font: bold; color: white; }");

}

void QContinueButton::mousePressEvent(QMouseEvent* event)
{
    emit clicked();
}
