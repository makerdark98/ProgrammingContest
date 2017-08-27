#include <iostream>

using namespace std;
int main() {
    string S;
    for(int i =1;;i++) {
        getline(cin, S);
        if (S.compare("#") == 0) {
            break;
        }
        printf("Case %d: ", i);
        if (S.compare("HELLO") == 0) {
            printf("ENGLISH\n");
        } else if (S.compare("HOLA")==0) {
            printf("SPANISH\n");
        } else if (S.compare("HALLO")==0) {
            printf("GERMAN\n");
        } else if (S.compare("BONJOUR")==0) {
            printf("FRENCH\n");
        } else if (S.compare("CIAO")==0) {
            printf("ITALIAN\n");
        } else if (S.compare("ZDRAVSTVUJTE")==0) {
            printf("RUSSIAN\n");
        } else{
            printf("UNKNOWN\n");
        }
    }
    return 0;
}