#include <iostream>
using namespace std;
int main() {
    int T, sum=0;
    cin>>T;
    while(T--){
        string s;
        getline(cin,s);
        if(s.compare("report")==0){
            printf("%d\n",sum);
        }else{
            if(s.length()<7){
                T++;
            }else {
                string num = s.substr(7, s.length());
                sum += stoi(num);
            }
        }
    }
    return 0;
}