#include <iostream>
#include <cstdlib>
#include <string.h>
#include <algorithm>
using namespace std;
int main(){
    char s1[1010], s2[1010];
    int dp[1010][1010]={0};
    int i,j;
    scanf("%s",s1+1);
    scanf("%s",s2+1);
    for(i=1;s1[i];i++){
        for(j=1;s2[j];j++){
            if(s1[i]==s2[j])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
        }
    }
    printf("%d",dp[i-1][j-1]);
    return 0;
}
