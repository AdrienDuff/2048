#ifndef GAME_H
#define GAME_H

#define WINNING_VALUE 2048

#include "subject.h"
#include "board.h"

class Board;
class Game : public Subject
{
public:
    Game(int dimension);
    ~Game();
    void restart();
    Board* getGameBoard() const { return board; }
    bool isGameOver() const { return gameOver; }
    void move(Direction dir);
    // renvoie VRAI si on a gagné
    bool won() const;
    int getScore() const { return score; }

private:
    Board* board;
    bool gameOver;
    int score;

};

#endif // GAME_H
