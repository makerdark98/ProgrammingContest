#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
struct POINT{
    int x, y, z;
};
int main(){
    int M, N, H;
    scanf("%d %d %d", &M, &N, &H);
    vvvi tomato;
    tomato.resize(M+2);
    for(int i=0;i<M+2;i++){
        tomato[i].resize(N+2);
        for(int j=0;j<N+2;j++){
            tomato[i][j].assign(H+2, -1);
        }
    }
    for(int k=1;k<=H;k++){
        for(int j=1;j<=N;j++){
            for(int i=1;i<=M;i++){
                scanf("%d",&tomato[i][j][k]);
            }
        }
    }
    queue<pair<POINT, int> > q;
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=H;k++){
                if(tomato[i][j][k]==1){
                    if(tomato[i-1][j][k]==0) q.push({POINT{i-1,j,k},1});
                    if(tomato[i+1][j][k]==0) q.push({POINT{i+1,j,k},1});
                    if(tomato[i][j-1][k]==0) q.push({POINT{i,j-1,k},1});
                    if(tomato[i][j+1][k]==0) q.push({POINT{i,j+1,k},1});
                    if(tomato[i][j][k-1]==0) q.push({POINT{i,j,k-1},1});
                    if(tomato[i][j][k+1]==0) q.push({POINT{i,j,k+1},1});

                }
            }
        }
    }
    int ans=0;
    while(!q.empty()){
        auto p=q.front().first;
        auto t=q.front().second;
        q.pop();
        if(tomato[p.x][p.y][p.z]==0){
            tomato[p.x][p.y][p.z]=1;
            ans=max(t,ans);
            if(tomato[p.x-1][p.y][p.z]==0) q.push({POINT{p.x-1,p.y,p.z},t+1});
            if(tomato[p.x+1][p.y][p.z]==0) q.push({POINT{p.x+1,p.y,p.z},t+1});
            if(tomato[p.x][p.y-1][p.z]==0) q.push({POINT{p.x,p.y-1,p.z},t+1});
            if(tomato[p.x][p.y+1][p.z]==0) q.push({POINT{p.x,p.y+1,p.z},t+1});
            if(tomato[p.x][p.y][p.z-1]==0) q.push({POINT{p.x,p.y,p.z-1},t+1});
            if(tomato[p.x][p.y][p.z+1]==0) q.push({POINT{p.x,p.y,p.z+1},t+1});
        }
    }
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=H;k++){
                if(tomato[i][j][k]==0) ans=-1;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
