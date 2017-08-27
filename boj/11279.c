//11279
//2957
//1717
//1199
//11724
//1260
//1922
#include <stdio.h>

int Heap[200000];
int idx=1;

void push(int x);
int pop();
void balance(int now_idx);

int main() {
    int N, i, O;
    scanf("%d", &N);
    for(i=0;i<N;i++){
        scanf("%d", &O);
        if(O==0){
            printf("%d\n", pop());
        }
        else{
            push(O);
        }
    }
    return 0;
}

void push(int x){
    Heap[idx] = x;
    balance(idx);
    idx++;
}

int pop(){
    if(idx==1) return 0;
    int out = Heap[1];
    Heap[1] = Heap[idx-1];
    Heap[idx-1] = 0;
    balance_down(1);
    idx--;
    return out;
}

void balance(int now_idx){
    int tmp;
    if(now_idx==1) return;
    if(Heap[now_idx]>Heap[now_idx/2]){
        tmp = Heap[now_idx];
        Heap[now_idx] = Heap[now_idx/2];
        Heap[now_idx/2] = tmp;
    }
    balance(now_idx/2);
}

void balance_down(int now_idx){
    int tmp, max_idx;
    if(now_idx>=idx) return;
    max_idx = Heap[now_idx*2]>Heap[now_idx*2+1] ? now_idx*2 : now_idx*2 +1;
    if(Heap[now_idx]<Heap[max_idx]){
        tmp = Heap[now_idx];
        Heap[now_idx] = Heap[max_idx];
        Heap[max_idx] = tmp;
        balance_down(max_idx);
    }
}