//
// Created by sun on 2022/3/24.
//

#include<iostream>
const int N=10;
char g[N][N];  //用来存整个棋盘
int col[2*N],dg[2*N],udg[2*N];//用来存每一竖列，对角，反对角有没有用过  //如果是N就是错误的，容易造成数组越界！
//对角线的用法是 y=x+b ，x=y-b,用dg[y-b]存的就是y-b用来记录y-b这个斜线有没有被用过
int n;

using namespace std;

void dfs(int u){    //这个dfs(u) 这个x代表的是深搜到了第几行
    if(u == n){
        for (int i = 0; i < n; ++i) {
            puts(g[i]);
        }
        puts("");
        return;
    }
    for(int i = 0; i < n; ++i) {
        if(!col[i] && !dg[u+i] && !udg[n-u+i]){
            g[u][i]='Q';
            col[i]=dg[u+i]=udg[n-u+i]=true;
            dfs(u+1);
            col[i]=dg[u+i]=udg[n-u+i]=false;
            g[u][i]='.';
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for (int j = 0; j < n; ++j){
            g[i][j]='.';
        }
    }
    dfs(0);
    return 0;
}