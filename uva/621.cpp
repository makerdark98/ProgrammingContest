#include <iostream>
using namespace std;
using lld = long long;
#define scl(n) scanf("%lld", &(n))
#define prl(n) printf("%lld\n", n)
int main(){
    lld T;
    scl(T);
    while(T--){
        string tmp;
        cin>>tmp;
        if(tmp.size() > 1 && tmp.at(tmp.size()-2)=='3' && tmp.at(tmp.size()-1) == '5')
            printf("-\n");
        else if(tmp.size() > 1 && tmp.at(0) == '9' && tmp.at(tmp.size()-1) == '4')
            printf("*\n");
        else if(tmp.at(0) == '1' && tmp.at(1) == '9' && tmp.at(2) == '0')
            printf("?\n");
        else printf("+\n");
    }
    return 0;
}
