#include <stdio.h>
#include <vector>

using namespace std;

int n, S;
int main() {
    int input;
    vector<int> a;
    vector<int> x;
    scanf("%d %d", &n, &S);
    for(int i=0;i<n;i++){
        scanf("%d", &input);
        a.push_back(input);
        x.push_back(input);
    }

    return 0;
}