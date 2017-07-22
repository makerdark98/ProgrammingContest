#include <iostream>
#include <queue>

using namespace std;
queue<pair<int, int>> q;
int Map[1001][1001];
int M, N;

int check_range(int first, int second){
    return first>-1&&first<N&&second>-1&&second<M;
}

int BFS() {
    int i, count, size, check;
    pair<int, int> tmp2;
    for (count = 0; !q.empty(); count++) {
        size = q.size();
        check =0;
        for(i=0;i<size;i++){
            tmp2 = q.front();
            q.pop();
            if(check_range(tmp2.first,tmp2.second-1)&&Map[tmp2.first][tmp2.second-1]==0){
                check = 1;
                Map[tmp2.first][tmp2.second-1]=1;
                q.push(make_pair(tmp2.first,tmp2.second-1));
            }
            if(check_range(tmp2.first,tmp2.second+1)&&Map[tmp2.first][tmp2.second+1]==0){
                check = 1;
                Map[tmp2.first][tmp2.second+1]=1;
                q.push(make_pair(tmp2.first,tmp2.second+1));
            }
            if(check_range(tmp2.first-1,tmp2.second)&&Map[tmp2.first-1][tmp2.second]==0){
                check = 1;
                Map[tmp2.first-1][tmp2.second]=1;
                q.push(make_pair(tmp2.first-1,tmp2.second));
            }
            if(check_range(tmp2.first+1,tmp2.second)&&Map[tmp2.first+1][tmp2.second]==0){
                check = 1;
                Map[tmp2.first+1][tmp2.second]=1;
                q.push(make_pair(tmp2.first+1, tmp2.second));
            }
        }
        if(check==0) count--;
    }
    for(i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(Map[i][j]==0) return -1;
        }
    }
    return count;
}
int main() {
    int i, j;
    scanf("%d %d", &M, &N);
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            scanf("%d", &Map[i][j]);
            if(Map[i][j]==1) q.push(make_pair(i,j));
        }
    }
    printf("%d", BFS());
    return 0;
}