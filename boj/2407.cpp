#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long LL ;
class BigInteger{
    public:
    vector<short> num;
    BigInteger(){
        num.assign(50, 0);
    }
    BigInteger operator+(const BigInteger& a){
        BigInteger tmp;
        short up=0;
        for(int i=0;i<50;i++){
            tmp.num[i]=this->num[i]+a.num[i]+up;
            if(tmp.num[i]>9)
        }
        return tmp;
    }
}
vector<vector<LL> > a;
int main(){
    int N, K;
    scanf("%d %d",&N,&K);
    a.assign(N+1, vector<LL>(K+1));
    for(int i=0;i<=K;i++){
        a[0][i]=0;
        a[1][i]=i;
    }
    for(int i=0;i<=N;i++){
        a[i][0]=1;
        a[i][1]=i;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=K;j++){
            a[i][j] = (a[i-1][j]+a[i-1][j-1]);
        }
    }
    printf("%llu\n",a[N][K]);
    return 0;
}

