//
// Created by sun on 22-5-3.
//
#include<iostream>
using namespace std;
const int N=510;
int a[N][N],f[N][N];
int n;

int main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>a[i][j];
        }
    }
    //处理边界问题的另外一个办法，把所有无关的数都当作0,这样就算读取到了，也不会对题目造成影响
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            f[i][j]= max(f[i-1][j-1]+a[i][j],f[i-1][j]+a[i][j]);
        }
    }

    int res=-INT_FAST16_MAX;
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
           if(res<f[i][j]){
               res=f[i][j];
           }
        }
    }*/
    //比上面更好的写法
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
