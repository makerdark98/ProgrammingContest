#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using lld = long long;
using vi = vector<lld>;
#define sci(n) scanf("%d",&(n))
#define scl(n) scanf("%lld",&(n))
#define max(a, b) ((a) > (b) ? (a) : (b))
lld solve(vi& data);
int main() {
    int C;
    sci(C);
    while (C--){
        int N;
        sci(N);
        vi data(N);
        for(int i=0;i<N;i++){
            scl(data[i]);
        }
        printf("%lld\n", solve(data));
    }
    return 0;
}
lld solve(vi& data){
    stack<size_t> s;
    lld result = 0;
    s.push(0);
    for(size_t i=1;i<data.size();i++){
        if(s.empty() || data[s.top()] <= data[i]) {
            s.push(i);
        } else {
            while(!s.empty() && data[s.top()] > data[i]) {
                result = max(result, data[s.top()] * (i - s.top()));
                s.pop();
            }
        }
    }
    while(!s.empty()) {
        result = max(result, data[s.top()]*(data.size() - s.top()));
        s.pop();
    }
    return result;
}
