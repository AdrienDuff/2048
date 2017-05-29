#include "gui/qgameboard.h"
#include "core/board.h"
#include "core/game.h"
#include "gui/qtile.h"
#include "core/tile.h"
#include "gui/qresetbutton.h"

#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QKeyEvent>
#include <QVBoxLayout>
#include <QString>
#include <QTimer>
#include <QEventLoop>
#include <ctime>

#include <QDebug>
#include <iostream>

//#include "rtNEAT.1.0.2/genome.h"
//#include "rtNEAT.1.0.2/genome.cpp"
//#include "rtNEAT.1.0.2/population.h"
//#include "rtNEAT.1.0.2/neat.h"
//#include "rtNEAT.1.0.2/network.h"
#include "rtNEAT.1.0.2/experiments.h"
#include <cstring>
#include <valarray>
#include <unistd.h>
using namespace std;
using namespace NEAT;

QGameBoard::~QGameBoard()
{
    delete game;
}

QGameBoard::QGameBoard(QWidget *parent) :
    QWidget(parent)
{

    resize(650,450);

    mainLayout = new QVBoxLayout();
    setLayout(mainLayout);

    boardLayout = NULL;

    newGame = new QPushButton("Nouvelle Partie");
    newGame->setFixedHeight(30);
    //mainLayout->addWidget(newGame);

    // créer le jeu
    game = new Game(4);
    game->registerObserver(this);



    gui_board.resize(game->getGameBoard()->getDimension());
    for (int i = 0; i < game->getGameBoard()->getDimension(); ++i)
        gui_board[i].resize(game->getGameBoard()->getDimension());
    for (int i = 0; i < game->getGameBoard()->getDimension(); ++i)
        for (int j = 0; j < game->getGameBoard()->getDimension(); ++j)
            gui_board[i][j] = NULL;
    drawBoard();



    // créer le widget score
    score = new QLabel(QString("SCORE: %1").arg(game->getScore()));
    score->setStyleSheet("QLabel { color: rgb(235,224,214); font: 16pt; }");
    score->setFixedHeight(50);
    mainLayout->insertWidget(1, score, 0, Qt::AlignRight);




    setStyleSheet("QGameBoard { background-color: rgb(187,173,160) }");

    connect(gameOverWindow.getResetBtn(), SIGNAL(clicked()), this, SLOT(resetGame()));
}

void QGameBoard::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
        game->move(UP);
        break;
    case Qt::Key_Left:
        game->move(LEFT);
        break;
    case Qt::Key_Right:
        game->move(RIGHT);
        break;
    case Qt::Key_Down:
        game->move(DOWN);
        break;
    case Qt::Key_Space:
        IA_neural();
        break;
    }
}

void QGameBoard::notify()
{
    if (game->isGameOver())
        gameOverWindow.show();

    if (game->won())
        score->setText(QString("You hit 2048, congratulations! Keep playing to increase your score.\t\t SCORE: %1").arg(game->getScore()));
    else
        score->setText(QString("SCORE: %1").arg(game->getScore()));

    drawBoard();
}

void QGameBoard::drawBoard()
{
    delete boardLayout;
    boardLayout = new QGridLayout();
    for (int i = 0; i < game->getGameBoard()->getDimension(); ++i) {
        for (int j = 0; j < game->getGameBoard()->getDimension(); ++j) {
            delete gui_board[i][j];
            gui_board[i][j] = new QTile(game->getGameBoard()->getTile(i,j));
            boardLayout->addWidget(gui_board[i][j], i, j);
            gui_board[i][j]->draw();
        }
    }
    mainLayout->insertLayout(0, boardLayout);
}


void QGameBoard::resetGame()
{
    game->restart();
    drawBoard();
    score->setText(QString("SCORE: %1").arg(game->getScore()));
    gameOverWindow.hide();
}


void QGameBoard::IA_neural() {
    Population *pop=0;
    Genome *start_genome;
    char curword[20];
    int id;
    int indice_max;
    int indice_pred;
    Direction dir;
    vector<double> out(4);
    vector<double> temp(4);
    vector<double> out_ini(4);
    bool success;
    bool maxfound;
    int to_check;
    


    ifstream iFile("jeu2048_winner",ios::in);

    //Read in the start Genome
    iFile>>curword;
    iFile>>id;
    cout<<"Reading in Genome id "<<id<<endl;
    start_genome= new Genome(id,iFile);
    iFile.close();

    pop=new Population(start_genome,1);
    cout<<"Verifying Spawned Pop"<<endl;
    pop->verify();

    Organism* org;
    org = pop->organisms[0];
    Network *net;
    net=org->net;
    vector<float> in;
    Board* b = game->getGameBoard();
    bool gameover = false;
    while(!game->isGameOver()){
        in.clear();
        //Il noust faut un tableau de 16 avec les cases.
        for (int i=0; i<=3;i++){
          for(int j=0; j<=3;j++){
            if (b->board[i][j] == NULL){
              in.push_back(0.0);
            }else{
              in.push_back(b->board[i][j]->getValue());
            }
          }
        }

        net->load_sensors(in);
        success=net->activate();
        //cout << success << endl;
        for(int i=0;i <4;i++){
          out[i] = net->outputs[i]->activation;
        }
        temp = out;
        out_ini = out;
        sort(temp.begin(), temp.begin()+4);

        //for(int unsigned i=0;i<4;i++){cout << "-" << out[i];} 
        //cout << endl;
        //for(int unsigned i=0;i<4;i++){cout << "-" << temp[i];} 
        //cout << endl;

        maxfound = false;
        to_check = 3;
        indice_pred = -1;
        while (maxfound == false and gameover == false){
          indice_max = distance(out.begin(), std::find(out.begin(), out.end(), temp[to_check]));
          while (indice_max == indice_pred){
            out[indice_max] = -1;
            indice_max = distance(out.begin(), std::find(out.begin(), out.end(), temp[to_check]));
          }
          switch(indice_max){
            case 0: dir = UP;
                    break;
            case 1: dir = DOWN;
                    break;
            case 2: dir = LEFT;
                    break;
            case 3: dir = RIGHT;
                    break;
          }
          Board other = Board(*b);
          b->move(dir);
          if (b->changed(other)){
            maxfound =true;
          }
          //cout << dir << endl;
          
          indice_pred = indice_max;
          to_check--;
          if (to_check == -1){
            gameover = true;
          }
        }

        net->flush();
        game->move(dir);
        speedIA(50);

    }
}

void QGameBoard::speedIA(int ms) {
    QEventLoop eventLoop;
    QTimer::singleShot (ms, &eventLoop, SLOT (quit ()));
    eventLoop.exec ();
}