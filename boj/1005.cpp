#include <iostream>
#include <vector>
#include <queue>
#define sci(n) scanf("%d",&(n))
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
int main(){
    int T;
    sci(T);
    while(T--){
        int N, K;
        sci(N),sci(K);
        vi D(N+1);
        vi indeg(N+1, 0);
        vi dp(N+1,0);
        for(int i=1;i<=N;i++){
            sci(D[i]);
        }
        vector<vi> rule(N+1);
        for(int i=0;i<K;i++){
            int a, b;
            sci(a),sci(b);
            rule[a].push_back(b);
            indeg[b]++;
        }
        int W;
        sci(W);
        queue<pii> q;
        for(int i=1;i<=N;i++){
            if(indeg[i]==0){
                q.push({i,0});
            }
        }
        while(!q.empty()){
            pii f = q.front();
            indeg[f.first]--;
            q.pop();
            if(dp[f.first]<f.second+D[f.first]){
                dp[f.first]=f.second+D[f.first];
            }
            if(indeg[f.first]<=0){
                for(int i=0;i<rule[f.first].size();i++){
                    q.push({rule[f.first][i], dp[f.first]});
                }
            }
        }
        printf("%d\n",dp[W]);
    }
    return 0;
}
