#include <iostream>
#include <vector>
using namespace std;
int main(){

    int N, K;
    scanf("%d %d",&N,&K);
    vector<int> a(N);
    char tmp;
    for(int i=0;i<N-1;i++){
        scanf("%d",&a[i]);
        scanf(" %c",&tmp);
    }
    scanf("%d", &a[N-1]);
    for(int j=0;j<K;j++){
        for(int i=0;i<N-j-1;i++){
            a[i]=a[i+1]-a[i];
        }
    }
    for(int i=0;i<N-K-1;i++){
        printf("%d,",a[i]);
    }
    printf("%d\n",a[N-K-1]);
    return 0;
}
