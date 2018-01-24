#include <iostream>
#include <vector>
#define sci(n) scanf("%lld", &(n))
using namespace std;
typedef long long lld;
typedef vector<int> vi;
typedef vector<vi> vvi;
lld N;
vvi m;
int ans[3];
void solve(int s, int r, int c){
    int t=m[r][c];
    for(int i=r;i<r+s;i++){
        for(int j=c;j<c+s;j++){
            if(t!=m[i][j]){
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        solve(s/3,r+s/3*k,c+s/3*l);
                    }
                }
                return;
            }
        }
    }
    ans[t]++;
}

int main(){
    sci(N);
    m.assign(N, vi(N,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&(m[i][j]));
            if(m[i][j]==-1) m[i][j]=0;
            else if(m[i][j]==0) m[i][j]=1;
            else m[i][j]=2;
        }
    }
    solve(N,0,0);
    for(int i=0;i<3;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
