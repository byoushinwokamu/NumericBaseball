#ifndef __NBGAME_HH__
#define __NBGAME_HH__

class NBGame
{
  private:
  int turn;
  int strike;
  int ball;
  int answer[3];

  public:
  void initGame();
  bool playTurn(int a, int b, int c);
  int getTurn();
  int getStrike();
  int getBall();
};

#endif