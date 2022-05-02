//
// Created by sun on 2022/4/8.
//
#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
const int N=110;
int f[N][N];
int v[N],w[N],s[N];

int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i]>>s[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=s[i]&&k*v[i]<=j;k++){
                f[i][j]= max(f[i][j],f[i-1][j-v[i]*k]+w[i]*k);
            }
        }
    }
    cout<<f[n][m]<<endl;
    return 0;
}
/*4 5
1 2 3
2 4 1
3 4 3
4 5 2

 10*/

