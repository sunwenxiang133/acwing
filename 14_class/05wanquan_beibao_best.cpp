//
// Created by sun on 2022/4/8.
//
#include<iostream>
#include<algorithm>
using namespace std;
const int N=110;
int f[N];
int v[N],w[N];
int n,m;

int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=v[i];j<=m;j++){
            f[j]=max(f[j],f[j-v[i]]+w[i]);  //这个循环完得到的是j<m的限制，当循环结束的时候i对应的就是n的时候
        }
    }

    cout<<f[m]<<endl;

    return 0;
}
