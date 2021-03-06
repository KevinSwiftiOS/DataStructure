#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
//二叉树的定义
typedef struct BiTreeNode{
    char c;
    struct BiTreeNode *left;
    struct BiTreeNode *right;
}node,*Nodetree;
//visit为一函数指针 用于传递二叉树中对节点的操作方式 其原型为
// int(*visit)(char)
//递归方式实现二叉树的先序遍历
void PreOrder(Nodetree ptee){
    if(ptee){
        cout<<ptee -> c;
        PreOrder(ptee->left);
        PreOrder(ptee->right);
        
    }
}
//中序遍历
void InOrder(Nodetree ptree){
    if(ptree){
        InOrder(ptree->left);
        cout<<ptree->c;
        InOrder(ptree->right);
    }
    }
//后序遍历
void PostOrder(Nodetree ptree){
    if(ptree){
        PostOrder(ptree->left);
        PostOrder(ptree->right);
        cout<<ptree->c;
    }
}
struct queue{
    Nodetree key;
};
//层次遍历 用到了队列的知识 类似于广搜 如果左孩子存在 左孩子就入队列 右孩子存在 右孩子就入队列
void LevelOrder(Nodetree ptree){
    int rear = -1;
    int front = -1;
    queue q[10000];
    if(!ptree)
        return;
    q[++rear].key = ptree;
    while(front < rear){
        if(ptree){
            ptree = q[++front].key;
            cout<<ptree -> c;
            if(ptree -> left)
                q[++rear].key = ptree->left;
            if(ptree->right)
                q[++rear].key = ptree->right;
        }else{
            break;
        }
    }
    
}
//二叉树的创建 以递归方式实现的先序创建二叉树
Nodetree createTreeProOrder() {
    BiTreeNode *ptree = NULL;
    char ch;
    ch = getchar();
    if(ch == ' ')
        ptree = NULL;
    else{
       //进行创建树
        ptree = (struct BiTreeNode *)malloc(sizeof(BiTreeNode));
        ptree->c = ch;
        ptree->left = createTreeProOrder();
        ptree->right = createTreeProOrder();
    }
    return ptree;
}
int main() {
     Nodetree  ptree = createTreeProOrder();
    PreOrder(ptree);
    cout<<endl;
    InOrder(ptree);
    cout<<endl;
    PostOrder(ptree);
    return 0;
}

