#include <stdio.h>
#include <stdlib.h>


typedef struct __Node{
    char Data;
    __Node* Left;
    __Node* Right;
} Node;

void SetNode(Node* node, char data);
Node* SearchNode(Node* tree, char data);
void SetLeft(Node* Root, Node* Child);
void SetRight(Node* Root, Node* Child);
void DestroyTree(Node* Root);

void preorder(Node* Root);
void Inorder(Node* Root);
void Postorder(Node* Root);

int main(){
    int i, j;
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
    preorder(Root);
    printf("\n");

    Inorder(Root);
    printf("\n");

    Postorder(Root);
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
    if(Root->Left == NULL && Root->Right == NULL){
        free(Root);
        return;
    }
    DestroyTree(Root->Left);
    DestroyTree(Root->Right);
}
void SetLeft(Node* Root, Node* Child){
    Root->Left = Child;
}
void SetRight(Node* Root, Node* Child){
    Root->Right = Child;
}

void preorder(Node* Root){
    printf("%c", Root->Data);
    if(Root->Left!=NULL) {
        preorder(Root->Left);
    }
    if(Root->Right!=NULL) {
        preorder(Root->Right);
    }
}

void Inorder(Node* Root) {
    if(Root->Left!=NULL) {
        Inorder(Root->Left);
    }
    printf("%c", Root->Data);
    if(Root->Right!=NULL) {
        Inorder(Root->Right);
    }
}

void Postorder(Node* Root){
    if(Root->Left!=NULL) {
        Postorder(Root->Left);
    }
    if(Root->Right!=NULL) {
        Postorder(Root->Right);
    }
    printf("%c", Root->Data);
}