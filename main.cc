#include <iostream>

#include "NBBot.hh"
#include "NBGame.hh"

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
  NBGame game;
  NBBot bot;
  ll acc = 0;

  int games;
  // cout << "Games to play? ";
  // cin >> games;
  cout << "100000 games\n";
  games = 100000;
  bot.initBot();
  for (int i = 0; i < games; i++)
  {
    game.initGame();
    acc += bot.playGame(game, false, false);
  }

  // cout << "Average try: " << bot.getResult();
  cout << "Average try: " << (double)acc / games;

  return 0;
}