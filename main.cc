#include <iostream>

#include "NBBot.hh"
#include "NBGame.hh"

using namespace std;
typedef long long ll;

int main()
{
  NBGame game;
  NBBot bot;
  ll acc = 0;

  constexpr int games = 10000;
  bot.initBot();
  for (int i = 0; i < games; i++)
    acc += bot.playGame(game, false, false);

  cout << (double)acc / games;

  return 0;
}