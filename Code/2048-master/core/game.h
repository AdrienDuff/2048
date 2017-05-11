#ifndef GAME_H
#define GAME_H

#define WINNING_VALUE 2048

#include "core/subject.h"
#include "core/board.h"

class Board;

class Game : public Subject
{
public:
    Game(int dimension);
    ~Game();
    void restart();
    bool isGameOver() const { return gameOver; }
    Board* getGameBoard() const { return board; }
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
