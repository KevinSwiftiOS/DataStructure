#include<iostream>
#include<cstring>
#include<string>
using namespace std;
#define MaxVertexType 100
typedef char VertexType;
//边表节点
typedef struct node{
    int adjvex;
    node *next;
}EdgeNode;
//顶点表的节点
typedef struct {
    VertexType vertex;
    EdgeNode *firstedge;
}VertexNode;
//顶点表数组
typedef VertexNode AdjList[MaxVertexType];
typedef struct {
    AdjList adjlist;
    int n,e;
}Algraph;
//建立无向表的过程
void create(Algraph *G){
    int i,j,k,w,v;
    EdgeNode *s;
    cout<<"读入顶点数和边数:";
    cin >> G->n >> G->e;
    for(i = 0; i < G->n;i++){
        fflush(stdin);
        cout<<"建立顶点表";
        G->adjlist[i].vertex = getchar();
        getchar();
        G->adjlist[i].firstedge = NULL;
    }
  cout<<"建立边表:";
    for(k = 0; k < G->e;k++){
        cout<<"读入(vi-vj的顶点序列号";
        cin>>i>>j;
        s = (EdgeNode *)malloc(sizeof(EdgeNode));
        //下一条边的位置
        s->adjvex=j;
        //插入到表头中
        s->next = G->adjlist[i].firstedge;
        G->adjlist[i].firstedge = s;
        //这里是有向图的进行插入
        s=(EdgeNode *)malloc(sizeof(EdgeNode));
        s->adjvex = i;
        s->next = G->adjlist[j].firstedge;
        G->adjlist[j].firstedge = s;
    }
}
int main() {
    Algraph *G = (Algraph *)malloc(sizeof(Algraph));
    create(G);
    for(int i = 0; i < G->n;i++){
        cout<<i;
        while(G->adjlist[i].firstedge != NULL){
            cout<<G->adjlist[i].firstedge->adjvex;
            G->adjlist[i].firstedge = G->adjlist[i].firstedge->next;
            
        }
        cout<<endl;
    }
}
