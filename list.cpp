#include<stdlib.h>
#include<stdio.h>

typedef  struct student{
    //学号 分数 下一节点的指针
    int num;
    float score;
    struct student *next;
}Stu,*Node;
//节点总数
int n;
//进行创建 创建n个节点的链表 返回:指向链表表头的指针
 Node Create() {
    //头结点
     Node head;
    //p1保存创建的新节点的地址
     Stu *p1 = NULL;
    //P2保存原链表最后一个节点的地址
     student *p2 = NULL;
    //空链表
    n = 0;
    p1 = (student *)malloc(sizeof(student));
     p2 = p1;
     if(p1 == NULL){
         //创建节点不成功
         return NULL;
     }else{
         head = NULL;
         printf("请输入第%d个的分数和学号",n + 1);
         scanf("%d %f",&(p1->num), &(p1->score));
     }
     //只要学号不为0 就继续录入下一个节点
     while(p1 -> num != 0 ){
         n += 1;
         //如果节点的个数为1 则第一个就为他
         if(n == 1){
             head = p1;
             p2 -> next = NULL;
         }else{
             p2 -> next = p1;
         }
         p2 = p1;
         p1 = (student *)malloc(sizeof(student));
         printf("请输入成绩个数");
         scanf("%d %f", &(p1 -> num), &(p1 -> score));
        
     }
      p1 = NULL;
     return head;
}
//输出节点
void Print(student *head){
    struct student *p;
    printf("节点个数为%d",n);
    p = head;
    if(head != NULL){
        //头指针的地址
        printf("头在 %o\n",head);
        do{
            printf("%o %d %lf %o\n",p,p -> num, p -> score, p -> next);
            p = p -> next;
        }while(p != NULL);
    }
}
int main() {
   student *head =  Create();
    Print(head);
          return 0;
}
