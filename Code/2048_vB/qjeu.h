#ifndef QJEU_H
#define QJEU_H

#include "jeu.h"
#include "observer.h"
#include "qgameoverwindow.h"
#include "qresetbutton.h"
#include "qcolorcase.h"

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QVector>

class QKeyEvent;
class QGridLayout;
class QVBoxLayout;
class QLabel;
class QPushButton;

class QJeu : public QWidget, public Observer
{
    Q_OBJECT
protected:
    void keyPressEvent(QKeyEvent *event);
private:
    Jeu* jeu;
    QVector<Qcolorcase*> gui_grille;

    QVBoxLayout *mainLayout;
    QGridLayout *boardLayout;
    // score widget
    QLabel *score;
    // newGame Widget
    QPushButton *newGame;
    // game over widget
    QGameOverWindow gameOverWindow;
    // win widget
    QLabel *youwin;

    void drawBoard();

public:
    explicit QJeu(QWidget *parent=0);
    ~QJeu();

    void notify();
    void speedIA(int ms);
    void IA1();
    void IA2();
    void IA3();
signals:

public slots:
    void resetGame();

};

#endif // QJEU_H
