#ifndef __NBBOT_HH__
#define __NBBOT_HH__

#include "NBGame.hh"

class NBBot
{
  private:
  int gameResult;
  long long gameResultAcc;
  int gameCount;

  public:
  void initBot();
  int getResult();
  double getAverage();
  int playGame(NBGame &game, bool dispTurn, bool dispRes);
};

#endif