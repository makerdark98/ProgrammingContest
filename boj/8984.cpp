#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pll> vpll;


int main(){
    int N, L;
    ll ans=0;
    scanf("%d %d", &N, &L);
    vpll stick;
    vll t(N), d(N), tpoint(N, 0), dpoint(N, 0);
    stick.resize(N);
    for(int i=0;i<N;i++){
        scanf("%lld %lld", &stick[i].first, &stick[i].second);
        t[i]=stick[i].first;
        d[i]=stick[i].second;
    }
    sort(stick.begin(), stick.end());
    sort(t.begin(), t.end());
    sort(d.begin(), d.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    d.erase(unique(d.begin(), d.end()), d.end());


    for(int i=0;i<N;i++){
        int ti = distance(t.begin(), lower_bound(t.begin(), t.end(), stick[i].first));
        int di = distance(d.begin(), lower_bound(d.begin(), d.end(), stick[i].second));
        ll len = L + (abs(stick[i].first - stick[i].second));
        ll t= tpoint[ti], d = dpoint[di];
        tpoint[ti] = max(t, d+len);
        dpoint[di] = max(d, t+len);
        ans = max(ans, tpoint[ti]);
        ans = max(ans, dpoint[di]);
    }
    printf("%lld\n", ans);
    return 0;
}
