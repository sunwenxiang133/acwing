//
// Created by sun on 2022/4/8.
//
#include<iostream>
#include<algorithm>
using namespace std;
const int N=110;
int n,m;
int v[N],w[N];
int f[N][N];

int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k*v[i]<=j;k++){
                f[i][j]= max(f[i][j],f[i-1][j-v[i]*k]+w[i]*k);
            }
        }
    }
    cout<<f[n][m]<<endl;
    return 0;
}

/*
4 5
1 2
2 4
3 4
4 5

10
*/