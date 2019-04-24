#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
    vector<int> a;//初始化
    vector<int> b(10);
      vector<int> c(10,1); //10个大小，初始化为1
    int d[7]={1,2,3,4,5,9,8};
    vector<int> e(d,d+7); //从数组中获得初值
    cout<<e.back(); //最后一个元素
    vector<int> a;
    for(int i=0;i<10;i++) //向里面投放值
        a.push_back(i);
    //输出值 利用下标
    for(int i =0; i < 11;i++)
        cout<<a[i];
    //利用迭代器
    for(vector<int>::iterator it = a.begin();it != a.end();it++)
        cout<<*it;
    return 0;
}
//参考链接 https://www.cnblogs.com/Nonono-nw/p/3462183.html
