#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%lld", &(n))
#define pri(n) printf("%d\n", (n))
#define prl(n) printf("%lld", (n))
using namespace std;
typedef long long lld;
typedef pair<lld, lld> pii;
typedef vector<lld> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

int n, m;
char data[1000010], pattern[40];
char ans[1000010];
bool check(int idx){
    for(int i=idx; i<idx+m;i++){
        if(ans[i]!=pattern[i-idx]){
            return false;
        }
    }
    return true;
}
int main() {
    scanf(" %[^\n]s", data);
    scanf(" %[^\n]s", pattern);
    n = strlen(data);
    m = strlen(pattern);
    int now=0;
    for(int i=0;i<n;i++){
        ans[now++] = data[i];
        if(now-m>=0 && check(now-m)){
            now-=m;
        }
    }
    ans[now] = '\0';
    printf("%s\n", now ? ans : "FRULA");
    return 0;
}
