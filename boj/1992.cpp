#include <iostream>
#define sci(n) scanf("%d", &(n))
using namespace std;
int N;
int A[65][65];
void solve(int size, int r, int c);
int main(){
    sci(N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%1d", &(A[i][j]));
        }
    }
    solve(N, 0, 0);
    return 0;
}
void solve(int s,int r, int c){
    int t = A[r][c];
    int chk=0;
    for(int i=r;i<r+s;i++){
        for(int j=c;j<c+s;j++){
            if(t!=A[i][j]) chk=1;
        }
    }
    if(!chk) printf("%d",t);
    else{
        printf("(");
        solve(s/2,r,c);
        solve(s/2,r,c+s/2);
        solve(s/2,r+s/2,c);
        solve(s/2,r+s/2,c+s/2);
        printf(")");
    }
}
