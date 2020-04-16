#include <iostream>
#include <vector>
#define MAX_SIZE 100010
#define MAX_NUMBER 1000010

using namespace std;
int web[MAX_NUMBER];
vector<int> prime;
int main() {
  for (int i=1;i<=MAX_NUMBER;i++)
    web[i] = i;
  for (int i=2;i<=MAX_NUMBER;i++) {
    if (web[i] == i) {
      prime.push_back(i);
      for(int j=2;i*j<=MAX_NUMBER;j++) {
        web[i*j] = min(web[i*j], i);
      }
    }
  }
  printf("%d\n", prime.size());
  for(int i=0;i<prime.size();i++){
    printf("%d ", prime[i]);
  }
  return 0;
}
