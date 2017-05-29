#ifndef QCOLORCASE_H
#define QCOLORCASE_H

#include "grille.h"
#include <QObject>
#include <QWidget>
#include <QLabel>

class Qcolorcase : public QLabel
{
    Q_OBJECT
public:
    Qcolorcase(Grille* grilleJeu, int numCase);
    Qcolorcase(const QString & text);

    void draw();

private:
    Grille* gameBoard;
    int valeurCase;

signals:

public slots:
};

#endif // QCOLORCASE_H
