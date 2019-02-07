#include <iostream>
using namespace std;
#define sci(n) scanf("%d", &(n))
int main() {
    int tmp;
    for(int i=0;i<3;i++) {
        int result = 0;
        char output;
        for(int j=0;j<4;j++){
            sci(tmp);
            result+= tmp;
        }
        if(result == 3) output = 'A';
        else if (result == 2) output = 'B';
        else if (result == 1) output = 'C';
        else if (result == 0) output = 'D';
        else output = 'E';
        printf("%c\n", output);
    }

    return 0;
}
