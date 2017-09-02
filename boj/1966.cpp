#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N,M, M_pri;
        scanf("%d %d",&N,&M);
        queue<pair<int, int> > q;
        priority_queue<int> pq;
        for(int i=0;i<N;i++){
            int tmp;
            scanf("%d", &tmp);
            if(i==M){
                M_pri = tmp;
            }
            q.push(make_pair(tmp, i));
            pq.push(tmp);
        }
        int result = 1;
        while(!q.empty()){
            if(pq.top()==q.front().first){
                if(pq.top()==M_pri&&q.front().second==M){
                    printf("%d\n",result);
                    while(!q.empty()) q.pop();
                }
                else{
                    q.pop();
                    pq.pop();
                    result++;
                }
            }
            else{
                q.push(q.front());
                q.pop();
            }
        }
    }
    return 0;
}
