#ifndef BOARD_H
#define BOARD_H

#include "subject.h"
#include <vector>
#include "tile.h"


//class Tile;

enum Direction { UP, DOWN, LEFT, RIGHT };

class Board : public Subject
{
public:

    Board(int dimension);
    Board(const Board& other);
    // détruit Board
    ~Board();
    // initialise le jeu
    void reset();
    Tile* getTile(int i, int j);
    int getDimension() const { return dimension; }
    void move(Direction direction);
    bool full() const;
    int getPointsScoredLastRound() const { return pointsScoredLastRound; }
    bool isTileCollisionLastRound() const { return tileCollisionLastRound; }
    // mouvement possible ?
    bool movePossible() const;
    vector<vector<Tile*> > board;
    bool changed(Board& other) const;

private:
    
    int dimension;

    void init();
    // position aléatoire
    vector<int> freePosition();
    

    bool inbounds(int i, int j);
    void moveHorizontally(int i, int j, Direction dir);
    void moveVertically(int i, int j, Direction dir);
    void handleCollision(int i, int j);

    // réinitialise certains point avant le mouvement suivant
    void prepareForNextMove();

    int pointsScoredLastRound;
    bool tileCollisionLastRound;
};

#endif // BOARD_H
