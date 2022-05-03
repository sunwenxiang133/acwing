//
// Created by sun on 22-5-3.
//
#include<iostream>
using namespace std;
const int N=1010;
int n;
int a[N],f[N];
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        f[i]=1;
        for(int j=1;j<=i;j++){
            if(a[j]<a[i]){
                f[i]= max(f[i],f[j]+1);
            }
        }
    }
    int res=0;
    for(int i=1;i<=n;i++){
        res= max(res,f[i]);
    }
    cout<<res;
    return 0;
}

/*
7
3 1 2 1 8 5 6

4*/
