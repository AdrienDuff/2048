#include "test_app_2048.h"

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

Test_App_2048::Test_App_2048()
{

}

bool Test_App_2048::Test_1(){
    Grille grille(16);
    int test1 = grille.getDim();
    int test2 = grille.getScore();

    grille.setValue(8,8);

    int test3 = grille.getValue(8);

    return (test1 == 16)&&(test2 == 0)&&(test3 == 8);
}
bool Test_App_2048::Test_2(){
    Grille grille(16);
    grille.setValue(0,2);
    grille.setValue(1,0);
    grille.setValue(2,0);
    grille.setValue(3,2);
    grille.moveLeft();

    int test1 = grille.getValue(0);
    int test2 = grille.getValue(1);
    int test3 = grille.getValue(2);
    int test4 = grille.getValue(3);

    return (test1 == 4)&&(test2 == 0)&&(test3 == 0)&&(test4 == 0);
}
bool Test_App_2048::Test_3(){
    Grille grille(16);
    grille.setValue(0,2);
    grille.setValue(4,0);
    grille.setValue(8,0);
    grille.setValue(12,2);
    grille.rotate(1);

    int test1 = grille.getValue(0);
    int test2 = grille.getValue(1);
    int test3 = grille.getValue(2);
    int test4 = grille.getValue(3);

    return (test1 == 2)&&(test2 == 0)&&(test3 == 0)&&(test4 == 2);
}
bool Test_App_2048::Test_4(){
    Jeu jeu(16);
    jeu.getGrilleJeu()->setValue(8,2048);

    return jeu.aGagne();
}
