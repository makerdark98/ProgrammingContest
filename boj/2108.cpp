#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    scanf("%d", &N);
    vector<int> a(N, 0);
    vector<int> b(10000, 0);
    int sum =0;
    int minv=5000, maxv=-5000;
    for(int i=0;i<N;i++){
        scanf("%d", &a[i]);
        b[5000+a[i]]++;
        sum+=a[i];
        minv=min(minv, a[i]);
        maxv=max(maxv, a[i]);
    }
    printf("%.0lf\n", ((double)sum)/N);
    sort(a.begin(), a.end());
    printf("%d\n", a[N/2]);
    int common=a[0]+5000;
    for(int i=-4010;i<4010;i++){
        if(b[common+5000]<b[i+5000]) common=i;
    }
    int cnt=0;
    for(int i=-4010;i<4010;i++){
        if(b[common+5000]==b[i+5000]) cnt++;
        if(cnt==2){
            common=i;
            break;
        }
    }
    printf("%d\n",common);
    printf("%d\n",maxv-minv);
    return 0;
}
