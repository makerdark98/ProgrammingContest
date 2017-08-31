#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int N;
    scanf("%d\n",&N);
    vector<string> words;
    words.resize(N);
    for(int i=0;i<N;i++){
        getline(cin, words[i]);
    }
    sort(words.begin(), words.end(), [](string x, string y)->bool{
            int xl = x.length();
            int yl = y.length();
            if(xl==yl){
                for(int i=0;i<xl;i++){
                    if(x[i]<y[i]) return true;
                    if(x[i]>y[i]) return false;
                }
            }
            return xl<yl;
            });
    auto pos =unique(words.begin(), words.end());
    words.erase(pos, words.end());
    for(int i=0;i<words.size();i++){
        cout<<words[i]<<endl;
    }
    return 0;
}
