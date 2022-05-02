//
// Created by sun on 2022/4/8.
//
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1010;
int f[N];
int v[N],w[N];
int n,m;

int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=v[i];j--)
            f[j]=max(f[j],f[j-v[i]]+w[i]);
    }
    cout<<f[m]<<endl;
    return 0;
}

//f[i][j]=f[i-1][j]; 就是 f[j]=f[j]可以直接删掉
//if(j>=v[i]) //可以让j直接从v[i]开始做
//f[i][j]= max(f[i][j],f[i-1][j-v[i]]+w[i]);  这里因为i-1小于i,而在这个式子里面小的数会先被计算，变成f[i][j-v[i]]+w[i],所以循环的顺序变成从大到小就能解决了
//这样f[j-v[i]]还没有被更新过，存的就是第i-1层的v[i]
//随着i的变化每一轮都会更新一遍所有的数

/*
4 5
1 2
2 4
3 4
4 5

8
*/