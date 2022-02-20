#include <stdio.h>

//이진트리의 구조체 선언과 ADT

typedef struct _bTreeNode{
    int data; 
    struct _bTreeNode *left;
    struct _bTreeNode *right;
}BTreeNode;

BTreeNode *MakeTreeNode(void){ //트리를 만드는 함수
    BTreeNode *nd = (BTreeNode *malloc(sizeof(BTreeNode)));
    nd->left = NULL;
     //왼쪽 서브 트리를 가리키기 위한 멤버를 NULL로 초기화
    nd->right = NULL;
    //오른쪽 서브 트리를 가리키기 위한 멤버를 NULL로 초기화
}

BTreeNode *getdata(BTreeNode *nd){
    return nd->data; //노드의 데이터를 반환하는 함수
}

void setdata(BTreeNode *nd,int data){
    nd->data = data; //노드에 데이터를 저장하는 함수
}

BTreeNode *getLeftSubTree(BTreeNode *nd){
    return nd->left //왼쪽 서브트리의 주소를 반환하는 함수
}

BTreeNode *getRightSubTree(BTreeNode *nd){
    return nd->right;//오른쪽 서브트리의 주소를 반환하는 함수
}

void MakeLeftSubTree(BTreeNode *main,BTreeNode *sub){ //왼쪽서브트리를 연결하는 함수

    if(main->left != NULL){ //이미 서브트리가 있다면 트리를 삭제하고 새로운 왼쪽 서브 트리를 연결
        free(main->left);
    }
    main->left = sub;
}

void MakeRightSubTree(BTreeNode *main,BTreeNode *sub){
    if(main->right != NULL){//이미 서브트리가 있다면 트리를 삭제하고 새로운 오른쪽 서브 트리를 연결
        free(main->right);
    }
    main->right = sub;
}