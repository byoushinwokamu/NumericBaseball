#include "NBGame.hh"

#include <random>

using namespace std;

void NBGame::initGame()
{
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dis(1, 9);

  turn = strike = ball = 0;
  answer[0] = dis(gen);
  do
  {
    answer[1] = dis(gen);
  } while (answer[0] == answer[1]);
  do
  {
    answer[2] = dis(gen);
  } while (answer[0] == answer[2] || answer[1] == answer[2]);
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