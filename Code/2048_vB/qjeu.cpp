#include "qjeu.h"
#include "grille.h"
#include "jeu.h"
#include "qcolorcase.h"
#include "qresetbutton.h"


#include <QTimer>
#include <QEventLoop>

#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QKeyEvent>
#include <QVBoxLayout>
#include <QString>

#include <QDebug>

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

QJeu::~QJeu(){
 delete jeu;
}

QJeu::QJeu(QWidget *parent) : QWidget(parent)
{
    resize(650,650);

    mainLayout = new QVBoxLayout();
    setLayout(mainLayout);

    boardLayout = NULL;

    newGame = new QPushButton("Nouvelle Partie");
    newGame->setFixedHeight(30);
    //mainLayout->addWidget(newGame);

    jeu = new Jeu(16);
    jeu->registerObserver(this);

    gui_grille.resize(jeu->getGrilleJeu()->getDim());
    for(int i=0; i < jeu->getGrilleJeu()->getDim();i++){
        gui_grille[i] = new Qcolorcase(jeu->getGrilleJeu(),i);
    }
    drawBoard();

    // créer le widget score
    score = new QLabel(QString("SCORE: %1").arg(jeu->getScoreJeu()));
    score->setStyleSheet("QLabel { color: rgb(235,224,214); font: 16pt; }");
    score->setFixedHeight(50);
    mainLayout->insertWidget(1, score, 0, Qt::AlignRight);


    setStyleSheet("QJeu { background-color: rgb(187,173,160) }");

    connect(gameOverWindow.getResetBtn(), SIGNAL(clicked()), this, SLOT(resetGame()));
    //connect(gameOverWindow.getContBtn(), SIGNAL(clicked()), this, SLOT(drawBoard()));

}

void QJeu::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
    case Qt::Key_Up:
        jeu->move(UP);
        break;
    case Qt::Key_Left:
        jeu->move(LEFT);
        break;
    case Qt::Key_Right:
        jeu->move(RIGHT);
        break;
    case Qt::Key_Down:
        jeu->move(DOWN);
        break;
    case Qt::Key_Enter:
        IA();
        break;
    case Qt::Key_Space:
        IA3();
        break;

    }
}

void QJeu::notify(){
    if (jeu->isGameOver()){gameOverWindow.show();}

    if (jeu->aGagne()){
        score->setText(QString("You hit 2048, congratulations! Keep playing to increase your score.\t\t SCORE: %1").arg(jeu->getScoreJeu()));
    } else {
        score->setText(QString("SCORE: %1").arg(jeu->getScoreJeu()));
    }

    drawBoard();
}

void QJeu::drawBoard(){
    delete boardLayout;
    boardLayout = new QGridLayout();
    int lign = jeu->getGrilleJeu()->getCol();
    while(lign != 0){
        for (int i=0;i<jeu->getGrilleJeu()->getCol();i++){
            int ind((jeu->getGrilleJeu()->getCol()-lign)*jeu->getGrilleJeu()->getCol()+i);
            delete gui_grille[ind];

            gui_grille[ind] = new Qcolorcase(jeu->getGrilleJeu(),ind);

            boardLayout->addWidget(gui_grille[(jeu->getGrilleJeu()->getCol()-lign)*jeu->getGrilleJeu()->getCol()+i],lign,i);
        }
        lign--;
    }
    for (int i=0;i<jeu->getGrilleJeu()->getDim();i++){
        gui_grille[i]->draw();
    }
    mainLayout->insertLayout(0, boardLayout);
}

void QJeu::resetGame(){
    jeu->restart();
    drawBoard();
    score->setText(QString("SCORE: %1").arg(jeu->getScoreJeu()));
    gameOverWindow.hide();
}

void QJeu::speedIA(int ms) {
    QEventLoop eventLoop;
    QTimer::singleShot (ms, &eventLoop, SLOT (quit ()));
    eventLoop.exec ();
}

void QJeu::IA1() {
    while(!jeu->isGameOver()){

        jeu->move(UP);
        speedIA(2000);
        jeu->move(RIGHT);
        speedIA(2000);
        jeu->move(LEFT);
        speedIA(2000);
        jeu->move(DOWN);
        speedIA(2000);
    }
}

