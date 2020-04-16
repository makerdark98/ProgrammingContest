#include <iostream>
#include <vector>
using namespace std;
#define sci(n) scanf("%d", &(n))
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
bool solve(vpii& lookup, vvi& data, vector<pair<pii, pii> >&);
int main (){
    int T;
    sci(T);
    while(T--) {
        int n, m;
        sci(n), sci(m);
        vpii lookup(26, {-1, -1});
        vvi data(n, vi(m, -1));
        vector<pair<pii, pii> > result;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                char c;
                scanf(" %c", &c);
                if(c!='.') {
                    data[i][j]=c-'a';
                    lookup[data[i][j]] = {i, j};
                }
            }
        }
        if(solve(lookup, data, result)) {
            printf("YES\n%lu\n", result.size());
            for(int i=0;i<result.size();i++){
                printf("%d %d %d %d\n", result[i].first.first+1, result[i].first.second+1,
                        result[i].second.first+1, result[i].second.second+1);
            }
        } else {
            printf("NO\n");
        }
    }
    return 0;
}

bool solve(vpii& lookup, vvi& data, vector<pair<pii, pii> >& result){
    for(int i=0;i<26;i++) {
        if(lookup[i].first != -1) {
            pii end_point;
            bool chk = false;
            for(int j=lookup[i].first-1; j>=0; j--) {
                if (data[j][lookup[i].second] > i) {
                    continue;
                } else if(data[j][lookup[i].second] == i) {
                    chk=true;
                    end_point = {j, lookup[i].second};
                } else if(data[j][lookup[i].second] == -1) {
                    break;
                } else {
                    break;
                }
            }

            for(int j=lookup[i].second-1; j>=0; j--) {
                if(data[lookup[i].first][j] > i) {
                    continue;
                } else if(data[lookup[i].first][j] == i) {
                    if(chk) {
return false;
                    }
                    end_point = {lookup[i].first, j};
                } else if(data[lookup[i].first][j] == -1) {
                    break;
                } else {
                    return false;
                }
            }
            result.push_back({end_point, lookup[i]});
        }
    }
    return true;
}
