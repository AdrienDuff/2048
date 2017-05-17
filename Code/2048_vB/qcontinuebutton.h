#ifndef QCONTINUEBUTTON_H
#define QCONTINUEBUTTON_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include <QLabel>


class QContinueButton : public QLabel
{
    Q_OBJECT
public:
    QContinueButton( QWidget* parent = 0);

signals:
    void clicked();

public slots:

protected:
    void mousePressEvent(QMouseEvent* event);

};

#endif // QCONTINUEBUTTON_H
