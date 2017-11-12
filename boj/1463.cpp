#include <iostream>
#include <queue>
#define sci(n) scanf("%d",&(n))
using namespace std;
typedef pair<int, int> pii;
int chk[1000001];
int main(){
    queue<pii> q;
    int n;
    sci(n);
    q.push({n,0});
    while(!q.empty()){
        auto f = q.front();
        q.pop();
        if(f.first==1){
            printf("%d\n",f.second);
            return 0;
        }
        if(chk[f.first]==0){
            chk[f.first]=f.second;
            if(f.first%3==0) q.push({f.first/3, f.second+1});
            if(f.first%2==0) q.push({f.first/2, f.second+1});
            q.push({f.first-1, f.second+1});
        }
    }
    return 0;
}
