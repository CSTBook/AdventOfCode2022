/* Part 1

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    std::ifstream sack("sack");
    std::string buff;
    int score=0;
    while (sack>>buff) {
        
        std::string str1 = buff.std::string::substr(0,buff.length()/2);
        std::string str2 = buff.std::string::substr(buff.length()/2,buff.length()-1);
        //cout << str1 << endl << str2 << endl;
        for (int i=0;i<str1.length();i++) {
            for (int j=0;j<str2.length();j++) {
                if (str1[i]==str2[j]) {
                    score += (int)str1[i] - ((int)str1[i] < 91 ? 38 : 96);
                    goto outLoop;
                }
            }
        }
        outLoop:
        score+=0;
    }
    std::cout<<score<<std::endl;
}
*/
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    std::ifstream sack("sack");
    int score=0;
    string str1, str2, str3;
    while (getline(sack, str1)&&getline(sack, str2)&&getline(sack, str3)) {
        for (int i=0;i<str1.length();i++) {
            for (int j=0;j<str2.length();j++) {
                if (str1[i]==str2[j]) {
                    for (int k=0;k<str3.length();k++) {
                        if (str2[j]==str3[k]) {
                            score += (int)str1[i] - ((int)str1[i] < 91 ? 38 : 96);
                            goto outLoop;
                        }
                    }
                }
            }
        }
        outLoop:
        score;
    }
    cout << score << endl;
}