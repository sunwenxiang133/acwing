//
// Created by sun on 22-5-3.
//
#include<iostream>
using namespace std;
const int N=510,INF=1e9;
int n;
int a[N][N];
int f[N][N];

int main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>a[i][j];
        }
    }
    //初始化，从i=0开始初始化，j<=i+1 要往外面多初始化一格，因为三角形判断的时候会判断到右上
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i+1;j++){
            f[i][j]=-INF;
        }
    }
    //第一个数不进行下面的计算
    f[1][1]=a[1][1];
    for(int i=2;i<n;i++){
        for(int j=1;j<=i;j++){
            f[i][j]= max(f[i-1][j-1]+a[i][j],f[i-1][j]+a[i][j]);
        }
    }

    int res=-INF;
    for(int i=1;i<=n;i++) res= max(res,f[n][i]);
    cout<<res;
    return 0;
}

/*
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

 30*/