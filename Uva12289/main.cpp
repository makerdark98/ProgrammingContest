#include <iostream>
using namespace std;
int main() {
    string s;
    int t;
    scanf("%d",&t);
    while(t--){
        int one_count=0;
        cin>>s;
        if(s.length()==3){
            if(s.at(0)=='o') one_count++;
            if(s.at(1)=='n') one_count++;
            if(s.at(2)=='e') one_count++;
            if(one_count>1) printf("1\n");
            else printf("2\n");
        }else{
            printf("3\n");
        }
    }
    return 0;
}