#include "NBBot.hh"

#include <iostream>
#include <vector>

using namespace std;

void NBBot::initBot()
{
  cur = 0;
}

static void displayTurn(NBGame &game)
{
  cout << "In Turn " << game.getTurn() << '\n';
  cout << game.getStrike() << " strikes, " << game.getBall() << " balls\n";
}

static void displayResult(NBGame &game)
{
  cout << "Bot won in " << game.getTurn() << " turns\n";
}

int NBBot::playGame(NBGame &game, bool dispTurn, bool dispRes)
{
  game.initGame();
  initBot();
  vector<int> hubo;
  int c1, c2, c3;
  for (int i = 0; i <= 6; i += 3)
  {
    game.playTurn(i + 1, i + 2, i + 3);
    if (dispTurn) displayTurn(game);
    if (game.getStrike() == 3)
    {
      if (dispRes) displayResult(game);
      return game.getTurn();
    }
    if (game.getStrike() + game.getBall() > 0)
      hubo.push_back(i + 1), hubo.push_back(i + 2), hubo.push_back(i + 3);
  }
  for (int i = hubo.size() - 1; i >= 0; i--)
  {
    for (int j = hubo.size() - 1; j >= 0; j--)
    {
      if (i == j) continue;
      for (int k = hubo.size() - 1; k >= 0; k--)
      {
        if (i == k || j == k) continue;
        game.playTurn(hubo[i], hubo[j], hubo[k]);
        if (dispTurn) displayTurn(game);
        if (game.getStrike() == 3)
        {
          if (dispRes) displayResult(game);
          return game.getTurn();
        }
      }
    }
  }

  cout << "ERROR OCCURED\n";
  return -1;
}