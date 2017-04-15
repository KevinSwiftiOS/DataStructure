#include<iostream>
#include<cstring>
#include<string>
using namespace std;
#define MaxVertexNum 100
//由用户定义的类型
typedef char VertexType;
//由用户定义边上的权值类型
typedef int EdgeType;
typedef struct {
    VertexType vexs[MaxVertexNum];
    //二维矩阵
    EdgeType edges[MaxVertexNum][MaxVertexNum];
    int n,e;
}MGrap;
void createMap(MGrap *G){
    int i ,j,k,w= 0,p;
    cout<<"请输入顶点数和边数";
    cin>>G->n>>G->e;
    for(p = 0; p < G->n;p++){
        //清除缓冲区
        fflush(stdin);
        cout<<"输入顶点信息";
        G->vexs[p] = getchar();
        getchar();
    }
    cout<<"临界矩阵的初始化";
    for(i = 1; i <= G->n;i++){
        for(j = 1; j <= G->n; j++)
            G->edges[i][j] = 0;
    }
    
for(k = 0; k < G->e;k++) {
    cout<<"请输入两个顶点(i,j)之间边的值";
    cin>>i>>j>>w;
    G->edges[i][j] = w;
    G->edges[j][i] = w;
}
}
int main() {
    MGrap *G = (MGrap *)malloc(sizeof(MGrap));
    createMap(G);
    for(int i = 1; i <= G->n;i++){
        for(int j = 1; j <= G->n;j++)
            cout<<G->edges[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
