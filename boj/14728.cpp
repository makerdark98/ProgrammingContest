#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MAX(int a, int b){
    return a>b?a:b;
}
int main(){
    int N,T;
    scanf("%d %d",&N,&T);
    vector<vector<int> > bag;
    bag.resize(N+1);
    for(int i=0;i<=N;i++){
        bag[i].assign(T+1, 0);
    }
    vector<pair<int, int> > s;
    s.resize(N+1);
    for(int i=1;i<=N;i++){
        scanf("%d %d",&s[i].first, &s[i].second);
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=T;j++){
            if(s[i].first>j){
                bag[i][j]=bag[i-1][j];
            }
            else{
                bag[i][j] = MAX(s[i].second + bag[i-1][j-s[i].first], bag[i-1][j]);
            }
        }
    }
    printf("%d\n", bag[N][T]);
    return 0;
}
