#include <iostream>
#include <queue>

using namespace std;

int Map[201][201];
int Visited[201][201];
int N, M;
queue<pair<int, int>> q ;

int check_range(pair<int,int> p){
    return p.first>-1&&p.first<N&&p.second>-1&&p.second<M;
}

int BFS(){
    pair<int, int> tmp;
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        if(tmp.first==N-1&&tmp.second==M-1){
            return 1;
        }
        if(check_range(tmp)){
            if(Map[tmp.first][tmp.second]){
                Map[tmp.first][tmp.second]=0;
                q.push(make_pair(tmp.first-1,tmp.second));
                Visited[tmp.first-1][tmp.second]=Visited[tmp.first][tmp.second]+1;
                q.push(make_pair(tmp.first+1,tmp.second));
                Visited[tmp.first+1][tmp.second]=Visited[tmp.first][tmp.second]+1;
                q.push(make_pair(tmp.first,tmp.second+1));
                Visited[tmp.first][tmp.second-1]=Visited[tmp.first][tmp.second]+1;
                q.push(make_pair(tmp.first,tmp.second-1));
                Visited[tmp.first][tmp.second+1]=Visited[tmp.first][tmp.second]+1;
            }
        }
    }
    return 0;
}

int main() {
    int i, j;
    char c;
    scanf("%d %d", &N, &M);
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            scanf(" %c", &c);
            if(c=='1') Map[i][j]=1;
        }
    }
    q.push(make_pair(0,0));
    Visited[0][0]=1;
    BFS();
    printf("%d\n", Visited[N-1][M-1]);
    return 0;
}