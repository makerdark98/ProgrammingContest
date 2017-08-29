#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <map>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    while(N--){
        int total_pay=0;
        int K;
        scanf("%d",&K);
        map<int,int> pcv;
        while(K--){
            int v;
            char p;
            scanf(" %c %d", &p, &v);
            pcv[p]=v;
        }
        string line;
        int M;
        scanf("%d", &M);
        while(M--){
            getline(cin,line);
            for(auto c = line.begin(); c<line.end(); c++){
                total_pay += pcv.find(*c)->second;
                //if(pcv.find(*c)->second!=0) printf("p : %c v : %d t: %d\n", *c, pcv.find(*c)->second, total_pay);
            }
        }
        printf("%.2f$\n", (float)total_pay/100);
    }
}
