#include <iostream>
#include <vector>
#include <map>
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%lld", &(n))
using namespace std;
using lld = long long;
using vi = vector<lld>;
using vvi = vector<vi>;
using pii = pair<lld, lld>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;

vvpii g;
vi col;
lld D;
void dfs(lld )
int main() {
    int n, k;
    sci(n), sci(k);
    g.resize(n);
    vi d(n);
    for(int i=0;i<n-1;i++){
        lld x, y;
        scl(x), scl(y);
        x--, y--;
        g[x].push_back({y, i});
        g[y].push_back({x, i});
        d[x]++, d[y]++;
    }
    map<int, int> cnt;
    for(int dd: d)
        cnt[dd]++;

    int kk = n;
    D = 0;
    for(auto p:cnt){
        if(kk>k){
            D=p.first;
            kk-=p.second;
        } else {
            break;
        }
    }
    col = vi(n-1);
    dfs(0, -1, -1);
    printf("%lld\n", D);
    for(int i=0;i<n-1;i++){
        printf("%lld ", col[i]+1);
    }
    return 0;
}
