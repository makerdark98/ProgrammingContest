#include <iostream>
using namespace std;

int main() {
  string a; 
  getline(cin, a);
  int i=0;
  char data[] ="UCPC";
  for(const auto& c:a){
    if (c==data[i]){
      i++;
    }
  }
  printf("%s",i>=4 ? "I love UCPC " : "I hate UCPC ");
  return 0;
}
