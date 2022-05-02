//
// Created by sun on 2022/4/8.
//
#include<iostream>
using namespace std;
const int N=110;
int f[N];
int v[N],w[N],s[N];
int n,m;

int main() {
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n;i++){
        int a,b,s;
        cin>>a>>b>>s;
        int k=1;
        while(k<=s){   //这个是对确定的a和确定的b进行的操作，现在不确定的是取几个k,然后用二进制能够表示左右的数的方法把二进制表示出来
            cnt++;
            v[cnt]=a*k;
            w[cnt]=b*k;
            s-=k;
            k*=2;
        }
        if(s>0){
            cnt++;
            v[cnt]=a*s;
            w[cnt]=b*s;
        }
    }
    n=cnt;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=v[i];j--){
            f[j]= max(f[j],f[j-v[i]]+w[i]);
        }
    }
    cout<<f[m]<<endl;
    return 0;
}

/*4 5
1 2 3
2 4 1
3 4 3
4 5 2

 10*/