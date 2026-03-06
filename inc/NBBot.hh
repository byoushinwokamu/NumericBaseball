#ifndef __NBBOT_HH__
#define __NBBOT_HH__

#include "NBGame.hh"

class NBBot
{
  private:
  int cur;

  public:
  void initBot();
  int playGame(NBGame &game, bool dispTurn, bool dispRes);
};

#endif