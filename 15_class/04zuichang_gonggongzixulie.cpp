//
// Created by sun on 22-5-3.
//
#include<iostream>
using namespace std;
int n,m;
const int N=1010;
char a[N],b[N];
int f[N][N];

int main() {
    cin>>n>>m;
    //读取字符串变成字符数组的方法
    scanf("%s%s",a+1,b+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[i][j]= max(f[i-1][j],f[i][j-1]);
            if(a[i]==b[j]) f[i][j]= max(f[i][j],f[i-1][j-1]+1);
        }
    }
    cout<<f[n][m];
    return 0;
}

/*
4 5
acbd
abedc

 3
 */
