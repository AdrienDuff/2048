#include "jeu.h"
#include "grille.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

Jeu::Jeu(int dim)
{
    scoreJeu = 0;
    grilleJeu = new Grille(dim);
    finJeu = false;
    restart();
}
/*Jeu::Jeu(const Jeu &obj){
    scoreJeu = 0;
    grilleJeu = new Grille(16);
    *grilleJeu = *obj.getGrilleJeu();
    finJeu = false;
    restart();
}*/
Jeu::~Jeu(){
    /*delete grilleJeu;*/
}
void Jeu::restart(){
    grilleJeu->reset();
    finJeu = false;
    scoreJeu = 0;
}

void Jeu::move(Direction dir){
    if(this->grilleJeu->movePossiblein(dir)){
    this->grilleJeu->move(dir);
    scoreJeu+=grilleJeu->getScore();
    cout << "mouvement : " << dir << endl;
    }
    else {
        cout << "pas possible" << endl;
    }
    if(!grilleJeu->movePossible()){ finJeu = true;}
    notifyObservers();
}

bool Jeu::aGagne() const{
    for(int i= 0;i<grilleJeu->getDim();i++){
        if(grilleJeu->getValue(i) == VAL_MAX ){
           /* cout << "GAGNE";*/
            return true;}
    }
    return false;
}


