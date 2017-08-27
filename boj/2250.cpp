#include <stdio.h>
#include <stdlib.h>


typedef struct __Node{
    char Data;
    struct __Node* Left;
    struct __Node* Right;
} Node;

void SetNode(Node* node, char data);
Node* SearchNode(Node* tree, char data);
void SetLeft(Node* Root, Node* Child);
void SetRight(Node* Root, Node* Child);
void DestroyTree(Node* Root);

void Inorder(Node* Root);

int main(){
    int i, j, x, y;
    int N;
    char Parent, Right, Left;
    Node *tmp, *tmp2;
    Node* Root = (Node*)malloc(sizeof(Node));


    SetNode(Root, 'A');

    scanf("%d", &N);

    for(i=0;i<N;i++){
        scanf(" %c", &Parent);
        tmp = SearchNode(Root, Parent);

        scanf(" %c", &Left);
        if(Left!='.') {
            tmp2=(Node*)malloc(sizeof(Node));
            SetNode(tmp2, Left);
            SetLeft(tmp, tmp2);
        }

        scanf(" %c", &Right);
        if(Right!='.') {
            tmp2=(Node*)malloc(sizeof(Node));
            SetNode(tmp2, Right);
            SetRight(tmp, tmp2);
        }
    }
    Inorder(Root,x,y);
    printf("\n");

    DestroyTree(Root);

    return 0;
}


void SetNode(Node* node, char data){
    node->Left=NULL;
    node->Right=NULL;
    node->Data = data;
}
Node* SearchNode(Node* tree, char data){
    Node* tmp;
    if(tree==NULL) return NULL;
    if(tree->Data==data) return tree;
    tmp=SearchNode(tree->Left, data);
    if(tmp!=NULL) return tmp;
    tmp=SearchNode(tree->Right, data);
    if(tmp!=NULL) return tmp;
    return NULL;
}
void DestroyTree(Node* Root){
    if(Root==NULL) return;
    free(Root);
    DestroyTree(Root->Left);
    DestroyTree(Root->Right);
}
void SetLeft(Node* Root, Node* Child){
    Root->Left = Child;
}
void SetRight(Node* Root, Node* Child){
    Root->Right = Child;
}

void Inorder(Node* Root, int& x, int& y) {
    if(Root->Left!=NULL) {
        Inorder(Root->Left);
    }
    printf("%c", Root->Data);
    if(Root->Right!=NULL) {
        Inorder(Root->Right);
    }
}
