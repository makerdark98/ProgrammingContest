#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%d", &(n))
#define pri(n) printf("%d ", (n))
#define prl(n) printf("%d ", (n))
using namespace std;
typedef int lld;
typedef pair<lld, lld> pii;
typedef vector<lld> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

int main() {
    int N;
    sci(N);
    vector<set<int> > sub;
    vector<int> visited(N+1, 0);
    queue<pii> q;
    for(int i=0;i<N;i++){
        int K;
        sci(K);
        set<int> tmp_sub;
        bool can=false;
        for(int j=0;j<K;j++) {
            int tmp;
            sci(tmp);
            if(tmp==0) can=true;
            tmp_sub.insert(tmp);
        }
        if(can) {
            q.push({i, 0});
            visited[i]=1;
        };
        sub.push_back(tmp_sub);
    }
    int e;
    sci(e);
    while(!q.empty()){
        auto f = q.front();
        q.pop();
        if(sub[f.first].count(e)!=0){
            printf("%d", f.second);
            return 0;
        }
        for(auto station:sub[f.first]){
            for(int i=0;i<sub.size();i++){
                if(!visited[i] && sub[i].count(station)!=0 && f.first!=i) {
                    q.push({i, f.second + 1});
                    visited[i]=1;
                }
            }
        }
    }
    printf("-1");
    return 0;
}
