#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
vector<int> uni;
vector<int> ran;
int findSet(int i) { return (uni[i]== i) ? i: (uni[i]=findSet(uni[i]));}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N;
        scanf("%d",&N);
        vector<iii> input(N);
        uni.resize(N);
        ran.resize(N);
        for(int i=0;i<N;i++){
            scanf("%d %d %d",&input[i].first.first,&input[i].first.second,&input[i].second);
            uni[i]=i;
        }
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                if(pow(input[i].second+input[j].second,2)>=(pow(input[i].first.first-input[j].first.first,2)+pow(input[i].first.second-input[j].first.second,2))){
                    int x = findSet(i), y = findSet(j);
                    if(x!=y){
                        if(ran[x] > ran[y]) uni[y] = x;
                        else{
                            uni[x]=y;
                            if(ran[x]==ran[y]) ran[y]++;
                        }
                    }
                }
            }
        }
        for(int i=0;i<N;i++){
            findSet(i);
        }
        sort(uni.begin(), uni.end());
        uni.erase(unique(uni.begin(), uni.end()), uni.end());
        printf("%d\n", uni.size());
    }
    return 0;
}
