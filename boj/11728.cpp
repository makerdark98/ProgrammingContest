#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N, M;
    scanf("%d %d",&N,&M);
    vector<int> a, b;
    for(int i=0;i<N;i++){
        int tmp;
        scanf("%d",&tmp);
        a.push_back(tmp);
    }
    for(int i=0;i<M;i++){
        int tmp;
        scanf("%d",&tmp);
        b.push_back(tmp);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ai=0, bi=0;
    while(ai<N||bi<M){
        if(ai==N){
            printf("%d ",b[bi++]);
        }
        else if(bi==M){
            printf("%d ",a[ai++]);
        }
        else{
            if(a[ai]<b[bi]){
                printf("%d ",a[ai++]);
            }
            else{
                printf("%d ",b[bi++]);
            }
        }
    }
    return 0;
}