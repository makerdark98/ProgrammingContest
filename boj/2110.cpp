#include <iostream>
#include <vector>
#include <algorithm>
#define sci(n) scanf("%d",&(n))
using namespace std;
int N, C;
vector<int> x;
int canPlace(int k){
    int cnt=1;
    int before=x[0];
    for(int i=1;i<N;i++){
        if(x[i]-before>=k){
            before=x[i];
            cnt++;
        }
        if(cnt>=C) return true;
    }
    return false;
}
int main(){
    sci(N), sci(C);
    x.resize(N);
    for(int i=0;i<N;i++) sci(x[i]);
    sort(x.begin(), x.end());
    int s=0, e=x[N-1] - x[0];
    int k=(s+e)/2;
    while(s+1<e){
        if(canPlace(k)){
            s = k;
            k = (s+e)/2;
        }else{
            e = k;
            k = (s+e)/2;
        }
    }
    if(canPlace(e)) printf("%d\n", e);
    else printf("%d\n", s);
    return 0;
}
