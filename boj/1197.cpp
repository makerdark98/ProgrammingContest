#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define sci(n) scanf("%d", &(n))
vector<int> parent, set_size;
int getParent(int a) {
    return parent[a]==a? a : parent[a]=getParent(parent[a]);
}
void merge(int a, int b) {
    int pa = getParent(a), pb = getParent(b);
    if (set_size[pa] < set_size[pb]) {
        parent[pa] = pb;
        set_size[pb] += set_size[pa];
    } else {
        parent[pb] = pa;
        set_size[pa] += set_size[pb];
    }
}

void init (int n) {
    parent.resize(n+1);
    set_size.assign(n+1, 1);
    for(int i=0;i<=n;i++)
        parent[i] = i;
}

bool isSameSet(int a, int b) {
    return getParent(a) == getParent(b);
}

struct edge_t {
    int a, b, cost;
};
vector<edge_t> edges;
int main () {
    int V, E;
    sci(V), sci(E);
    init(V);
    edges.resize(E);
    for (int i=0;i<E;i++) {
        sci(edges[i].a), sci(edges[i].b), sci(edges[i].cost);
    }
    
    sort(edges.begin(), edges.end(), [](const edge_t& a, const edge_t& b) -> bool {
        return a.cost < b.cost;
    });
    
    int result = 0;
    for (int i=0;i<E;i++) {
        if(!isSameSet(edges[i].a, edges[i].b)) {
            merge(edges[i].a, edges[i].b);
            result += edges[i].cost;
        }
    }
    printf("%d", result);
    return 0;
}
