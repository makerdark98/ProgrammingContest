#include <iostream>
#include <vector>
#include <queue>
#define MAX 9999999
using namespace std;
int N, K;
int main(){
    scanf("%d %d",&N, &K);
    queue<int> q;
    vector<int> s;
    vector<int> check;
    if(N>=K){
        printf("%d\n", N-K);
        return 0;
    }
    s.assign(K*7,MAX);
    check.assign(K*7, 0);
    s[N] = 0;
    q.push(N);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        if(t<1||t>2*K||check[t]) continue;
        check[t]=1;
        if(s[t*2]>s[t]+1){
            s[t*2]=s[t]+1;
            q.push(t*2);
        }
        if(s[t-1]>s[t]+1){
            s[t-1]=s[t]+1;
            q.push(t-1);
        }
        if(s[t+1]>s[t]+1){
            s[t+1]=s[t]+1;
            q.push(t+1);
        }
    }
    printf("%d\n", s[K]);
    return 0;
}
