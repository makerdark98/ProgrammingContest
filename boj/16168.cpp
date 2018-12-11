#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%lld", &(n))
#define pri(n) printf("%d ", (n))
#define prl(n) printf("%lld ", (n))
using namespace std;
typedef long long lld;
typedef pair<lld, lld> pii;
typedef vector<lld> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

lld find(vi& c, lld x){ return (c[x]==x) ? x : c[x]=find(c,c[x]);}
void merge(vi& c,lld x, lld y){c[find(c,x)]=find(c,y);}
int main() {
    lld v, e;
    scl(v), scl(e);
    vi forest(v+1);
    vi degree(v+1, 0);
    for(lld i=1;i<=v;i++) forest[i]=i;
    for(lld i=0;i<e;i++){
        lld a, b;
        scl(a),scl(b);
        degree[a]++;
        degree[b]++;
        merge(forest, a, b);
    }
    for(lld i=2;i<=v;i++){
        if(find(forest,1)!=find(forest,i)){
            printf("NO");
            return 0;
        }
    }
    lld cnt=0;
    for(lld i=1;i<=v;i++){
        if(degree[i]%2==1) cnt++;
    }
    if(cnt==0 || cnt==2) printf("YES");
    else printf("NO");
    return 0;
}
