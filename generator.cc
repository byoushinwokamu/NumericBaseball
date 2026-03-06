#include <iostream>

using namespace std;

int main()
{
  for (int i = 1; i < 10; i++)
  {
    for (int j = 1; j < 10; j++)
    {
      if (i == j) continue;
      for (int k = 1; k < 10; k++)
      {
        if (i == k || j == k) continue;
        cout << "{" << i << ", " << j << ", " << k << "},";
      }
    }
  }
}