#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define sci(n) scanf("%d", &(n))

int main() {
    int N, result;
    sci(N);
    vector<int> data(N), sorted;
    for(int i=0;i<N;i++){
        sci(data[i]);
    }
    sorted = data;
    sort(sorted.begin(), sorted.end());
    vector<int> diff_Point;
    int diff;
    for(int i=1;i<N-1;i++){
        if(sorted[i]-sorted[i-1] == sorted[i+1]-sorted[i]){
            diff = sorted[i]-sorted[i-1];
            break;
        }
    }
    for(int i=1;i<N;i++) {
        if(sorted[i]-sorted[i-1] != diff) {
            diff_Point.push_back(i);
        }
    }
    if (diff_Point.size() == 0) {
        result = 0;
    } else if (diff_Point.size() == 1) {
        if(diff_Point[0]==1) result = 0;
        else result = 1;
    } else if (diff_Point.size() == 2) {
        result = diff_Point[0];
    }
    else {
        printf("-1");
        return 0;
    }
    for(int i=0;i<N;i++) {
        if(sorted[result] == data[i]) {
            printf("%d", i+1);
            return 0;
        }
    }
    return 0;
}
