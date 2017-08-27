#include <iostream>
#include <stack>
using namespace std;

stack<char> Operator;
int checkPriority(char c){
    switch(c){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
            return 0;
    }
}
int main() {
    int i, k;
    char c;
    string str;
    getline(cin, str);
    k=str.length();
    for(i=0;i<k;i++) {
        c = str.at(i);
        switch (c) {
            case '+':
            case '-':
                while (!Operator.empty() && checkPriority(c)<=checkPriority(Operator.top())) {
                    printf("%c", Operator.top());
                    Operator.pop();
                }
                Operator.push(c);
                break;
            case '*':
            case '/':
                while (!Operator.empty() && checkPriority(c)<=checkPriority(Operator.top())) {
                    printf("%c", Operator.top());
                    Operator.pop();
                }
                Operator.push(c);
                break;
            case '(':
                Operator.push(c);

                break;
            case ')':
                while (!Operator.empty() && Operator.top() != '(') {
                    printf("%c", Operator.top());
                    Operator.pop();
                }
                if(!Operator.empty()){
                    Operator.pop();
                }
                break;
            default:
                printf("%c", c);
        }

    }
    while (!Operator.empty()) {
        printf("%c", Operator.top());
        Operator.pop();
    }
    return 0;
}
