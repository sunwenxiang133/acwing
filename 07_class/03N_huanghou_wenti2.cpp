//
// Created by sun on 2022/4/2.
//
#include<iostream>
using namespace std;
const int N=20;
bool row[N],col[N],dg[N],edg[N];
int n;
char g[N][N];

void dfs(int x, int y,int s){    //s 是记录当前有多少个皇后的
    if(y==n) y=0,x++;  //到了每一行的末尾，接着进入到下一行
    if(x==n){
        if(s==n){
            for(int i=0;i<n;i++) puts(g[i]);
            puts("");
        }
        return;
    }
    //不放皇后
    dfs(x,y+1,s);
    //放皇后
    if(!row[x] && !col[y] && !dg[x + y] && !edg[n + x - y]){
        g[x][y]='Q';
        row[x]=col[y]=dg[x + y]=edg[n+x-y]=true;
        dfs(x, y + 1,s+1);
        row[x]=col[y]=dg[x + y]=edg[n+x-y]=false;
        g[x][y]='.';
    }
}


int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            g[i][j]='.';
        }
    }

    dfs(0,0,0);
    return 0;
}
