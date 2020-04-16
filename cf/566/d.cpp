#include <iostream>
#include <vector>
#include <queue>
#define sci(n) scanf("%d", &(n))
using namespace std;
using lld = int;
using vi = vector<lld>;
using vvi = vector<vi>;
int main() {
    int n;
    sci(n);
    vi deg(n+1, 0);
    vi visited(n+1, 0);
    vvi edges(n+1);
    if(n==1) {
        printf("1");
        return 0;
    }
    for(int i=1;i<n;i++){
        int v1, v2;
        sci(v1), sci(v2);
        deg[v1] ++;
        deg[v2] ++;
        edges[v1].push_back(v2);
        edges[v2].push_back(v1);
    }
    queue<int> q1, q2;
    queue<int>* cur = &q1;
    queue<int>* nex = &q2;
    for(int i=1;i<=n;i++){
        if(deg[i]==1) {
            nex->push(i);
            visited[i] = 1;
        }
    }
    while(nex->size() != 1) {
        if(nex->size() == 0) {
            printf("-1");
            return 0;
        }
        queue<int>* tmp = cur; cur = nex; nex = tmp;
        while(!cur->empty()) {
            int f = cur->front();
            cur->pop();
            for(int i=0;i<edges[f].size();i++){
                if(!visited[edges[f][i]]) {
                    deg[edges[f][i]] --;
                    if(deg[edges[f][i]] == 1) {
                        visited[edges[f][i]] = 1;
                        nex->push(edges[f][i]);
                    }
                }
            }
        }
    }
    printf("%d",nex->front());
    return 0;
}
