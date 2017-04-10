//斐波那契数列的实现 可以用递归算法实现 或者用一个for 循环实现 如果为0就返回0 如果为1就返回1
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int feibo(int n){
    if(n == 1)
    return 1;
    else if(n == 0)
    return 0;
    else return feibo(n - 1) + feibo(n - 2);
}
int main() {
    int a[1000];
    a[0] = 0;a[1] = 1;
    cout<<feibo(5);
    for(int i = 2; i < 1000;i++)
    a[i] = a[i - 1] + a[i - 2];
    cout<<a[5];
}
