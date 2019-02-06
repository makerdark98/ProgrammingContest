#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using lld = long long;
#define scl(n) scanf("%lld", &(n))
#define scd(n) scanf("%lf", &(n))
int main(){
    lld loanDuration, nRec;
    double downPayment, loan;
    while(true){
        vector<double> decRatio;
        scl(loanDuration), scd(downPayment), scd(loan), scl(nRec);
        if(loanDuration < 0) break;
        lld a;
        double b=0, preb;
        for(lld i = 0; i<nRec ;i++){
            scl(a), scd(b);
            while(decRatio.size() < (size_t)a) decRatio.push_back(preb);
            preb = b;
        }
        decRatio.push_back(preb);
        lld result = 0;
        double monthlyPayment = loan / loanDuration;
        double curVal = (loan + downPayment) * (1.-decRatio[0]);
        double curLoan = loan;
        while(curVal < curLoan) {
            result++;
            curLoan -= monthlyPayment;
            curVal *= (1.-decRatio[min(result, (lld)decRatio.size()-1)]);
        }
        printf("%lld %s\n", result, result != 1 ? "months" : "month");
    }
    return 0;
}
