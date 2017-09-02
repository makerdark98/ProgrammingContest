#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    deque<int> dq;
    while(n--){
        string input;
        cin>>input;
        if(input.compare("push_front")==0){
            int x;
            scanf("%d",&x);
            dq.push_front(x);
        }else if(input.compare("push_back")==0){
            int x;
            scanf("%d",&x);
            dq.push_back(x);
        }else if(input.compare("pop_front")==0){
            int result=-1;
            if(!dq.empty()){ result=dq.front();
                dq.pop_front();
            }
            printf("%d\n",result);
        }else if(input.compare("pop_back")==0){
            int result=-1;
            if(!dq.empty()){ result=dq.back();
                dq.pop_back();
            }
            printf("%d\n",result);
        }else if(input.compare("size")==0){
            printf("%d\n",(int)dq.size());
        }else if(input.compare("empty")==0){
            int result=0;
            if(dq.empty()) result = 1;
            printf("%d\n",result);
        }else if(input.compare("front")==0){
            int result=-1;
            if(!dq.empty()){
                result=dq.front();
            }
            printf("%d\n",result);
        }else if(input.compare("back")==0){
            int result=-1;
            if(!dq.empty()){
                result=dq.back();
            }
            printf("%d\n",result);
        }
    }
    return 0;
}
