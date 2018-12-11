#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%lld", &(n))
#define pri(n) printf("%d ", (n))
#define prl(n) printf("%lld ", (n))
using namespace std;
typedef long long lld;
typedef pair<lld, lld> pii;
typedef vector<lld> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

struct edge { lld to, length; };
vvi route;

lld dijkstra(const vector< vector<edge> > &graph, lld source, lld target){
    vi min_distance(graph.size(), LLONG_MAX);
    min_distance[source] = 0;
    set<pair<lld, lld> > active_vertices;
    active_vertices.insert( {0, source} );
    while(!active_vertices.empty()){
        int where = active_vertices.begin()->second;
        if (where == target) return min_distance[where];
        active_vertices.erase(active_vertices.begin());
        for (auto ed : graph[where] ){
            if (min_distance[ed.to] > min_distance[where] + ed.length){
                active_vertices.erase({min_distance[ed.to], ed.to});
                route[ed.to] = route[where];
                route[ed.to].push_back(where);
                min_distance[ed.to] = min_distance[where] + ed.length;
                active_vertices.insert({min_distance[ed.to], ed.to});
            } else if(min_distance[ed.to]==min_distance[where]+ed.length 
                    && route[ed.to].size()>route[ed.to].size()+1){
                active_vertices.erase({min_distance[ed.to], ed.to});
                route[ed.to] = route[where];
                route[ed.to].push_back(where);
                min_distance[ed.to] = min_distance[where] + ed.length;
                active_vertices.insert({min_distance[ed.to], ed.to});
            }
        }
    }
    return min_distance[target];
}

int main() {
    lld N, R;
    scl(N), scl(R);
    vector< vector<edge> > graph(N+1,vector<edge>());
    route.assign(N+1, vi());
    for(int i=1;i<=N;i++) route[i].push_back(i);
    for(int i=0;i<R;i++){
        lld a,b,c,d,e;
        scl(a), scl(b), scl(c), scl(d), scl(e);
        if(e<10) e=10;
        lld dist=c+d*(e-10);
        graph[a].push_back({b, dist});
    }
    lld dist = dijkstra(graph, 1, N);
    if(dist==LLONG_MAX){
        printf("It is not a great way.");
        return 0;
    }
    printf("%lld %d", dist, int(route[N].size()));

    return 0;
}
