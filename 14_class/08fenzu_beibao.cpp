//
// Created by sun on 22-5-2.
//
#include<iostream>
#include<algorithm>
using namespace std;

const int N=110;
int n,m;
int v[N][N],w[N][N],s[N];  //v是对应组对应序号的体积，w是对应组对应序号的价值
int f[N];

int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        for(int j=0;j<s[i];j++){
            cin>>v[i][j]>>w[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            for(int k=0;k<s[i];k++){
                f[j]=max(f[j],f[j-v[i][k]]+w[i][k]);
            }
        }
    }
    cout<<f[m]<<endl;
    return 0;
}

/*3 5
2
1 2
2 4
1
3 4
1
4 5*/
