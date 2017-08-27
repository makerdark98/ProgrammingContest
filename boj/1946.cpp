#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int T, N;
    scanf("%d",&T);
    while(T--){
        vector<pair<int, int> > score;
        int Maxidx=0;
        int count=1;
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            int a, b;
            scanf("%d %d", &a, &b);
            score.push_back(make_pair(a,b));
        }
        sort(score.begin(),score.end(),[](pair<int, int> x,pair<int, int> y)->bool{
            if(x.first==y.first) return x.second>y.second;
            return x.first<y.first;
        });
        Maxidx=0;
        for(int i=1;i<N;i++){
            if(score[Maxidx].second>score[i].second){
                count++;
                Maxidx=i;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}