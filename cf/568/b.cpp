#include <iostream>
#include <string>
using namespace std;
#define sci(n) scanf("%d", &(n))
bool solve(string& a, string& b);
int main() {
    int N;
    sci(N);
    while(N--) {
        string a, b;
        cin >> a >> b;
        printf("%s\n", solve(a, b) ? "YES" : "NO");
    }
    return 0;
}
bool solve(string& a, string& b) {
    int j=0;
    int i;
    for(i=0;i<a.size() && j <b.size();i++) {
        if(a[i]!=b[j]) {
            return false;
        }
        while(j<b.size() && a[i]==b[j]){
            j++;
            if(i<a.size()-1 && a[i]==a[i+1]) {
                i++;
                if(a[i]!=b[j]) return false;
            }   
        }
    }
    if(j!=b.size() || i!=a.size()) return false;
    return true;
}
