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
bool Test_App_2048::Test_5(){
    int tab[16];
    tab[0]=2;
    tab[1]=4;
    tab[2]=8;
    tab[3]=16;
    tab[4]=32;
    tab[5]=64;
    tab[6]=128;
    tab[7]=256;
    tab[8]=512;
    tab[9]=1024;
    tab[10]=2048;
    tab[11]=4096;
    tab[12]=8192;
    tab[13]=16384;
    tab[14]=32768;
    tab[15]=65536;
    Jeu newjeu(16);
    newjeu.getGrilleJeu()->setGrille(tab);
    if(!(newjeu.getGrilleJeu()->movePossible())){newjeu.setFinJeu(true);}
    return (!newjeu.getGrilleJeu()->movePossible()) && (newjeu.isGameOver()) && (newjeu.getGrilleJeu()->full());
}
