//
// Created by sun on 2022/3/14.
//

#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

using namespace std;

//A 除 tmp 余数是C  虽然除法从最高为开始计算比较好，但是为了和加减乘保持一致
vector<int> div(vector<int> &A,int b,int &r){
    vector<int> C;
    r=0;
    for(int i = A.size()-1;i>=0;--i){
        r=r*10+A[i];
        C.push_back(r/b);
        r%=b;
    }
    reverse(C.begin(),C.end());  //因为算出来的除法是倒着的，所以逆序输出
    return C;
}

int main(){
    string a;
    int b;
    cin>>a>>b;
    vector<int> A;
    for(int i=a.size()-1;i>=0;i--){
        A.push_back(a[i]-'0');
    }
    int r;
    auto C= div(A,b,r);
    for(int i=C.size()-1;i>=0;i--){
        printf("%d",C[i]);
    }
    cout<<endl<<r<<endl;
    return 0;
}