#include <iostream>
#include <deque>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        bool dir=true, berror=false;
        string p;
        deque<int> arr;
        cin>>p>>n;
        int x=0;
        while(1){
            char c =getchar();
            if(c>='0' && c<='9') x =x*10 + c-'0';
            else{
                if(x>0) arr.push_back(x);
                x=0;
                if(c==']') break;
            }
        }
        for(auto c = p.begin();c<p.end();c++){
            if(*c=='D'){
                if(arr.empty()){
                    printf("error\n");
                    berror=true;
                    break;
                }else{
                    if(dir){
                        arr.pop_front();
                    }else{
                        arr.pop_back();
                    }
                }
            }else if(*c=='R'){
                dir=!dir;
            }
        }
        if(!dir){
            reverse(arr.begin(),arr.end());
        }
        if(!berror){
            printf("[");
            while(!arr.empty()){
                printf("%d",arr.front());
                arr.pop_front();
                if(!arr.empty()){
                    printf(",");
                }
            }
            printf("]\n");
        }
    }
    return 0;
}
