#include <cstdio>
#include <cstdlib>
#include <limits.h>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
#define sci(n) scanf("%d", &(n))
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

int main(){
    int V, E, K;
    sci(V), sci(E);
    sci(K);
    vvpii edges(V+1, vpii());
    vi dis(V+1, INT_MAX);
    dis[K]=0;
    while(E--){
        int from, to , weight;
        sci(from), sci(to), sci(weight);
        edges[from].push_back({to, weight});
    }
    set<pii> active_vertices;
    active_vertices.insert({0, K});
    while(!active_vertices.empty()){
        int where = active_vertices.begin()->second;
        active_vertices.erase(active_vertices.begin());
        for(auto ed: edges[where]){
            if(dis[ed.first] > dis[where] + ed.second) {
                active_vertices.erase({dis[ed.first], ed.first});
                dis[ed.first] = dis[where] + ed.second;
                active_vertices.insert({dis[ed.first], ed.first});
            }
        }
    }

    for(int i=1;i<=V;i++){
        if(dis[i]==INT_MAX) printf("INF\n");
        else printf("%d\n", dis[i]);
    }
    return 0;
}