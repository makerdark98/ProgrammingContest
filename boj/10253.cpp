#include <iostream>
#include <vector>
using namespace std;
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%lld", &(n))
using lld = long long;
int gcd(int a, int b) {
    int t = a%b;
    while(t!=0){ a=b; b=t; t=a%b; }
    return b;
}
class Fraction {
    public:
        int rc, rp;
        Fraction(int a, int b){
            int g = gcd(a, b);
            rc=a/g;
            rp=b/g;
        }
        static Fraction Minus(Fraction a, Fraction b){
            return Fraction(a.rc*b.rp-b.rc*a.rp, a.rp*b.rp);
        }
};
int main(){
    int T;
    sci(T);
    while(T--){
        int a, b;
        sci(a), sci(b);
        Fraction f(a,b);
        int i;
        for(i=1;f.rc!=1;i++){
            if((double)f.rc/f.rp > (double)1/i)
                f = Fraction::Minus(f, Fraction(1, i));
        }
        printf("%d\n", f.rp);
    }
    return 0;
}
