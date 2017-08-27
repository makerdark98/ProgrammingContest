#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, now=0, count=0;
    scanf("%d",&n);
    vector<pair<int, int> > time;
    for(int i=0;i<n;i++){
        int s, e;
        scanf("%d %d",&s, &e);
        time.push_back(make_pair(s, e));
    }
    sort(time.begin(), time.end(), [](pair<int, int> x, pair<int, int> y)->bool{
        if(x.second==y.second){
            return x.first<y.first;
        }
        return x.second<y.second;
    });
    for(int i =0;i<n;i++){
        if(time[i].first>=now){
            now=time[i].second;
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}