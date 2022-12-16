#include <iostream>
#include <fstream>
using namespace std;

//only diff for part 2 is that 4 changes to 14

bool unique(string inp) {
    for (int i=0;i<14;i++) {
        for (int j=i+1;j<14;j++) {
            if (inp[i]==inp[j]) {return false;}
        }
    }
    return true;
}

int main() {
    ifstream jamds("jamds.txt");
    string buff;
    jamds >> buff;
    for (int i=0;i<buff.length()-14;i++) {
        if (unique(buff.substr(i,14))) {
            cout << i + 14<< endl;
            break;
        }
    } 
}