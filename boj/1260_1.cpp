#include <iostream>
#include <queue>
using namespace std;

int N, M, V;

int Ver[1001][1001]={0};
int Ver1[1001][1001]={0};
int Already[1001];

queue<int> q;

void DFS(int Node);
void BFS();

int main() {
    int A, B, i;
    scanf("%d %d %d", &N, &M, &V);
    for(i=0;i<M;i++){
        scanf("%d %d", &A, &B);
        Ver[A][B]=1;
        Ver[B][A]=1;
        Ver1[A][B]=1;
        Ver1[B][A]=1;
    }
    DFS(V);
    printf("\n");
    for(i=1;i<=N;i++){
        Already[i]=0;
    }
    q.push(V);
    while(!q.empty()) {
        BFS();
    }
    return 0;
}

void DFS(int Node){
    int i;
    if(Already[Node]) return;
    printf("%d ", Node);
    Already[Node]=1;
    for(i=1;i<=N;i++){
        if(Ver[Node][i]){
            Ver[Node][i]=0;
            Ver[i][Node]=0;
            DFS(i);
        }
    }
}

void BFS(){
    int i;
    int Node = q.front();
    if(Already[Node]) {
        q.pop();
        return;
    }
    q.pop();
    printf("%d ", Node);
    Already[Node]=1;
    for(i=1;i<=N;i++){
        if(Ver1[Node][i]){
            Ver1[Node][i]=0;
            Ver1[i][Node]=0;
            q.push(i);
        }
    }
}