#include "core/game.h"
#include "core/tile.h"

Game::Game(int dimension)
{
    score = 0;
    board = new Board(dimension);
    restart();
}

Game::~Game()
{
    delete board;
}

void Game::move(Direction dir)
{
    // effectue le déplacement
    board->move(dir);

    // maj score
    if (board->isTileCollisionLastRound())
        score += board->getPointsScoredLastRound();

    // si pas de déplacement possible ==> game over
    if (!board->movePossible())
        gameOver = true;

    notifyObservers();
}

void Game::restart()
{
    board->reset();
    gameOver = false;
    score = 0;
}


// si valeur max atteinte ==> win
bool Game::won() const
{
    for (int i = 0; i < board->getDimension(); ++i)
        for (int j = 0; j < board->getDimension(); ++j)
            if (board->getTile(i,j) != NULL && board->getTile(i,j)->getValue() == WINNING_VALUE)
                return true;

    return false;
}
