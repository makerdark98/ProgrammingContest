#include <iostream>
#include <vector>
#include <algorithm>
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%lld", &(n))
#define pri(n) printf("%d ", n);
#define prl(n) printf("%lld ", n);

using namespace std;
using lld = long long;
using vi = vector<lld>;
using vvi = vector<vi>;
using pii = pair<lld, lld>;
using vpii = vector<pii>;

int main() {
    int N;
    sci(N);
    vpii data(N);
    for(int i=0;i<N;i++){
        lld t;
        scl(data[i].first); scl(t); scl(data[i].second); scl(t);
    }
    sort(data.begin(), data.end(), [](const pii& a, const pii& b)->bool {
            if (a.second == b.second) return a.first < b.first;
            return a.second < b.second;
            });

    lld result = 0;

    for(size_t i=0;i<(size_t)N;i++){
        printf("%lld %lld\n", data[i].first, data[i].second);
    }
    return 0;
}
