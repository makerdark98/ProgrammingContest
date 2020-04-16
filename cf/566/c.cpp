#include <iostream>
#include <map>
#include <string>
#include <vector>
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%I64d", &(n))
using namespace std;
using lld = long long;
using vi = vector<lld>;
using vvi = vector<vi>;

bool isVowel(const char& c){
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}
int main() {
    int n;
    sci(n);
    vector<string> data(n);
    map<int, map<char, vi> > vowels;
    vector<pair<int, int> > complete_results;
    for(int i=0;i<n;i++){
        cin>>data[i];
        int cnt =0;
        for(const auto& c:data[i]){
            if(isVowel(c)) cnt++;
        }
        for(auto c=data[i].rbegin();c<data[i].rend();c++){
            if(isVowel(*c)){
                vowels[cnt][*c].push_back(i);
                if(vowels[cnt][*c].size() == 2) {
                    complete_results.push_back({vowels[cnt][*c][0], vowels[cnt][*c][1]});
                    vowels[cnt][*c] = vi(0);
                }
                break;
            }
        }
    }
    vector<pair<int, int> > sub_pairs;

    for(auto& vowel : vowels) {
        vi tmp;
        for(auto& t : vowel.second) {
            for(auto& n : t.second) {
                tmp.push_back(n);
                if(tmp.size() == 2) {
                    sub_pairs.push_back({tmp[0], tmp[1]});
                    tmp = vi(0);
                }
            }
        }
    }

    vector<pair<pair<int, int>, pair<int, int> > > result;

    while(!complete_results.empty()) {
        pair<int, int> first;
        pair<int, int> second = complete_results.back();
        complete_results.pop_back();
        if(!sub_pairs.empty()) {
            first = sub_pairs.back();
            sub_pairs.pop_back();
        } else if(!complete_results.empty()) {
            first = complete_results.back();
            complete_results.pop_back();
        } else {
            break;
        }
        result.push_back({first, second});
    }


    printf("%lu\n", result.size());
    for(auto& r: result) {
        cout << data[r.first.first] << " " << data[r.second.first] << endl;
        cout << data[r.first.second] << " " << data[r.second.second] << endl;
    }
    
    return 0;
}
