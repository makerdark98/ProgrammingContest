#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
set<string> visited;
bool chk(string data, vector<int> count)
{
  for (auto& c : data) count[c-'a'] --;

  for(int i=0;i<26;i++) 
    if (count[i] != 0) return false;

  return true;
}

vector<string> gen(string data) {
  vector<string> retval;
  string f, b, f_r, b_r;
  vector<string> r;
  if (data.size() == 1) 
    retval.push_back(data);

  else if (data.size() % 2 == 0) {
    f = data.substr(0, data.size() / 2); b = data.substr(data.size() / 2);

    r = gen(b); f_r = f; reverse(f_r.begin(), f_r.end());
    for (auto& d : r) retval.push_back(f_r+d);

    r = gen(f); b_r = b; reverse(b_r.begin(), b_r.end());
    for (auto& d : r) retval.push_back(d+b_r);

  } else {
    f = data.substr(0, data.size() / 2); b = data.substr(data.size() / 2);

    r = gen(b); f_r = f; reverse(f_r.begin(), f_r.end());
    for (auto& d : r) retval.push_back(f_r+d);

    r = gen(f); string b_r = b; reverse(b_r.begin(), b_r.end());
    for (auto& d : r) retval.push_back(d+b_r);

    f = data.substr(0, data.size() / 2 + 1); b = data.substr(data.size() / 2 + 1);

    r = gen(b); f_r = f; reverse(f_r.begin(), f_r.end());
    for (auto& d : r) retval.push_back(f_r+d);

    r = gen(f); b_r = b; reverse(b_r.begin(), b_r.end());
    for (auto& d : r) retval.push_back(d+b_r);
  }
  return retval;
}

void solve(string data) {
  vector<string> s = gen(data);
  for(auto& d : s) {
    visited.insert(d);
  }
}


int main (){
  int n, cnt, length;
  string input;
  char a;

  scanf("%d", &n);
  vector<int> count(26, 0);

  length = 0;
  for (int i=0;i<n;i++) {
    scanf(" %c %d", &a, &cnt);
    count[a-'a'] += cnt;
    length += cnt;
  }

  cin >> input;

  for (int i=0;i<=input.length() - length;i++){
    string tmp = input.substr(i, length);
    if(chk(tmp, count))
      solve(tmp);
  }

  printf("%d", (int)visited.size());
  return 0;
}
