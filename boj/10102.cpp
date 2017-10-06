#include <iostream>
using namespace std;
int main(){
    int V, A=0, B=0;
    scanf("%d", &V);
    while(V--){
        char tmp;
        scanf(" %c", &tmp);
        if(tmp=='A') A++;
        else B++;
    }
    if(A>B) printf("A\n");
    else if(A<B) printf("B\n");
    else printf("Tie\n");
    return 0;
}
