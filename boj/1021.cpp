#include <iostream>
#include <deque>
using namespace std;
int main(){
    int N, M;
    deque<int> dq;
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++){
        dq.push_back(i);
    }
    int result =0;
    while(M--){
        int tmp;
        scanf("%d",&tmp);
        auto s=dq.begin();
        auto e=dq.end()-1;
        while(*s!=tmp && *e!=tmp){
            s++;
            e--;
        }
        if(*s==tmp){
            while(dq.front()!=tmp){
                dq.push_back(dq.front());
                dq.pop_front();
                result++;
            }
            dq.pop_front();
        }else{
            while(dq.back()!=tmp){
                dq.push_front(dq.back());
                dq.pop_back();
                result++;
            }
            result++;
            dq.pop_back();
        }
    }
    printf("%d\n",result);
    return 0;
}
