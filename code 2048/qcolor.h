#ifndef QCOLOR_H
#define QCOLOR_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QLabel>

#include "grille.h"

class Qcolor : public QLabel
{
    Q_OBJECT
public:
    Qcolor(Grille* grilleJeu, int numCase);
    Qcolor(const QString & text);

    void draw();

private:
    Grille* gameBoard;
    int valeurCase;

signals:

public slots:
};

#endif // QCOLOR_H
