#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int Person_Time[1001];

int main() {
    int N, sum=0;
    scanf("%d", &N);
    for(int i = 0;i<N;i++){
        scanf("%d", &Person_Time[i]);
    }
    std::sort(Person_Time,Person_Time+N);
    for(int i =0;i<N;i++){
        sum+= (N-i)*Person_Time[i];
    }
    printf("%d\n", sum);
    return 0;
}