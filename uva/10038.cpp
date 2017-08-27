#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int k;
    while(scanf("%d", &k) != EOF){
        vector<bool> check;
        check.assign(k, 0);
        int n1, n2;
        scanf("%d", &n1);
        for(int i =1; i<k; i++){
            scanf("%d", &n2);
            check[abs(n1-n2)]=true;
            n1=n2;
        }
        int i;
        for(i=1;i<k;i++){
           if(!check[i]){
               break;
           }
        }
        if(i==k) cout<<"Jolly"<<endl;
        else cout<<"Not jolly"<<endl;
    }
    return 0;
}
