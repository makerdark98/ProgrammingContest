#include <iostream>
using namespace std;

int main(){
    int init, first, second, third;
    int sum;
    while(cin>>init>>first>>second>>third){
        if(!init&&!first&&!second&&!third){
            return 0;
        }
        sum = 120;
        sum += (init - first + 40) % 40;
        sum += (second - first + 40) % 40;
        sum += (second - third + 40) % 40;
        cout<<sum*9<<endl;
    }
}
