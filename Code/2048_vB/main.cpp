#include <QApplication>
#include <QtWidgets>
#include <QVector>

#include "grille.h"
#include "jeu.h"
#include "qjeu.h"
#include "qgameoverwindow.h"
#include "test_app_2048.h"

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


    Test_App_2048 test_unitaire;
    cout << "                       Batterie de tests unitaires sur le jeu 20480" << endl;
    cout << " Test 1 : renvoie 1 si on recupere la bonne dimension, le bon score et fonction setValue fonctionnelle -->  " << test_unitaire.Test_1() << endl;
    cout << " Test 2 : renvoie 1 si la fonction moveLeft est fonctionnelle -->                                           " << test_unitaire.Test_2() << endl;
    cout << " Test 3 : renvoie 1 si la fonction rotate est fonctionnelle -->                                             " << test_unitaire.Test_3() << endl;
    cout << " Test 4 : renvoie 1 si le test de la fonction aGagne() est valide  -->                                      " << test_unitaire.Test_4() << endl;
    cout << " Test 5 : renvoie 1 si le test des fonctions isGameOver(), full() et movePossible() est valide -->          " << test_unitaire.Test_5() << endl;




    return a.exec();

}
