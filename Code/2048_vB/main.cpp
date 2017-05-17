#include <QApplication>
#include <QtWidgets>
#include <QVector>

#include "grille.h"
#include "jeu.h"
#include "qjeu.h"
#include "qgameoverwindow.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
   /* Grille maGrille(16);
    maGrille.affiche();
    maGrille.rotate(2);
    maGrille.affiche();
    maGrille.moveLeft();
    maGrille.rotate(2);
    maGrille.affiche();
    maGrille.move(UP);
    maGrille.affiche();
    cout << maGrille.movePossiblein(UP) << true << endl;
     maGrille.affiche();
    Jeu jeu(16);
    jeu.getGrilleJeu()->setValue(5,2048);
    cout << jeu.aGagne();
    return 0;*/

   QApplication a(argc, argv);

    srand(time(NULL));
    cout << !true << "=false" << endl;

    QWidget fenetre;
           QPushButton *jeuSolo = new QPushButton("Jouer",&fenetre);
           QPushButton *jeuIA1 = new QPushButton("APPUYER SUR ENTER POUR L'IA1",&fenetre);
           QPushButton *jeuIA2 = new QPushButton("APPUYER SUR SPACE POUR L'IA1",&fenetre);
           QHBoxLayout *layout = new QHBoxLayout;
           layout->addWidget(jeuSolo);
           layout->addWidget(jeuIA1);
           layout->addWidget(jeuIA2);
           fenetre.setLayout(layout);

    QJeu jeu;
    QWidget::connect(jeuSolo, SIGNAL(clicked()), &jeu, SLOT(show()));
    QWidget::connect(jeuSolo,SIGNAL(clicked()),&fenetre,SLOT(close()));


    fenetre.show();


    return a.exec();

}
