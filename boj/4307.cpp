#include <iostream>
using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int l, n;
        int mini=0, maxi=0;
        scanf("%d %d",&l, &n);
        for(int i=0;i<n;i++){
            int a;
            scanf("%d", &a);
            mini=max(mini, min(a,l-a));
            maxi=max(maxi, max(a,l-a));
        }
        printf("%d %d\n",mini,maxi);
    }
    return 0;
}
