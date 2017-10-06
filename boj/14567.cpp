#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    vector<vector<int> > p;
    vector<int> indeg, ans;
    queue<int> q;
    p.resize(N+1);
    indeg.assign(N+1,0);
    ans.assign(N+1, 0);
    for(int i=0;i<M;i++){
        int a, b;
        scanf("%d %d",&a, &b);
        indeg[b]++;
        p[a].push_back(b);
    }
    for(int i=1;i<=N;i++){
        if(indeg[i]==0) {
          q.push(i);
          ans[i]=1;
        }
    }
    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(auto i = p[f].begin(); i<p[f].end();i++){
            indeg[*i]--;
            if(indeg[*i]==0){
                ans[*i]=ans[f]+1;
                q.push(*i);
            }
        }
    }
    for(int i=1;i<=N;i++){
        printf("%d ",ans[i]);
    }

    return 0;
}
