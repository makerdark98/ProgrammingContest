#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define sci(n) scanf("%lld",&(n))
#define MAX 10e15
using namespace std;
typedef long long lld;
typedef pair<lld, lld> pii;
typedef vector<pii> vpii;
lld N;
vpii data;
lld scp(lld,lld);
lld di(pii a,pii b){
    return (a.first-b.first)*(a.first-b.first)
        +(a.second-b.second)*(a.second-b.second);
}
int main(){
    sci(N);
    data.resize(N);
    for(int i=0;i<N;i++) sci(data[i].first), sci(data[i].second);
    sort(data.begin(), data.end());
    printf("%lld\n", scp(0,N-1));
    return 0;
}
lld scp(lld s, lld e){
    if(s==e) return MAX;
    if(s+1==e) return di(data[s],data[e]);
    lld m = (s+e)/2;
    lld cp = min(scp(s,m), scp(m+1, e));
    lld d = sqrt(cp);
    lld line = (data[m].first+data[m+1].first)/2;
    vpii tmp;
    for(lld i=m;i<=e&&abs(line-data[i].first)<=d;i++) tmp.push_back(data[i]);
    for(lld i=m-1;i>=s&&abs(line-data[i].first)<=d;i--) tmp.push_back(data[i]);
    sort(tmp.begin(),tmp.end(),[](pii a,pii b){
            return a.second<b.second;
            });
    for(lld i=0;i<tmp.size();i++){
        for(lld j=i+1;j<tmp.size()&&j<=i+6;j++){
            cp = min(cp,di(tmp[i],tmp[j]));
        }
    }
    return cp;
}
