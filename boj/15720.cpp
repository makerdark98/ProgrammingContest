//
// Created by lmu on 18. 9. 25.
//

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <complex>
#include <vector>
#include <algorithm>
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%d", &(n))
#define pri(n) printf("%d ", (n))
#define prl(n) printf("%d ", (n))
using namespace std;
typedef int lld;
typedef pair<lld, lld> pii;
typedef vector<lld> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

typedef complex<double> base;

void fft(vector<base> &a, bool invert) {
    int n = a.size();
    for (int i=1,j=0;i<n;i++){
        int bit = n >> 1;
        for (;j>=bit;bit>>=1) j -= bit;
        j += bit;
        if (i < j) swap(a[i],a[j]);
    }
    for (int len=2;len<=n;len<<=1){
        double ang = 2*M_PI/len*(invert?-1:1);
        base wlen(cos(ang),sin(ang));
        for (int i=0;i<n;i+=len){
            base w(1);
            for (int j=0;j<len/2;j++){
                base u = a[i+j], v = a[i+j+len/2]*w;
                a[i+j] = u+v;
                a[i+j+len/2] = u-v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        for (int i=0;i<n;i++) a[i] /= n;
    }
}

void multiply(const vector<int> &a,const vector<int> &b,vector<int> &res) {
    vector <base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < max(a.size(),b.size())) n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa,false); fft(fb,false);
    for (int i=0;i<n;i++) fa[i] *= fb[i];
    fft(fa,true);
    res.resize(n);
    for (int i=0;i<n;i++) res[i] = int(fa[i].real()+(fa[i].real()>0?0.5:-0.5));
}

lld B, C, D;
vi burger, side, drink;
int main(){
    scl(B), scl(C), scl(D);
    burger.resize(B);
    side.resize(C);
    drink.resize(D);
    for(int i=0;i<B;i++) scl(burger[i]);
    for(int i=0;i<C;i++) scl(side[i]);
    for(int i=0;i<D;i++) scl(drink[i]);
    sort(burger.begin(), burger.end(), greater<lld>());
    sort(side.begin(), side.end(), greater<lld>());
    sort(drink.begin(), drink.end(), greater<lld>());
    lld maxsize=B;
    maxsize = min(C, maxsize);
    maxsize = min(D, maxsize);
    lld res1=0, res2=0;
    for(int i=0;i<B;i++) {
        res1 += burger[i];
        if(i<maxsize) res2 += burger[i] * 0.9;
        else res2 += burger[i];
    }
    for(int i=0;i<C;i++) {
        res1 += side[i];
        if(i<maxsize) res2 += side[i] * 0.9;
        else res2 += side[i];
    }
    for(int i=0;i<D;i++) {
        res1 += drink[i];
        if(i<maxsize) res2 += drink[i] * 0.9;
        else res2 += drink[i];
    }
    prl(res1);
    printf("\n");
    prl(res2);
    return 0;
}