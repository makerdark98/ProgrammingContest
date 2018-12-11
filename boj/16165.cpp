//
// Created by lmu on 18. 10. 1.
//

#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%d", &(n))
#define pri(n) printf("%d ", (n))
#define prl(n) printf("%d ", (n))
using namespace std;
typedef int lld;
typedef pair<lld, lld> pii;
typedef vector<lld> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

int main(){
    int M, N;
    sci(N), sci(M);
    map<string, vector<string> > groups;
    while(N--) {
        string group;
        cin>>group;
        int t;
        sci(t);
        vector<string> members(t);
        for(int i=0;i<t;i++)
            cin>>members[i];
        sort(members.begin(), members.end());
        groups[group] = members;
    }
    while(M--){
        int p;
        string input;
        cin>>input;
        sci(p);
        if(p==0){
            auto selected=groups[input];
            for(auto member : selected)
                cout<<member<<"\n";
        }else if(p==1){
            for(auto group : groups){
                if(find(group.second.begin(), group.second.end(), input)!=group.second.end()) {
                    cout<<group.first<<"\n";
                }
            }
        }
    }
    return 0;
}

