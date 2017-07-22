#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
#include <functional>

using namespace std;
int n,m,l,r,x;
int p[20010];
int main() {
    scanf("%d %d",&n, &m);
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d %d %d", &l,&r,&x);
        std::priority_queue<int, std::vector<int>, greater<int> > q;
        for(int j=l;j<=r;j++){
            q.push(p[j]);
        }
        for(int k=0;k<x-l;k++){
            q.pop();
        }
        if(q.top()==p[x]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}