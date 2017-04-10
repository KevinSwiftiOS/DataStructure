#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
//本题是从x到y上 所以要通过z作为中间件 先把x上的n-1个通过y移到z 随后把最后一个移到y上 随后再将z上的n-1个移到y上
void hanno(int n,char x,char y,char z){
    if(n == 1){
        cout<<x<< "-" << y<<endl;
    }else{
        
        hanno(n - 1,x,z,y);
        cout<<x<<"-"<<y<<endl;
        hanno(n - 1,z,y,x);
    }

}
int main() {
    int n;
    cin>>n;
    hanno(n,'a','b','c');
    return 0;
}
