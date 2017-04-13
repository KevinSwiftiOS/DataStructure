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
//非递归先序遍历二叉树 先将根的结果输出 随后压入栈的时候应注意 先将右子树压入 再压入左子树
struct stack{
    BiTreeNode key;
};
void PreOrder(Nodetree ptree){
    int top = -1;
    stack s[10000];
    if(ptree)
        s[++top].key = *ptree;
    while(top != -1) {
         //进行出栈
        BiTreeNode cur = s[top--].key;
        cout<<cur.c;
      
       if(cur.right)
           s[++top].key = *cur.right;
        if(cur.left)
            s[++top].key = *cur.left;
    }
    
}
//非递归的中序 在栈不为空的前提下 先让左子树的节点全部入栈 随后弹出栈 随后变成他的右子树
void InOrder(Nodetree ptree){
    int top = -1;
    stack s[10000];
    Nodetree cur = ptree->left;
    s[++top].key = *ptree;
    while(cur || top != -1){
        //左子树全部的入栈
        while(cur){
        s[++top].key = *cur;
        cur = cur->left;
    }
    cur = &s[top--].key;
    cout<<cur->c;
    cur = cur->right;
    }
}
//非递归的后序 要定义一个指针表示他的右子树是否被访问过 首先也是所有的左子树入栈 之后再判断右子树是否为空或者是否被访问过 如果是空的或者已经被访问过了 则输出当前的元素 否则就变成他的右子树
void PostOrder(Nodetree ptr) {
    stack s[1000];
    int top = -1;
    Nodetree cur = ptr;//指向当前要检查的节点
    Nodetree preVisited = NULL;//指向前一个被访问的节点
    while (cur || top != -1) {
        //一直向左走直到为空的时候
        while (cur) {
            s[++top].key = *cur;
            cur = cur->left;
        }
        cur = &s[top].key;
        //当前右孩子如果为空或者已经被访问,则访问当前的节点
        if (cur->right == preVisited||cur->right==NULL) {
            cout << cur->c << " ";
            preVisited = cur;
            top--;
            cur = NULL;
        }
        else
            cur = cur->right;
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
//    PreOrder(ptree);
//    cout<<endl;
//   
//   InOrder(ptree);
//    cout<<endl;
   PostOrder(ptree);
//    cout<<endl;
//    LevelOrder(ptree);
    return 0;
}

