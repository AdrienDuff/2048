#ifndef GRILLE_H
#define GRILLE_H

#include "subject.h"

#include <QObject>
#include <QWidget>
#include <QVector>

enum Direction { UP, DOWN, LEFT, RIGHT };

class Grille : public Subject
{
protected:

private:
    int dim;
    QVector<int> grille;
    int score;
    int col;
    int lignes;
public:
    Grille(int dim);
    //Grille(const Grille &other);
    ~Grille();
    void init();
    void reset();
    int getDim() const { return dim;}
    int getCol() const { return col;}
    int getScore() const { return score;}
    int getValue(int ind) const {return grille[ind];}
    void setValue(int ind,int val) { grille[ind] = val;}
    void setGrille(int tab_grille[]);
    bool full() const;
    void rotate(int nrotate);
    void moveLeft();
    void moveRight();
    void moveBottom();
    void moveTop();
    void move(Direction direction);
    bool movePossible();
    bool movePossiblein(Direction direction);
    bool changed(Grille& newGrille) const;
    int countZeroAfter(Direction dir1, Direction dir2);
    void affiche();
};

#endif // GRILLE_H
