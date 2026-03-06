#ifndef __NBBOT_HH__
#define __NBBOT_HH__

#include "NBGame.hh"
#include <vector>

class NBBot
{
  private:
  int cur;

  public:
  void initBot();
  int playGame(NBGame &game, bool dispTurn, bool dispRes);
};

#endif