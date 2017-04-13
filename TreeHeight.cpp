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
//统计节点的个数 也是用到了递归的操作 左孩子右孩子碰到 节点的个数就加1
int countTree(Nodetree ptr){
    if(ptr)
        return countTree(ptr->left) + countTree(ptr->right) + 1;
    else
        return 0;
}
//统计叶节点的个数 也用放到了递归 当他的左子树和右子树都不存在的时候 则他就为叶节点
int cnt = 0;
void countLeaf(Nodetree ptr) {
    if(!ptr->left&&!ptr->right) {
        cnt++;
        return;
    }
    else  {
        if(ptr->left)
            countLeaf(ptr->left);
        if(ptr->right)
            countLeaf(ptr->right);
    }
}


//统计数的高度
int height = 0;
int treeHeight(Nodetree ptr) {
    if (ptr->left) {
        return treeHeight(ptr->left) + 1;
    }
    if (ptr->right) {
        return treeHeight(ptr->right) + 1;
    }
    if (ptr)
        return 1;
    return 1;
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
  //统计树的高度
   cout<< treeHeight(ptree)<<endl;
   
    //统计叶节点的个数
    countLeaf(ptree);
    cout<<cnt<<endl;
    //统计节点的个数
    cout<<countTree(ptree);
    
//    cout<<endl;
//    LevelOrder(ptree);
    return 0;
}

