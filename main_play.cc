#include <iostream>

#include "NBGame.hh"

using namespace std;

int main()
{
  NBGame game;
  int a, b, c;

  while (true)
  {
    game.initGame();
    cout << "Game Initialized\n";
    do
    {
      cin >> a >> b >> c;
      game.playTurn(a, b, c);
      cout << game.getStrike() << " strikes, " << game.getBall() << " balls\n";
    } while (game.getStrike() < 3);
    cout << "3 strikes, you won in " << game.getTurn() << " turns\n\n";
  }
}