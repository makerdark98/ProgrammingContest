#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define sci(N) scanf("%d", &(N))
#define scc(C) scanf(" %c", &(C))

int parent[50010];
int set_size[50010];
vector<int> edges[50010];
vector<pair<int, int> > data;
int indegree[50010];
int getParent(int a) { return a == parent[a] ? a : parent[a] = getParent(parent[a]); }
void merge (int a, int b) {
    int pa = getParent(a), pb = getParent(b);
    if (set_size[pa] < set_size[pb]) {
        set_size[pb] += set_size[pa]; parent[pa] = pb;
    } else {
        set_size[pa] += set_size[pb]; parent[pb] = pa;
    }
}

int main () {
    int N, M;
    sci(N), sci(M);
    for (int i = 0; i < N; i++) {
        parent[i] = i;
        set_size[i] = 1;
    }
    for (int i =0; i< M;i++) {
        int a, b;
        char o;
        sci(a), scc(o), sci(b);
        
        if (o == '=') merge(a, b);
        else data.push_back({a, b});
    }
    
    for (int i = 0; i < data.size(); i ++) {
        int a = getParent(data[i].first), b = getParent(data[i].second);
        if (a == b) {
            printf("inconsistent");
            return 0;
        }
        edges[a].push_back(b);
        indegree[b] ++;
    }
    queue<int> q;
    
    for (int i = 0; i < N; i++)
        if (indegree[i] == 0) q.push(i);
    
    while (!q.empty()) {
        int f = q.front(); q.pop();
        for (int i = 0; i < edges[f].size(); i ++) {
            indegree[edges[f][i]] --;
            if (indegree[edges[f][i]] == 0) q.push(edges[f][i]);
        }
    }
    
    for (int i = 0; i< N; i++) {
        if (indegree[i] != 0) {
            printf("inconsistent");
            return 0;
        }
    }
    printf("consistent");
    return 0;
}
