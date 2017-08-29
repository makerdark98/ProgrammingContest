#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
typedef pair<int, int> ii;

int N;
int white, blue;

vector< vector<int> > Map;
int check(ii s, ii e){
    for(int i=s.first;i<=e.first;i++){
        for(int j=s.second;j<=e.second;j++){
            if(Map[i][j]!=Map[e.first][e.second])
                return false;
        }
    }
    return true;
}

void Divide(ii s, ii e){
    ii m = make_pair(s.first+(e.first-s.first)/2, s.second+(e.second-s.second)/2);
    if(check(s, e)) {
        if(Map[s.first][s.second]) blue++;
        else white++;
    }
    else{
        Divide(s, m);
        Divide(make_pair(m.first+1,s.second),make_pair(e.first,m.second));
        Divide(make_pair(s.first,m.second+1),make_pair(m.first,e.second));
        Divide(make_pair(m.first+1,m.second+1), e);
    }
}

int main(){
    scanf("%d",&N);
    Map.resize(N);
    for(int i=0;i<N;i++){
        Map[i].resize(N);
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N; j++){
            scanf("%d", &Map[i][j]);
        }
    }
    Divide(make_pair(0,0), make_pair(N-1,N-1));
    printf("%d\n%d", white, blue);
    return 0;
}