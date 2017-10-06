#include <iostream>
#include <vector>
using namespace std;
int n;
vector<vector< int > > m;
vector<vector< int > > sav;

void bfs(int x, int y, int day){
    if(x>=0&&x<n&&y>=0&&y<n){
        printf("%d %d\n", x,y);
        getchar();
        if(sav[x][y]<day){
            sav[x][y]=day;
        printf("%d %d\n", x,y);
        getchar();
            if(x<n-1&&m[x][y]<m[x+1][y]) bfs(x+1, y,day+1);
            if(x>0&&m[x][y]<m[x-1][y]) bfs(x-1, y,day+1);
            if(y<n-1&&m[x][y]<m[x][y+1]) bfs(x, y+1,day+1);
            if(y>0&&m[x][y]<m[x][y-1]) bfs(x, y-1,day+1);
        }
    }
    return;
}

int main(){
    vector<vector< int > > m;
    vector<vector< int > > sav;
    scanf("%d",&n);
    m.resize(n);
    sav.resize(n);
    for(int i=0;i<n;i++){
        m[i].assign(n, 0);
        sav[i].assign(n, 0);
        for(int j=0;j<n;j++){
            scanf("%d",&m[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            bfs(i,j,1);
        }
    }
    int ma=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ma=ma>sav[i][j]?ma:sav[i][j];
        }
    }
    printf("%d\n",ma);
    return 0;
}
