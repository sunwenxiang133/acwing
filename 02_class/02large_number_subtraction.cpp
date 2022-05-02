//
// Created by sun on 2022/3/12.
//


#include<iostream>
#include<string>
#include <vector>
using namespace std;

bool cmp(vector<int> &A,vector<int> &B){
    if(A.size()!=B.size()){
        return A.size()>B.size();
    }
    for(int i=A.size()-1;i>=0;i++){
        if(A[i]!=B[i]){
            return A[i]>=B[i];
        }
    }
    return true;  //如果执行到了这里，就是A和B是相等的
}

vector<int>sub(vector<int> &A,vector<int> &B){
    vector<int> C;  //还债，个位，进位
    for(int i=0,t=0;i<A.size();i++){
        t=A[i]-t;    //还债
        if(i<B.size()) t-=B[i];
        C.push_back((t+10)%10); //判断个位
        //如果是<0的要加10,如果大于0的本身加上10再%10是ok的
        if(t<0) t=1;   //记录进位
        else t=0;
        //这步用来判断是否借位了，上面一步用于判断个位的数字，而且上面的操作是不影响数本身的
    }
    while(C.size()>1 && C.back()==0) C.pop_back();
    return C;
}

int main() {
    string a,b;
    vector<int> A,B;
    cin>>a>>b;
    for(int i=a.size()-1;i>=0;i--){
        A.push_back(a[i]-'0');
    }
    for(int i=b.size()-1;i>=0;i--){
        B.push_back(b[i]-'0');
    }
    if(cmp(A,B)){
        auto C=sub(A,B);
        for(int i=C.size()-1;i>=0;i--){
            printf("%d",C[i]);
        }
    }else{
        auto C= sub(B,A);
        printf("-");
        for(int i=C.size()-1;i>=0;i--){
            printf("%d",C[i]);
        }
    }
    return 0;
}