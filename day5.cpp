#include <iostream>
#include <fstream>
#define NUM_STACKS 9
using namespace std;

class StackNode {
    public:
    char val;
    StackNode* next;
    StackNode(char val, StackNode* next) {
        this->val=val;
        this->next=next;
    }
};

class Stack {
    StackNode* top;
    public:
    Stack() {
        this->top=NULL;
    }
    void Add(char val) {
        if (!top) {top = new StackNode(val, NULL);return;}
        StackNode* temp = top;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new StackNode(val, NULL);
    }
    void Move(char val) {
        StackNode* temp = new StackNode(val, top);
        top = temp;
        cout << "";
    }
    /* Part 1
    char Pop() {
        if (top==NULL) {return '.';}
        StackNode* temp = top;
        top = top->next;
        return temp->val;
    }
    */
    char Pop(int lvl=1) {
        if (top==NULL) {return '.';}
        StackNode* temp = top;
        if (lvl==1) {top=top->next;return temp->val;}
        for (int i=1;i<lvl-1;i++) {
            temp = temp->next;
        }
        char tempVal =temp->next->val; 
        temp->next=temp->next->next;
        return tempVal;
    }
};

int main() {
    Stack stacks[NUM_STACKS] = {Stack()};
    ifstream cargo("cargo.txt");
    string buff;
    for (int i=0;i<NUM_STACKS;i++) {
        getline(cargo, buff);
        for (int j=0;j<NUM_STACKS;j++) {
            char temp = buff[1+j*4];
            if (temp!=' ') {
                stacks[j].Add(temp);
            }
        }
    }
    int mv, fm, to;
    while (cargo >> mv >> fm >> to) {
        for (int i=0;i<mv;i++) {
            /*Part 1
            stacks[to-1].Move(stacks[fm-1].Pop());
            */
            stacks[to-1].Move(stacks[fm-1].Pop(mv-i));
        }
    }
    for (int i=0;i<NUM_STACKS;i++) {
        cout << stacks[i].Pop();
    }
    cout << endl;
}