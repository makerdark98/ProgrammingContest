#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define sci(n) scanf("%d", &(n))
#define scd(d) scanf("%lf", &(d))
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
    int a, b;
    double cost;
};
vector<edge_t> edges;

struct point_t {
    double x, y;
};

vector<point_t> data;

double dist(int ia, int ib) {
    point_t& a = data[ia];
    point_t& b = data[ib];
    
    return sqrt((a.x-b.x) * (a.x-b.x) + (a.y - b.y) * (a.y-b.y));
}


int main () {
    int N;
    
    sci(N);
    init(N);
    data.resize(N);
    for (int i=0;i<N;i++) {
        scd(data[i].x), scd(data[i].y);
    }
    
    for(int i=0;i<N;i++) {
        for(int j=i+1; j<N;j++) {
            edges.push_back({i, j, dist(i,j)});
        }
    }
    
    
    sort(edges.begin(), edges.end(), [](const edge_t& a, const edge_t& b) -> bool {
        return a.cost < b.cost;
    });
    
    double result = 0;
    for (int i=0;i<edges.size();i++) {
        if(!isSameSet(edges[i].a, edges[i].b)) {
            merge(edges[i].a, edges[i].b);
            result += edges[i].cost;
        }
    }
    printf("%lf", result);
    return 0;
}
