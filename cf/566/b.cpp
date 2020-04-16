#include <iostream>
#include <vector>
#define sci(n) scanf("%d",&(n))
#define scc(c) scanf(" %c", &(c))
#define scl(n) scanf("%I64d",&(n))
using namespace std;
using lld = long long;
using vi = vector<lld>;
using vvi = vector<vi>;
vvi data;
int h, w;
bool solve();
int main() {
    sci(h), sci(w);
    data.assign(h, vi(w, 0));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            char c;
            scc(c);
            if (c=='.') data[i][j] = 0;
            else if (c=='*') data[i][j] = 1;
        }
    }

    printf("%s", solve() ? "YES" : "NO");
    return 0;
}
bool solve() {
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    bool already_found = false;
    pair<int, int> position;
    for (int i=1;i<h-1;i++) {
        for(int j=1;j<w-1;j++){
            if(data[i][j]) {
                int t;
                for(t=0;t<4;t++){
                    if(!data[i+dr[t]][j+dc[t]]) {
                        break;
                    }

                }
                if(t==4) {
                    if(already_found) return false;
                    already_found = true;
                    position = {i, j};
                }
            }
        }
    }
    if(!already_found) return false;
    for(int i=position.first;i>=0;i--){
        if(!data[i][position.second]) break;
        data[i][position.second] = 0;
    }
    for(int i=position.first+1;i<h;i++){
        if(!data[i][position.second]) break;
        data[i][position.second] = 0;
    }
    for(int j=position.second-1;j>=0;j--){
        if(!data[position.first][j]) break;
        data[position.first][j] = 0;
    }
    for(int j=position.second+1;j<w;j++){
        if(!data[position.first][j]) break;
        data[position.first][j] = 0;
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(data[i][j]) return false;
        }
    }
    return true;
}
