#include <iostream>
#include <vector>
using namespace std;
using lld = long long;
using vi = vector<lld>;
using vvi = vector<vi>;
using pii = pair<lld, lld>;
using vpii = vector<pii>;
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%I64d", &(n))
#define scc(c) scanf(" %c", &(c))
int main(){
    int n;
    sci(n);
    vpii result;
    vvi r(27), l(27);
    for(int i=1;i<=n;i++){ char c;
        scc(c);
        if(c=='?') c = 26; else c -='a';
        r[c].push_back(i);
    }
    for(int i=1;i<=n;i++){
        char c;
        scc(c);
        if(c=='?') c = 26; else c -='a';
        l[c].push_back(i);
    }
    for(int i=0;i<26;i++){
        while(r[i].size()>0&&l[i].size()>0) {
            result.push_back({r[i].back(), l[i].back()});
            r[i].pop_back();
            l[i].pop_back();
        }
    }

    for(int i=0;i<26 && r[26].size() >0;i++){
        while(l[i].size()>0&&r[26].size()>0) {
            result.push_back({r[26].back(), l[i].back()});
            r[26].pop_back();
            l[i].pop_back();
        }
    }
    for(int i=0;i<27 && l[26].size() >0;i++){
        while(r[i].size()>0&&l[26].size()>0) {
            result.push_back({r[i].back(), l[26].back()});
            r[i].pop_back();
            l[26].pop_back();
        }
    }

    printf("%lu\n", result.size());

    size_t i = 0;
    for(;i<result.size();i++){
        printf("%I64d %I64d\n", result[i].first, result[i].second);
    }

    return 0;
}
