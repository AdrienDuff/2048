#include "gui/mainwindow.h"
#include <QApplication>
#include <QtWidgets>

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "core/board.h"
#include "gui/qgameboard.h"

#include "gui/qgameoverwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    srand(time(NULL));

    QWidget fenetre;
           QPushButton *jeuSolo = new QPushButton("Jouer",&fenetre);
           QPushButton *jeuIA1 = new QPushButton("IA 1",&fenetre);
           QPushButton *jeuIA2 = new QPushButton("IA 2",&fenetre);
           QHBoxLayout *layout = new QHBoxLayout;
           layout->addWidget(jeuSolo);
           layout->addWidget(jeuIA1);
           layout->addWidget(jeuIA2);
           fenetre.setLayout(layout);

    QGameBoard board;

    QWidget::connect(jeuSolo, SIGNAL(clicked()), &board, SLOT(show()));
    QWidget::connect(jeuSolo,SIGNAL(clicked()),&fenetre,SLOT(close()));



    fenetre.show();


    return a.exec();
}
