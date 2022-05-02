//
// Created by sun on 2022/3/12.
//


#include <iostream>
#include <string>
#include<vector>
using namespace std;

vector<int> mul(vector<int>&A,int b){
    vector<int> C;
    int t=0;
    for (int i = 0; i < A.size()|t; ++i) {  //有个|t是因为当A.size计算到最后一位的时候，可能会有进位，这时判断条件就是t！=0
        if(i<A.size()) t+=A[i]*b;  //上一项剩下的和新的加在一起
        C.push_back(t%10); //当前位
        t/=10;   //进位
    }
    return C;
}

int main() {
    string a;
    int b;
    cin>>a>>b;
    vector<int> A;
    for (int i = a.size()-1; i >0; --i) {
        A.push_back(a[i]-'0');
    }
    auto C=mul(A,b);
    for (int i = C.size()-1; i >0; --i) {
        printf("%d",C[i]);
    }
}