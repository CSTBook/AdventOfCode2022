#include <iostream>
#include <fstream>

int main() {
    std::string buff;
    std::ifstream strats("strat");
    int score=0;
    while (std::getline(strats, buff)) {
        if (buff[0]=='A') {
            if (buff[2]=='X') {score+=3;}
            else if (buff[2]=='Y') {score+=4;}
            else {score+=8;}
        } else if (buff[0]=='B') {
            if (buff[2]=='X') {score+=1;}
            else if (buff[2]=='Y') {score+=5;}
            else {score+=9;}
        } else {
            if (buff[2]=='X') {score+=2;}
            else if (buff[2]=='Y') {score+=6;}
            else {score+=7;}
        }
        //a - rock, b - paper, c - scissors  ||||   x - lose, y - draw, z - win
    }
    std::cout<<score<<std::endl;
}