void QJeu::IA2() {
    while(!jeu->isGameOver()){
        int scoreM = 0;
        while (scoreM==0){
        Direction dirM;
        int tab_grille[16];
        for (int i= 0 ;i<16;i++){
            tab_grille[i] = jeu->getGrilleJeu()->getValue(i);
        }
        for (int i=0;i<4;i++ ){
            Direction dir;
            switch(i){
            case 0:
                dir = UP;
                break;
            case 1:
                dir = DOWN;
                break;
            case 2:
                dir = RIGHT;
                break;
            case 3:
                dir = LEFT;
                break;
            }

            Jeu jeutmp(jeu->getGrilleJeu()->getDim());
            for(int j=0;j<16;j++){
                jeutmp.getGrilleJeu()->setValue(j,tab_grille[j]);
            }

            jeutmp.move(dir);
            int scoretmp = jeutmp.getScoreJeu();
            if (scoretmp > scoreM){
                scoreM = scoretmp;
                dirM = dir;
            }jeutmp.restart();
        }
        if (scoreM==0){
                srand(time(NULL));
                Direction dir;
                int d = rand()%4;
                switch(d){
                case 0:
                    dir = UP;
                    break;
                case 1:
                    dir = DOWN;
                    break;
                case 2:
                    dir = RIGHT;
                    break;
                case 3:
                    dir = LEFT;
                    break;
                }
                jeu->move(dir);
                speedIA(200);
        } else {
        jeu->move(dirM);
        speedIA(200);}
        }
}

}

void QJeu::IA3(){
    while(!jeu->isGameOver()){
        int nb_cellule_vide;
        /*int tab_grille[16];
        for (int i= 0 ;i<16;i++){
            tab_grille[i] = jeu->getGrilleJeu()->getValue(i);
        }
        Jeu jeutmp(jeu->getGrilleJeu()->getDim());
        jeutmp.getGrilleJeu()->setGrille(tab_grille);*/

        Direction move_direction =DOWN;
        if(!(jeu->getGrilleJeu()->movePossiblein(DOWN))){
            if(jeu->getGrilleJeu()->movePossiblein(RIGHT) && jeu->getGrilleJeu()->movePossiblein(LEFT)){
                if (jeu->getGrilleJeu()->countZeroAfter(LEFT,DOWN) >= jeu->getGrilleJeu()->countZeroAfter(RIGHT,DOWN)){
                        move_direction=LEFT;

                } else {
                    move_direction=RIGHT;
                }
            } else if (jeu->getGrilleJeu()->movePossiblein(LEFT)){
                move_direction=LEFT;
            } else if (jeu->getGrilleJeu()->movePossiblein(RIGHT)){
                move_direction=RIGHT;
            } else {
                move_direction = UP;
            }
        }



        jeu->move(move_direction);
        speedIA(200);
    }
}

void QJeu::IA() {
    while(!(this->jeu->isGameOver())){
          Direction dir_interdite = UP;
         /*if (this->jeu->getGrilleJeu()->movePossiblein(DOWN)){
                this->jeu->move(DOWN);
          speedIA(200);
          }*/

          if (!(this->jeu->getGrilleJeu()->movePossiblein(DOWN))){
               if (this->jeu->getGrilleJeu()->movePossiblein(RIGHT) && this->jeu->getGrilleJeu()->movePossiblein(LEFT)){
                    if (this->jeu->getGrilleJeu()->countZeroAfter(LEFT,DOWN) > this->jeu->getGrilleJeu()->countZeroAfter(RIGHT,DOWN)){
                        this->jeu->move(LEFT);
                    } else if (this->jeu->getGrilleJeu()->countZeroAfter(LEFT,DOWN) == this->jeu->getGrilleJeu()->countZeroAfter(RIGHT,DOWN)) {
                        this->jeu->move(LEFT);
                    } else {
                        this->jeu->move(RIGHT);
                    }
               } else if (this->jeu->getGrilleJeu()->movePossiblein(LEFT)){
                    this->jeu->move(LEFT);

               } else if (this->jeu->getGrilleJeu()->movePossiblein(RIGHT)){
                    this->jeu->move(RIGHT);
               } else {
                    this->jeu->move(dir_interdite);
               }
           } else {
            this->jeu->move(DOWN);
         }
         speedIA(200);
    }
}

