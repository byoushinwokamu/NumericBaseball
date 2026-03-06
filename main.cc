#include <iostream>
#include <stdexcept>
#include <string>

#include "NBBot.hh"
#include "NBGame.hh"

using namespace std;

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    cerr << "Usage: " << argv[0] << " <number_of_games>\n";
    cerr << "Example: " << argv[0] << " 100000\n";
    return 1;
  }

  int games = 0;

  try
  {
    games = stoi(argv[1]);

    if (games <= 0)
    {
      cerr << "Error: must be positive integer\n";
      return 1;
    }
  }
  catch (const invalid_argument &e)
  {
    cerr << "Error: must be positive integer\n";
    return 1;
  }
  catch (const out_of_range &e)
  {
    cerr << "Error: too large\n";
    return 1;
  }

  NBGame game;
  NBBot bot;
  long long acc = 0;

  cout << games << " games\n";

  for (int i = 0; i < games; i++)
  {
    game.initGame();
    acc += bot.playGame(game, false, false);
  }

  cout << "Average try: " << (double)acc / games << "\n";

  return 0;
}