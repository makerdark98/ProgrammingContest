#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
int q_idx;
int main(){
    vector<int> input;
    stack<int> s;
    string output;
    int n;
    scanf("%d",&n);
    input.resize(n);
    for(int i=0;i<n;i++){
        scanf("%d",&input[i]);
    }
    int i;
    for(i=1;q_idx<n;){
        if(!s.empty()&&s.top()==input[q_idx]){
            q_idx++;
            s.pop();
            output.append("-\n");
        }
        else{
            if(i==n+1) break;
            s.push(i);
            output.append("+\n");
            i++;
        }
    }
    if(i==n||!s.empty()){
        printf("NO\n");
    }
    else cout<<output;
    return 0;
}
