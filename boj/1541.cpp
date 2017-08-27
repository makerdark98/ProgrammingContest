#include <iostream>
using namespace std;
int main() {
    int S;
    scanf("%d",&S);
    while(true){
        char c;
        int num;
        scanf(" %c",&c);
        if(c=='\n'){
            printf("%d",S);
            return 0;
        }
        scanf("%d",&num);
        if(c=='-'){
            S-=num;
            break;
        }
        else{
            S+=num;
        }
    }
    while(true){
        char c;
        int num;
        scanf(" %c",&c);
        if(c=='\n'){
            break;
        }
        scanf("%c",&num);
        S-=num;
    }
    printf("%d\n",S);
    return 0;
}