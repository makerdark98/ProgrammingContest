#include <iostream>
#include <vector>
#define MOD 1000000007LL
#define scl(n) scanf("%lld", &(n))
using namespace std;
using lld = long long;
lld fast_pow(lld a, lld p) {
    lld t= fast_pow(a, p/2) %MOD;
    if(p%2==1) {
        return t * t % MOD * a % MOD;
    }
    return t * t % MOD;
}

class Matrix{
    public:
        lld data[3][3];
        Matrix() {
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    data[i][j] = 0;
                }
            }
        }
        static Matrix MatMul(const Matrix& a, const Matrix& b){
            Matrix result;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    for(int k=0;k<3;k++){
                        result.data[i][j] += a.data[i][k] * b.data[k][j];
                        result.data[i][j] %= MOD;
                    }
                }
            }
            return result;
        }
        static Matrix fast_pow(const Matrix& a, lld p){
            Matrix t = fast_pow(a, p/2);
            if(p%2 == 1) {
                return MatMul(MatMul(t, t), a);
            }
            return MatMul(t, t);
        }
};
int main() {
    int base[3][3] = {
        {1, 1, 1},
        {1, 0, 0},
        {0, 1, 0}
    };
    lld n, c, f1, f2, f3;
    scl(c), scl(f1), scl(f2), scl(f3), scl(n);
    lld result = fast_pow(c, (n-3) * (n-2));
    Matrix b;
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) b.data[i][j] = base[i][j];
    printf("%lld", 
    return 0;
}
