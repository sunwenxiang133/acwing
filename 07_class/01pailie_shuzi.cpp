//
// Created by sun on 2022/3/24.
//

#include<iostream>

using namespace std;
const int N=10;
int path[N];
bool st[N];
int n;

void dfs(int u){
    if(u == n){
        for (int i = 0; i < u; ++i) {
            printf("%d ",path[i]);
        }
        puts(" ");
        return;
    }
    for(int i=1; i <= n; i++){
        if(!st[i]){
            st[i]=true;
            path[u]=i;
            dfs(u + 1);   //在这里是DFS的递归,这一层搜完了，该搜索下面一层了
            st[i]=false;  //如果执行到这里说明从上面一行语句的递归里面出来了，
            // 该马上恢复现场了
        }
    }
}

int main(){
    cin>>n;
    dfs(0);
    return 0;
}


/*
3

123
132
213
231
312
321
 */
