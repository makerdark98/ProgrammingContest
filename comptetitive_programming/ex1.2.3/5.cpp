#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<iii> viii;
int main(){
    int n;
    viii people;
    scanf("%d",&n);
    people.resize(n);
    for(int i=0;i<n;i++){
        cin>>people[i].first.first>>people[i].first.second>>people[i].second;
    }
    sort(people.begin(), people.end(), [](iii x, iii y)->bool{
        if(x.first.second==y.first.second){
            if(x.first.first==y.first.first){
            return x.second<y.second;
            }
            return x.first.first<y.first.first;
        }
        return x.first.second<y.first.second;
    });
    for(int i=0;i<n;i++){
        cout<<people[i].first.first<<people[i].first.second<<people[i].second<<endl;
    }
    return 0;
}
