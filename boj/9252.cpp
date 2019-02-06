#include <iostream>
#include <vector>
using namespace std;
using lld = long long;
using vi = vector<lld>;
using vvi = vector<vi>;
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%lld", &(n))
vvi dp;
vector<vector<string> > str_dp;
lld lcs(int& i, int& j){
    if(i<0 || j< 0) return 0;
    return dp[i][j];
}
int main() {
    string a, b;
    cin>>a>>b;
    dp.assign(a.length(), vi(b.length(), 0));
    str_dp.assign(a.length(), vector<string>(b.length(), ""));
    for(int i=0;i<a.length();i++){
        for(int j=0;j<b.length();j++){
            if(a.at(i) == b.at(j)){
                dp[i][j] = (i<1||j<1) ? 1 : dp[i-1][j-1]+1;
                str_dp[i][j] = (i<1 || j<1) ? a.substr(i, 1) : str_dp[i-1][j-1] + a.at(i);
            }
            else {
                if(i == 0 && j != 0) { dp[i][j] = dp[i][j-1]; str_dp[i][j] = str_dp[i][j-1]; }
                else if( i !=0 && j==0) { dp[i][j] = dp[i-1][j]; str_dp[i][j] = str_dp[i-1][j]; }
                else if( i ==0 && j==0) { dp[i][j] = 0; str_dp[i][j] = ""; }
                else {
                    if(dp[i-1][j] > dp[i][j-1]){ dp[i][j] = dp[i-1][j]; str_dp[i][j] = str_dp[i-1][j]; }
                    else { dp[i][j] = dp[i][j-1]; str_dp[i][j] = str_dp[i][j-1]; }
                }
            }
        }
    }
    cout<<dp[a.length()-1][b.length()-1]<<endl <<str_dp[a.length()-1][b.length()-1];
    return 0;
}

