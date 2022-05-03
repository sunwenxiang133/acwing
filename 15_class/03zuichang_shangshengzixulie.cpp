//
// Created by sun on 22-5-3.
//

//输出最长上升子序列的版本

#include<iostream>
using namespace std;
const int N=1010;
int n;
int a[N],b[N],f[N],g[N];
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        f[i]=1;
        for(int j=1;j<=i;j++){
            if(a[j]<a[i]){
                if(f[j]+1>f[i]){
                    g[i]=j;
                    f[i]=f[j]+1;
                }
            }
        }
    }
    int k=1;
    for(int i=1;i<=n;i++){
        if(f[k]<f[i]){
            k=i;
        }
    }
    cout<<f[k]<<endl;
    int temp;
    for(int i=0,temp=0,len=f[k];i<len;i++,temp++){
        b[temp]=a[k];
        k=g[k];
    }
    cout<<temp;
    for(int i=0;i<temp;i++){
        cout<<b[i];
    }
    return 0;
}

/*
7
3 1 2 1 8 5 6

4*/