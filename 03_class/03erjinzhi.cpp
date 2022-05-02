//
// Created by sun on 2022/3/15.
//

//n（大于8）的二进制表示的后面4位是多少

#include<iostream>

using namespace std;

int main(){
    int n=0;
    cin>>n;
    for(int k=3;k>=0;k--) cout<<(n>>k&1);  //输出后面4位
    return 0;
}