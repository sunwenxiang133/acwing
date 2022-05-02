//
// Created by sun on 2022/4/8.
//
#include<iostream>
using namespace std;
int m,n;
const int N=100;
int f[N][N];
int v[N],w[N];  //v表示体积，w表示价值

int main() {
    cin>>n>>m;
    for (int i = 0; i <n; ++i) {
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=n;i++){   //选择物品的个数
        for(int j=0;j<=m;j++){   //能够选择的重量
            f[i][j]=f[i-1][j];
            if(j>=v[i])f[i][j]= max(f[i][j],f[i-1][j-v[i]]+w[i]);
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

8
*/
