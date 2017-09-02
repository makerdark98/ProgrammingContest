#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N, M;
    queue<int> q;
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++){
        q.push(i+1);
    }
    printf("<");
    while(!q.empty()){
        for(int i=0;i<M-1;i++){
            q.push(q.front());
            q.pop();
        }
        printf("%d", q.front());
        q.pop();
        if(!q.empty()) printf(", ");
    }
    printf(">\n");
    return 0;
}
