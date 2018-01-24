#include <iostream>
#include <queue>
using namespace std;
#define sci(n) scanf("%d",&(n))
int N;
int A[1001], dp[1001];
int main(){
    sci(N);
    for(int i=0;i<N;i++) {
        sci(A[i]);
    }
    queue<pair<int, int> > q;
    q.push({0,0});
    while(!q.empty()){
        auto f=q.front();
        q.pop();
        if(f.first==N-1){
            printf("%d\n",f.second);
            return 0;
        }
        for(int i=1;i<=A[f.first]&&i+f.first<N;i++){
            if(!dp[i+f.first]) q.push({i+f.first, f.second+1});
            dp[i+f.first]=1;
        }
    }
    printf("-1\n");
    return 0;
}
