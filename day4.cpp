/* PART 1
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream assns("assns");
    string p1, p2;
    int score=0;
    while (getline(assns, p1, ',')&&getline(assns, p2, '\n')) {
       if ((stoi(p1.substr(0,p1.find("-"))) <= stoi(p2.substr(0,p2.find("-"))) && stoi(p1.substr(p1.find("-")+1,p1.length())) >= stoi(p2.substr(p2.find("-")+1,p2.length())))
       || (stoi(p1.substr(0,p1.find("-"))) >= stoi(p2.substr(0,p2.find("-"))) && stoi(p1.substr(p1.find("-")+1,p1.length())) <= stoi(p2.substr(p2.find("-")+1,p2.length()))) ){score++;}
    }
    cout << score << endl;
}
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream assns("assns");
    string p1, p2;
    int score=0;
    while (getline(assns, p1, ',')&&getline(assns, p2, '\n')) {
        if ((stoi(p1.substr(0,p1.find("-"))) <= stoi(p2.substr(0,p2.find("-"))))) {
            if ((stoi(p1.substr(p1.find("-")+1,p1.length())) >= stoi(p2.substr(0,p2.find("-"))))) {
                score++;
            }   
        } else if ((stoi(p2.substr(0,p2.find("-"))) <= stoi(p1.substr(0,p1.find("-"))))) {
            if ((stoi(p2.substr(p2.find("-")+1,p2.length())) >= stoi(p1.substr(0,p1.find("-"))))) {
                score++;
            }   
        }
    }
    cout << score << endl;
}