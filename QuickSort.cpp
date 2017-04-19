#include<iostream>
#include<stdlib.h>
using namespace std;
int Partition(int a[],int left,int right){
     //定义交换的临时值
    int temp;
    //定义航标
    int Pivo = a[left];
    //循环
    while(left < right){
        //轴右边的值都比轴值大
        while(left < right && a[right] >= Pivo)
            --right;
            //当找到第一个比轴值晓得值得时候 与轴的值进行交换
        temp = a[left];
        a[left] = a[right];
        a[right] = temp;
        while (left < right && a[left] <= Pivo)
            ++left;
        temp = a[left];
        a[left] = a[right];
        a[right] = temp;
        
    }
    return left;
}
//进行快速排序的核心代码
void QuickSort(int a[],int left,int right){
    if(left < right){
        int p = Partition(a, left, right);
        //递归的排序左边的 递归的排序右边的
        QuickSort(a, left, p - 1);
        QuickSort(a,p + 1, right);
    }
}

int main() {
    int a[5] = {1,5,2,3,4};
    InsertSort(a, 5);
    for(int i = 0; i < 5;i++)
        cout<<a[i]<<" ";
    return 0;
}
