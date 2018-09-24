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


int N, M;
int main() {
    sci(M), sci(N);
    vi machine[3], your[3];
    for(int i=0;i<3;i++){
        machine[i].assign(M+N,0);
        your[i].assign(N,0);
    }
    for(int i=0;i<M;i++){
        char tmp;
        int tmp1;
        scanf(" %c", &tmp);
        switch(tmp){
            case 'R': tmp1 = 0; break;
            case 'S': tmp1 = 1; break;
            case 'P': tmp1 = 2; break;
        }
        machine[tmp1][i]=1;
    }
    for(int i=N-1;i>=0;i--){
        char tmp;
        int tmp1;
        scanf(" %c", &tmp);
        switch(tmp){
            case 'R': tmp1 = 1; break;
            case 'S': tmp1 = 2; break;
            case 'P': tmp1 = 0; break;
        }
        your[tmp1][i]=1;
    }
    vi res[3];
    for(int i=0;i<3;i++)
        multiply(machine[i],your[i],res[i]);
    lld ans=0;
    for(int i=N-1;i<M+N;i++){
        ans = max(ans, res[0][i]+res[1][i]+res[2][i]);
    }
    prl(ans);
	return 0;
}
