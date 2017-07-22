#include <stdio.h>

int Tree[27][2];
int A2N(char n){
    return n-'A'+1;
}
char N2A(int n){
    return n+'A'-1;
}
void inorder(int A){
    if(A==0) return;
    inorder(Tree[A][0]);
    printf("%c", N2A(A));
    inorder(Tree[A][1]);
}
void preorder(int A){
    if(A==0) return;
    printf("%c", N2A(A));
    preorder(Tree[A][0]);
    preorder(Tree[A][1]);
}
void postorder(int A){
    if(A==0) return;
    postorder(Tree[A][0]);
    postorder(Tree[A][1]);
    printf("%c", N2A(A));
}
int main(){
    int T;
    char a, l, r;
    scanf("%d", &T);
    for(int i=0;i<T;i++){
        scanf(" %c %c %c",&a, &l, &r);
        if(l!='.') Tree[A2N(a)][0]=A2N(l);
        if(r!='.') Tree[A2N(a)][1]=A2N(r);
    }
    preorder(1);
    printf("\n");
    inorder(1);
    printf("\n");
    postorder(1);
    return 0;
}