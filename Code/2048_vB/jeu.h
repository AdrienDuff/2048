#ifndef JEU_H
#define JEU_H

#define VAL_MAX 2048

#include "grille.h"
#include "subject.h"

#include <QObject>
#include <QWidget>

class Jeu : public Subject
{
protected:

private:
    Grille* grilleJeu;
    int scoreJeu;
    bool finJeu;

public:
    Jeu(int dim);
   // Jeu(const Jeu &obj);
    ~Jeu();
    bool isGameOver() const { return finJeu;}
    int getScoreJeu() const {return scoreJeu;}
    Grille* getGrilleJeu() const {return grilleJeu;}
    void setGrilleJeu(Grille* newgrille) {grilleJeu=newgrille;}
    void setFinJeu(bool b) { finJeu = b;}
    void restart();
    void move(Direction dir);
    bool aGagne() const;

};

#endif // JEU_H
