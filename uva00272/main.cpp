#include <iostream>
using namespace std;
int main() {
    string str;
    bool isClose = true;
    while(getline(cin, str)) {
        for(int i = 0; i < str.length(); i++) {
            char c = str.at(i);
            if (c == '\"') {
                isClose ? cout << "``" : cout << "\'\'";
                isClose = (!isClose);
            } else {
                cout << c;
            }
        }
        cout<<endl;
    }
    return 0;
}