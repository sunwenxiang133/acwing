//
// Created by sun on 22-5-3.
//
#include<iostream>
using namespace std;
const int N=310;
int s[N];
int n;
int f[N][N];

int main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) s[i]+=s[i-1];  //前缀和

    for(int len=2;len<=n;len++){   //每个区间的长度
        for(int i=1;i+len-1<=n;i++){   //每个区间开始的位置
            int l=i,r=i+len-1;
            f[l][r]=1e8;
            for(int k=l;k<r;k++){
                f[l][r]= min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]); //s[r]-s[l-1] 前缀和，最后一步一定是从l到r这些数的和
            }
        }
    }
    cout<<f[1][n];
    return 0;
}

/*
4
1 3 5 2

22
 */
