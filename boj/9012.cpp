#include <iostream>
#include <stack>
using namespace std;
int main(){
    int T;
    string input;
    scanf("%d\n",&T);
    while(T--){
        bool check = true;
        getline(cin,input);
        stack<int> s;
        for(auto c=input.begin();c<input.end();c++){
            if(*c=='('){
                s.push(1);
            }
            else if(*c==')'){
                if(s.empty()){
                    check = false;
                    break;
                }
                s.pop();
            }
        }
        if(!s.empty()) check =false;
        if(check) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
