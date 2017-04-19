#include<iostream>
#include<stdlib.h>
using namespace std;
void InsertSort(int a[],int length){
    int i,j,k,temp;
    for(i = 0; i < length;i++){
        //从后向前移动
        for(j = i - 1;j >= 0; j--)
            //找到一个比a[i]打的
            if(a[i] > a[j])
                break;
        temp = a[i];
        //如果这个数已排好的数组中
        if(j != i - 1){
          //向后移
            for(k = i - 1; k >= 0 && a[k] > temp;k--){
                a[k + 1] = a[k];
            }
            a[k + 1] = temp;
        }
    }
}
int main() {
    int a[5] = {1,5,2,3,4};
    InsertSort(a, 5);
    for(int i = 0; i < 5;i++)
        cout<<a[i]<<" ";
    return 0;
}
