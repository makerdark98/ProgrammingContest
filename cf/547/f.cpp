#include <iostream>
#include <vector>
#include <map>
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%lld", &(n))
using namespace std;
using lld = long long;
using vi = vector<lld>;
using pii = pair<lld, lld>;
using vpii = vector<pii>;

int main () {
    int n;
    sci(n);
    vi dp(n+1, 0);
    for(int i=1;i<=n;i++){
        int t;
        sci(t);
        dp[i] = dp[i-1] + t;
    }
    map<lld, vpii> segs;
    for(int j=n;j>=0;j--){
        for(int i=j;i>=0;i--){
            segs[dp[j]-dp[i-1]].push_back({i,j});
        }
    }

    lld result=0;
    vpii result_pairs;
    for(auto& seg: segs) {
        lld cur = seg.second[0].first;
        int cnt = 1;
        vpii data;
        data.push_back(seg.second[0]);
        for(size_t i = 1; i<seg.second.size();i++){
            if (cur > seg.second[i].second) {
                cnt++;
                cur = seg.second[i].first;
                data.push_back(seg.second[i]);
            }
        }

        if(result < cnt) {
            result = cnt;
            result_pairs = data;
        }
    }

    printf("%lld\n", result);
    for(auto& r:result_pairs) {
        printf("%lld %lld\n", r.first, r.second);
    }
    return 0;
}
