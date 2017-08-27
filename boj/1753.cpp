#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int V, E, K;

int dist[20001];

queue<int> q;
vector<pair<int, int>> edge[20001]; //index : from, first : to, second: cost

int main(){
    scanf("%d %d", &V, &E);
    scanf("%d", &K);
    for(int i=1;i<=V;i++){
        dist[i] = -1;
        q.push(i);
    }
    dist[K] = 0;
    for(int i=0;i<E;i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edge[u].push_back(make_pair(v, w));
        if(u == K){
            dist[v]= w;
        }
    }
    while(!q.empty()){
        int i = q.front();
        q.pop();
        int length = edge[i].size();
        for (int j = 0; j < length; j++) {
            if (dist[i] != -1) {
                if(dist[edge[i][j].first]==-1){
                    dist[edge[i][j].first] = dist[i]+edge[i][j].second;
                    q.push(edge[i][j].first);
                }
                if (dist[i] + edge[i][j].second < dist[edge[i][j].first]) {
                    dist[edge[i][j].first] = dist[i] + edge[i][j].second;
                    q.push(edge[i][j].first);
                }
            }
        }
    }

    for(int i=1;i<=V;i++){
        if(dist[i]==-1){
            printf("INF\n");
        }
        else{
            printf("%d\n", dist[i]);
        }
    }
    return 0;
}