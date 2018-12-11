#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%lld", &(n))
#define pri(n) printf("%d ", (n))
#define prl(n) printf("%lld ", (n))
using namespace std;
typedef long long lld;
typedef pair<lld, lld> pii;
typedef vector<lld> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

void calculate_pi(vi& pi, const vector<char>& str){
    pi[0]=-1;
    for(int i=1,j=-1;i<str.size();i++){
        while(j>=0&&str[i]!=str[j+1]) j=pi[j];
        if(str[i]==str[j+1]) pi[i] = ++j;
        else pi[i]=-1;
    }
}

vi kmp(const vector<char>& text, const vector<char>& pattern) {
    vi pi(pattern.size()), ans;
    if(pattern.size()==0) return ans;
    calculate_pi(pi, pattern);
    for(int i=0,j=-1;i<text.size();i++){
        while(j>=0&&text[i]!=pattern[j+1]) j=pi[j];
        if(text[i]==pattern[j+1]){
            j++;
            if(j+1==pattern.size()){
                ans.push_back(i-j);
                j=pi[j];
            }
        }
    }
    return ans;
}


int main() {
    string S, K;
    cin>>S>>K;
    vector<char> s, k;
    for(auto c:S) if(isalpha(c)) s.push_back(c);
    for(auto c:K) if(isalpha(c)) k.push_back(c);
    vi ans = kmp(s, k);
    if(ans.size()!=0) printf("1");
    else printf("0");
    return 0;
}
