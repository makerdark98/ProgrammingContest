#include <bits/stdc++.h>
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%lld", &(n))
#define pri(n) printf("%d\n", (n))
#define prl(n) printf("%lld", (n))
using namespace std;
typedef long long lld;
typedef pair<lld, lld> pii;
typedef vector<lld> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
#define TMAX 10e9L

int N, M, K;
int dr[]={0,0,1,-1};
int dc[]={1,-1,0,0};
vvi input;
lld check(lld t){
    lld result=0;
    queue<pii> q;
    vvi visited(N+2, vi(M+2, 0));
    for(int i=1;i<=M;i++)
        if(!visited[1][i] && input[1][i]<=t) {
            visited[1][i]=1;
            q.push({1, i});
            result++;
        }
    for(int i=1;i<=N;i++)
        if(!visited[i][1] && input[i][1]<=t) {
            visited[i][1]=1;
            q.push({i, 1});
            result++;
        }
    for(int i=1;i<=N;i++)
        if(!visited[i][M] && input[i][M]<=t) {
            visited[i][M]=1;
            q.push({i, M});
            result++;
        }

    while(!q.empty()){
        auto f=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            if(!visited[f.first+dr[i]][f.second+dc[i]] && input[f.first+dr[i]][f.second+dc[i]]<=t){
                result++;
                visited[f.first+dr[i]][f.second+dc[i]]=1;
                q.push({f.first+dr[i], f.second+dc[i]});
            }
        }
    }
    return result;
}

int main(){
    sci(N), sci(M), sci(K);
    input.assign(N+2, vi(M+2, TMAX));
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            scl(input[i][j]);

    lld s=0, mid, e=10e7L;
    while(s!=e){
        mid = (s+e)/2;
        if(check(mid)<K) s = mid+1;
        else e = mid;
    }
    printf("%lld", s);

    return 0;
}
