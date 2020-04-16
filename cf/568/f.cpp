#include <iostream>
#include <vector>
using namespace std;
#define sci(n) scanf("%d", &(n))
using lld = long long;
using vi = vector<lld>;
using vvi = vector<vi>;
using pii = pair<lld, lld>;
using piii = pair<lld, pii>;
using vpiii = vector<piii>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
int n, m;
int main () {
    int n, m;
    sci(n), sci(m);
    vector<bool> wanted(1024, false);
    for(int i=0;i<n;i++) {
        int t;
        sci(t);
        int d=0;
        while(t--) {
            int a;
            sci(a);
            d |= 1 << (a-1);
        }
        wanted[d] = true;
    }
    vvpii data(1024, vpii(2, {10e9+7, 0}));
    for(int i=0;i<m;i++){
        int money;
        sci(money);
        int t;
        sci(t);
        int in=0;
        while(t--){
            int a;
            sci(a);
            in |= 1<<(a-1);
        }
        if(data[in][0].first > money) {
            data[in][1] = data[in][0];
            data[in][0] = {money, i};
        } else if (data[in][1].first > money ) {
            data[in][1] = {money, i};
        }
    }

    vpiii dp(1024, {10e9+7, {-1, -1}});
    for(int i=0;i<1024;i++) {
        for(int j=i+1;j<1024;j++) {
            if (dp[i|j].first > data[i][0].first + data[j][0].first) {
                dp[i|j].first = data[i][0].first + data[j][0].first;
                dp[i|j].second = {data[i][0].second, data[j][0].second};
            }
        }
        if(dp[i].first > data[i][0].first + data[i][1].first) {
            dp[i].first = data[i][0].first + data[i][1].first;
            dp[i].second = { data[i][0].second , data[i][1].second};
        }
    }
    piii result = {10e9+7, {-1, -1}};
    for(int i=0;i<1024;i++) {
        for(int j=0;j<1024;j++) {
            if(wanted[j] && (i&j) != 0 && result.first > dp[i].first) {

                result = dp[i];
            }
        }
    }
    printf("%lld %lld", result.second.first+1, result.second.second+1);
    return 0;
}
