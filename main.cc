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

  int games;
  cout << "Games to play? ";
  cin >> games;
  bot.initBot();
  for (int i = 0; i < games; i++)
    acc += bot.playGame(game, false, false);

  cout << "Average try: " << (double)acc / games;

  return 0;
}