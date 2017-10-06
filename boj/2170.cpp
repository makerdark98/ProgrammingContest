#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    int N;
    long long sum=0;
    scanf("%d", &N);
    vector<pair<long long  , long long> > a;
    a.resize(N);
    for(int i=0;i<N;i++){
        long long tmp1, tmp2;
        scanf("%lld %lld", &tmp1, &tmp2);
        if(tmp1>tmp2){
            long long tmp=tmp1;
            tmp2 = tmp1;
            tmp1 = tmp;
        }
        a[i].first = tmp1;
        a[i].second =tmp2;
    }
    sort(a.begin(), a.end());
    pair<long long, long long> f=a[0];
    sum+=a[0].second-a[0].first;
    for(int i=1;i<N;i++){
        if(f.second>a[i].second) continue;
        else{
            if(f.second<a[i].first){
                f=a[i];
                sum+=a[i].second-a[i].first;
            }
            else{
                sum+=a[i].second-a[i].first;
                sum-=f.second-a[i].first;
                f = a[i];
            }
        }
    }
    printf("%lld\n", sum);
    return 0;
}
