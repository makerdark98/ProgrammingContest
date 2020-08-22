#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define sci(N) scanf("%d", &(N))
using namespace std;
#define MAX_V 10010
#define INF 987654321

struct seg_tree {
    int bs = 1 << 20;
    pair<int, int> node[1 << 21];
    void add(int x, pair<int, int> v) {
        x |= bs;
        node[x] = v;
        while (x > 1) {
            x >>= 1;
            node[x] = node[x * 2].first > node[x * 2 + 1].first ?
                node[x * 2] : node[x * 2 + 1];
        }
    }
    
    pair<int, int> query(int s, int e) {
        s |= bs;
        e |= bs;
        pair<int, int> retval = {0, 0};
        while (s < e) {
            if (s % 2 == 1) {
                retval = retval.first > node[s].first ? retval : node[s];
                s ++;
            }
            if (e % 2 == 0) {
                retval = retval.first > node[e].first ? retval : node[e];
                e --;
            }
            s >>= 1;
            e >>= 1;
        }
        if (s == e)
            retval = retval.first > node[s].first ? retval : node[s];
        return retval;
    }
}seg;

int N, A[1010];
int main () {
    sci(N);
    for (int i = 0; i < N; i ++) {
        sci(A[i]);
    }
    for (int i = 0; i < N; i ++) {
        pair<int, int> tmp = seg.query(0, A[i]-1);
        tmp.first ++;
        tmp.second = A[i];
        seg.add(A[i], tmp);
    }
    
    pair<int, int> tmp = seg.query(0, 101000);
    int result = tmp.first;
    int a = tmp.second;
    printf("%d\n", result);
    vector<int> re;
    
    for (int i = 0; i < result; i ++) {
        re.push_back(a);
        a = seg.query(0, a-1).second;
    }
    reverse(re.begin(), re.end());
    for (auto& r : re) {
        printf("%d ", r);
    }
    return 0;
}
