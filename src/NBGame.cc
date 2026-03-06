#include "NBGame.hh"

#include <cstdlib>
#include <ctime>

using namespace std;

void NBGame::initGame()
{
  srand(time(NULL));
  turn = 0;
  answer[0] = rand() % 9 + 1;
  answer[1] = rand() % 9 + 1;
  answer[2] = rand() % 9 + 1;
}

bool NBGame::playTurn(int a, int b, int c)
{
  turn++;
  strike = ball = 0;
  if (a == answer[0]) strike++;
  else if (a == answer[1] || a == answer[2]) ball++;
  if (b == answer[1]) strike++;
  else if (b == answer[0] || b == answer[2]) ball++;
  if (c == answer[2]) strike++;
  else if (c == answer[0] || c == answer[1]) ball++;

  return strike == 3;
}

int NBGame::getTurn() { return turn; }
int NBGame::getStrike() { return strike; }
int NBGame::getBall() { return ball; }