#include "grille.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

Grille::Grille(int dim)
{
    score = 0;
    this->dim = dim;
    col = sqrt(dim);
    lignes = sqrt(dim);
    init();
}

/*Grille::Grille(const Grille &other){
    dim = other.dim;
    score = 0;
    col = sqrt(dim);
    lignes = sqrt(dim);
    for (int i = 0;i<dim;i++) {
        grille[i] = new int(other.grille[i]);
    }
    QVector<int> grille;
    grille = other.grille;

}*/

Grille::~Grille(){
   /* delete grille;*/
}

void Grille::init(){
    grille.resize(dim);
    for(int i=0;i<dim;i++){
        grille.append(0);
    }
    srand(time(NULL));
    grille[rand()%dim] = 2;
    grille[rand()%dim] = 2;
}

void Grille::reset(){
    score = 0;
    grille.clear();
    init();
}

void Grille::affiche() {
    int lign = lignes;
    while(lign != 0){
        for(int i=0;i<col;i++){
            cout << grille[(col-lign)*col+i]; // (colonnes-lignes)*colonnes +i permet d'afficher la bonne case du tableau en 2d
        }
        cout << endl;
        lign--;
   }
   cout << endl;
}

bool Grille::full() const {
    for(int i=0;i<dim;i++){
        if(grille[i]==0){
            return false;
        } else {
            return true;
        }
    }
}

void Grille::rotate(int nrotate){
    int tmp[dim];
    int tmp2[dim];
    for(int i=0;i<dim;i++){tmp[i] = grille[i];}
    for(int n=0;n<nrotate;n++){ // nrotate représente le nombre de rotation à effectuer
        int k=0;
        int i=0;
        while (i<dim){
            while(k<col){
                tmp2[i] = tmp[i/col+(lignes*(col-1))-k*col]; // permet de réaliser la rotation
                k++;
                i++;
            }
            k=0;
        }
        for(int j=0;j<dim;j++){tmp[j] = tmp2[j];}
        /*for(int j=0;j<dim;j++){
            g[j] = tmp[j];
        }*/
    }
    for(int i=0;i<dim;i++){grille.replace(i,tmp2[i]);}
}

void Grille::moveLeft(){
    QVector<int> ng(dim);
    int k = 0;
    int base = 0;
    int scoreMove = 0;
    for(int i=4;i<=dim;i+=4){
        while (k<i){
            if (grille[k] == 0){
                ++k;
                continue;
            }
            if (k+1<i && grille[k] == grille[k+1]){
                ng[base]=grille[k]*2;
                scoreMove += grille[k]*2;
                base++;
                k+=2;
            } else if (k+2<i && grille[k] == grille[k+2] && grille[k+1] == 0) {
                ng[base]=grille[k]*2;
                score += grille[k]*2;
                base++;
                k+=3;
            } else if (k+3<i && grille[k] == grille[k+3] && grille[k+1] == 0 && grille[k+2] == 0) {
                ng[base]=grille[k]*2;
                score += grille[k]*2;
                base++;
                k+=4;
            }else {
               // score += g[k];
                ng[base] = grille[k];
                base++;
                k++;
            }
        }
        while (base<i){
            ng[base]=0;
            base++;
        }
    }
    /*for (int j=0;j<taille;j++){
        g[j] = ng[j];
    }*/
    for(int i=0;i<dim;i++){grille.replace(i,ng[i]);}
    score=scoreMove;

}

void Grille::moveBottom(){
    rotate(3);
    moveLeft();
    rotate(1);
}

void Grille::moveRight(){
    rotate(2);
    moveLeft();
    rotate(2);
}

void Grille::moveTop(){
    rotate(1);
    moveLeft();
    rotate(3);
}

void Grille::move(Direction direction){
    Grille next_grille(*this);
    switch (direction){
    case UP:
        this->moveTop();
        break;
    case DOWN:
        this->moveBottom();
        break;
    case LEFT:
        this->moveLeft();
        break;
    case RIGHT:
        this->moveRight();
        break;
    }
    if (changed(next_grille) == true){

        srand(time(NULL));
        int alea = rand()%dim;
        while (grille[alea] != 0){
            alea = rand()%dim;
        }

        int alea2 = rand()%10;
        if (alea2==8){ grille[alea] = 4;
        } else {
            grille[alea] = 2;
        }
    }
    notifyObservers();
}

bool Grille::changed(Grille& newGrille) const {
    if (dim != newGrille.dim) {return false;}
    for(int i=0;i<dim;i++){
        if (grille[i] != newGrille.grille[i]){
            return true;
        }
    }
    return false;
}

bool Grille::movePossible() {
    if (full()) {
        return ((movePossiblein(UP))||(movePossiblein(DOWN))||(movePossiblein(LEFT))||(movePossiblein(RIGHT)));
    } else { return true;}
}

bool Grille::movePossiblein(Direction direction) {
    if (full()) {
        Grille newGrille(*this);
        newGrille.move(direction);
        return (this->changed(newGrille) == true);
    } else { return true;}
}

int Grille::countZeroAfter(Direction dir1,Direction dir2){
    Grille next_grille(*this);
    int scoreM=0;
    next_grille.move(dir1);
   // scoreM+=next_grille.getScore()*0.1;
    next_grille.move(dir2);
   // scoreM+=next_grille.getScore()*0.9;
    int count=0;
    for(int i=0; i<this->dim;i++){
        if (next_grille.getValue(i)==0){
            count++;

        }
    }
    cout << count << endl;
    return count+scoreM;
}

void Grille::setGrille(int tab_grille[]){
    for(int j=0;j<16;j++){
         this->grille[j] = tab_grille[j];
     }
}
