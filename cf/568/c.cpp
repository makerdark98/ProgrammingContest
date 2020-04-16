#include <iostream>
#include <vector>
#define sci(n) scanf("%d", &(n))
using namespace std;
#define LSOne(S) ((S) & (-(S)))
using vi = vector<int>;
class FenwickTree {
    private:
        vi ft;
    public:
        FenwickTree(int n) {
            ft.assign(n+1, 0);
        }

        int rsq(int b) {
            int sum = 0;
            for(;b;b-=LSOne(b)) sum += ft[b];
            return sum;
        }

        int rsq(int a, int b) {
            return rsq(b) - ((a ==1 || a==0) ? 0 : rsq(a-1));
        }

        void adjust(int k, int v) {
            if (k >= (int)ft.size()) {
                ft.resize(k+1, 0);
                int remain = k - LSOne(k);
                int a = LSOne(k)-1;
                for(;a;a-=LSOne(a)) {
                    ft[k] += ft[remain+a];
                }
                ft[k] += v;
                return;
            }

            for(; k< (int)ft.size(); k+=LSOne(k)) {
                ft[k] += v;
            }
        }

        void update(int k, int v) {
            if (k >= (int)ft.size()) adjust(k, v);
            else adjust(k, v-rsq(k, k));
        }
};
int main() {
    int n, M;
    sci(n), sci(M);
    vi t(n);
    FenwickTree ft(n);
    for(int i=0;i<n;i++){ sci(t[i]); }
    for(int i=0;i<n;i++){

    }
    return 0;
}
