#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N,M;
vector<vector<int> > al;
vector<int> solo;
vector<int> visited;
int chk(int idx){
    for(int i=idx+1, k =solo.size();i<N;i++){
        
    }
}
int main(){
    scanf("%d %d",&N,&M);
    al.resize(N);
    visited.assign(N,0);
    for(int i=0;i<M;i++){
        int a, b;
        scanf("%d %d",&a,&b);
        al[a].push_back(b);
        al[b].push_back(a);
    }
    for(int i=0;i<N;i++){
        if(al[i].size()==1) solo.push_back(i);
    }
    int cnt=0;
    for(int i=0, k = solo.size(); i<k ;i++){
        if(//check)
        else{
            cnt++;
        }
    }
    int ans = (cnt/2)+cnt%2;
    printf("%d\n",ans);
    return 0;
}
