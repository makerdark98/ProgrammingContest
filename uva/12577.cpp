#include <iostream>
using namespace std;
int main() {
    string s;
    int i = 1;
    while(cin>>s){
        if(s.compare("*")==0){
            break;
        }
        printf("Case %d: Hajj-e-",i++);
        if(s.compare("Hajj")==0){
            printf("Akbar\n");
        }else{
            printf("Asghar\n");
        }
    }
    return 0;
}