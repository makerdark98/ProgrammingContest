#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int c;
        scanf("%d", &c);
        map<string, int> data;
        for(int i=0;i<c;i++) {
            string a,b;
            cin>>a>>b;
            data[b]++;
        }
        int ans=1;
        for(auto c:data) {
            data[c.first]++;
            ans*=data[c.first];
        }
        printf("%d\n",ans-1);
    }
    return 0;
}
