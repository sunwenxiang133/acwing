//
// Created by sun on 2022/3/12.
//

#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> add(vector<int> &A,vector<int>&B){
    //传指针不传vector的原因是指针更快，如果传vector还要整个复制一遍
    vector<int> C;
    if(A.size()<B.size()) return add(B,A); //这样A的size一定是大于B的size，后面就不用加上B的判断条件了
    int t=0;
    for(int i=0;i<A.size();i++){
        //if(i<A.size())
            t+=A[i];
        if(i<B.size()) t+=B[i];
        C.push_back(t%10);
        t/=10;
    }
    if(t) C.push_back(1);  //如果最高位有进位补上1
    return C;
}

int main() {
    string a,b;
    vector<int>A,B;
    cin>>a>>b;  //h="123456"
    for(int i=a.size()-1;i>=0;i--){
        A.push_back(a[i]-'0');  //倒叙输入
    }
    for(int i=b.size()-1;i>=0;i--){
        B.push_back(b[i]-'0');
    }
    auto C= add(A,B);
    for(int i=C.size()-1;i>=0;i--){
        printf("%d",C[i]); //把本身倒叙的正向输出
    }
    return 0;
}
