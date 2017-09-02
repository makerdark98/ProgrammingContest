#include <iostream>
#include <stack>
using namespace std;
char end_c[4] = {' ', ' ',')', ']'};
string input;
string::iterator c;
int data(int end_idx){
    int result = 0;
    while(c<input.end()){
        if(*c==end_c[end_idx]){
            result *= end_idx;
            c++;
            break;
        }else if(*c=='('){
            c++;
            result += data(2);
        }else if(*c=='['){
            c++;
            result += data(3);
        }
    }
    if(result == 0) result = end_idx;
    return result;
}
int check(){
    stack<int> s;
    for(auto i = input.begin(); i<input.end(); i++){
        if(*i=='('){
            s.push(1);
        }
        else if(*i=='['){
            s.push(2);
        }
        else if(*i==')'){
            if(s.empty()){
                return false;
            }else if(s.top()!=1){
                return false;
            }
            s.pop();
        }
        else if(*i==']'){
            if(s.empty()){
                return false;
            }else if(s.top()!=2){
                return false;
            }
            s.pop();
        }
    }
    if(!s.empty()) return false;
    return true;
}
int main(){
    cin>>input;
    c=input.begin();
    int result =0;
    if(check()==false){
        printf("0\n");
        return 0;
    }
    while(c<input.end()){
        if(*c=='('){
            c++;
            result += data(2);
        }
        else if(*c=='['){
            c++;
            result += data(3);
        }
    }
    printf("%d\n", result);
    return 0;
}
