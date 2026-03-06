#include "NBBot.hh"

#include <iostream>
#include <vector>

using namespace std;

void NBBot::initBot()
{
  gameResult = 0;
  gameResultAcc = 0;
  gameCount = 0;
}

int NBBot::getResult() { return gameResult; }
double NBBot::getAverage() { return static_cast<double>(gameResultAcc) / static_cast<double>(gameCount); }

static void displayTurn(NBGame &game)
{
  cout << "In Turn " << game.getTurn() << '\n';
  cout << game.getStrike() << " strikes, " << game.getBall() << " balls\n";
}
#define DISPTURN \
  if (dispTurn) displayTurn(game)

static void displayResult(NBGame &game)
{
  cout << "Bot won in " << game.getTurn() << " turns\n";
}
#define DISPRES \
  if (dispRes) displayResult(game)

int NBBot::playGame(NBGame &game, bool dispTurn, bool dispRes)
{
  initBot();
  vector<vector<bool>> can(3, vector<bool>(10, true));
  int c1 = 1, c2 = 2, c3 = 3;
  constexpr int cc1[] = {1, 4, 7, 1, 2, 3};
  constexpr int cc2[] = {2, 5, 8, 4, 5, 6};
  constexpr int cc3[] = {3, 6, 9, 7, 8, 9};

  for (int i = 0; i < 6; i++)
  {
    c1 = cc1[i], c2 = cc2[i], c3 = cc3[i];
    game.playTurn(c1, c2, c3);
    DISPTURN;
    if (game.getStrike() == 3)
    {
      DISPRES;
      return game.getTurn();
    }
    else if (game.getStrike() == 1 && game.getBall() == 2)
    {
      game.playTurn(c1, c3, c2);
      DISPTURN;
      if (game.getStrike() == 3)
      {
        DISPRES;
        return game.getTurn();
      }
      game.playTurn(c2, c1, c3);
      DISPTURN;
      if (game.getStrike() == 3)
      {
        DISPRES;
        return game.getTurn();
      }
      game.playTurn(c3, c2, c1);
      DISPTURN;
      if (game.getStrike() == 3)
      {
        DISPRES;
        return game.getTurn();
      }
    }
    else if (game.getBall() == 3)
    {
      game.playTurn(c2, c3, c1);
      DISPTURN;
      if (game.getStrike() == 3)
      {
        DISPRES;
        return game.getTurn();
      }
      game.playTurn(c3, c1, c2);
      DISPTURN;
      if (game.getStrike() == 3)
      {
        DISPRES;
        return game.getTurn();
      }
    }
    else if (game.getStrike() + game.getBall() == 0)
    {
      can[0][c1] = can[0][c2] = can[0][c3] = false;
      can[1][c1] = can[1][c2] = can[1][c3] = false;
      can[2][c1] = can[2][c2] = can[2][c3] = false;
    }
  }
  for (int i = 1; i <= 9; i++)
  {
    if (!can[0][i]) continue;
    for (int j = 1; j <= 9; j++)
    {
      if (i == j) continue;
      if (!can[1][j]) continue;
      for (int k = 1; k <= 9; k++)
      {
        if (i == k || j == k) continue;
        if (!can[2][k]) continue;
        game.playTurn(i, j, k);
        DISPTURN;
        if (game.getStrike() == 3)
        {
          DISPRES;
          return game.getTurn();
        }
      }
    }
  }

  cout << "ERROR OCCURED\n";
  return -1;
}