#include <iostream>
#include <cmath>
#include <cstdlib>
#define sci(n) scanf("%d",&(n))
using namespace std;

int main(){
    int a,b,c,cnt;
    sci(a),sci(b),sci(c);
    cnt=b-a>c-b? b-a : c-b;
    cnt--;
    printf("%d\n",cnt);
    return 0;
}
