#include <iostream>
#include <string.h>
using namespace std;
#define scl(n) scanf("%lld", &(n))
#define prl(n) printf("%lld\n", n)
using lld = long long;

int main(){
    lld T;
    lld total = 0;
    scl(T);
    while(T--){
        char query[20];
        scanf(" %s", query);
        if(strcmp(query, "donate") == 0){
            lld tmp;
            scl(tmp);
            total += tmp;
        }
        else if(strcmp(query, "report") == 0){
            prl(total);
        }
    }
    return 0;
}