#include "NBBot.hh"

#include <iostream>

using namespace std;

void NBBot::initBot()
{
  cur = 0;
}

int NBBot::playGame(NBGame &game, bool dispTurn, bool dispRes)
{
  game.initGame();
  initBot();
  int c1, c2, c3;
  while (game.getStrike() < 3)
  {
    while (true)
    {
      cur++;
      if (cur > 999)
      {
        cout << "LOSE..\n";
        return -1;
      }
      c1 = cur % 10;
      c2 = cur / 10 % 10;
      c3 = cur / 100;
      if (c1 * c2 * c3 == 0) continue;
      if (c1 == c2 || c2 == c3 || c3 == c1) continue;
      break;
    }

    game.playTurn(c1, c2, c3);
    if (dispTurn)
    {
      cout << "Bot played " << cur << '\n';
      cout << game.getStrike() << " strikes, " << game.getBall() << " balls\n";
    }
  }
  if (dispRes)
  {
    cout << "Bot won in " << game.getTurn() << " turns\n";
  }
  return game.getTurn();
}