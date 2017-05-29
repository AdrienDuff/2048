#ifndef QGAMEOVERWINDOW_H
#define QGAMEOVERWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include "qresetbutton.h"
#include "qcontinuebutton.h"

class QGameOverWindow : public QWidget
{
    Q_OBJECT
public:
    explicit QGameOverWindow(QWidget *parent = 0);

    QResetButton* getResetBtn() const {return reset;}

signals:

public slots:

private:
    QResetButton* reset;

};

#endif // QGAMEOVERWINDOW_H
