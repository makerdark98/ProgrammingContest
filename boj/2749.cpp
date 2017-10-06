#include <iostream>
#include <vector>
const long long MOD=1000000;

using namespace std;
typedef vector<vector<long long> > Matrix;

Matrix operator*(const Matrix& x,const Matrix& y){
    Matrix tmp;
    int n, m, o;
    n = x.size();
    m = x[0].size();
    o = y[0].size();
    if(m!=(int)y.size()){
        throw new exception;
    }
    tmp.resize(n);
    for(int i=0;i<n;i++){
        tmp[i].assign(m, 0);
        for(int j=0;j<o;j++){
            for(int k=0;k<m;k++){
                tmp[i][j] += (x[i][k] * y[k][j]);
            }
            tmp[i][j] %=MOD;
        }
    }
    return tmp;
}

Matrix fastpow(Matrix m, long long power){
    Matrix ans=m;
    power--;
    while(power>0){
        if(power%2==1){
            ans = (ans*m);
        }
        m = m*m;
        power/=2;
    }
    return ans;
}

int main(){
    Matrix x;
    x.resize(2);
    x[0].assign(2, 0);
    x[1].assign(2, 0);
    x[0][0]=1;
    x[0][1]=1;
    x[1][0]=1;
    x[1][1]=0;
    long long n;
    scanf("%lld", &n);
    if(n==0) printf("0\n");
    else printf("%lld\n", fastpow(x, n-1)[0][0]);
    return 0;
}
