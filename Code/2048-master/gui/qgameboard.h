#ifndef QGAMEBOARD_H
#define QGAMEBOARD_H

#include "core/observer.h"
#include "qgameoverwindow.h"

#include <QVector>
#include <QWidget>

class QResetButton;
class Game;
class QKeyEvent;
class QTile;
class QGridLayout;
class QVBoxLayout;
class QLabel;
class QPushButton;

class QGameBoard : public QWidget, public Observer
{
    Q_OBJECT
public:
    explicit QGameBoard(QWidget *parent = 0);
    ~QGameBoard();

    void notify();
    void speedIA(int ms);

private:

    Game* game;
    // gui representation du jeu
    QVector<QVector<QTile*> > gui_board;
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

protected:
    void keyPressEvent(QKeyEvent *event);

signals:

public slots:
    void resetGame();
    void IA_neural();

};

#endif // QGAMEBOARD_H
