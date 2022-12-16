/* Part 1
#include <fstream>
#include <iostream>
using namespace std;

int checkCycle(int cycle, int xVal) {
  if (cycle==20||cycle==60||cycle==100||cycle==140||cycle==180||cycle==220) {
        return cycle*xVal;
      }
  return 0;
}

int main() {
  int cycle=0;
  int xVal=1;
  int score=0;
  string buff;
  ifstream inst("inst");
  while (inst >> buff) {
    if (buff=="noop") {
      cycle++;
      score+=checkCycle(cycle, xVal);

    } else {
      cycle++;
      score+=checkCycle(cycle, xVal);
      cycle++;
      score+=checkCycle(cycle, xVal);
      xVal += stoi(buff);
    }
  }
  cout << score << endl;
}
*/

#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;

void checkCycle(int cycle, int xVal) {
  int spritePos = (cycle - 1) % 40;
  if (abs(xVal - spritePos) <= 1) {
    cout << "#";
  } else {
    cout << ".";
  }
  if (spritePos == 39) {
    cout << endl;
  }
}

int main() {
  int cycle = 0;
  int xVal = 1;
  string buff;
  ifstream inst("inst");
  while (inst >> buff) {
    if (buff == "noop") {
      cycle++;
      checkCycle(cycle, xVal);
    } else {
      cycle++;
      checkCycle(cycle, xVal);
      cycle++;
      checkCycle(cycle, xVal);
      xVal += stoi(buff);
    }
  }
}