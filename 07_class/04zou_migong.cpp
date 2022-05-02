//
// Created by sun on 2022/4/2.
//
#include<iostream>
#include <cstring>

using namespace std;
int m,n;
const int N=20;
int g[N][N],d[N][N];  //g数组存的是图，d数组存的是每一个点到起点的距离
typedef pair<int,int> PII;
PII q[N*N],Prev[N][N];

int bfs(){
    int hh=0,tt=0;
    q[0]={0,0};
    memset(d,-1,sizeof d);
    d[0][0]=0;
    int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
    while(hh<=tt){   //这就是在这个队列依次读完一遍
        auto t=q[hh++];
        for(int i=0;i<4;i++){    //遍历四个方向
            int x=t.first+dx[i],y=t.second+dy[i];
            if(x>=0&& y>=0&&y<m&&g[x][y]==0&&d[x][y]==-1){
                q[++tt]={x,y};  //如果有能拓展的点放进去
                Prev[x][y]=t;   //记录之前过来的点
                d[x][y]=d[t.first][t.second]+1;   //距离在上一个的基础上加一
            }
        }
    }

    //执行到这里就能确定最短路径是什么了，下面的是按照Prev结构体依次往上面找上去
    int x=n-1,y=m-1;
    while(x||y){   //输出路径是倒着的
        cout<<x<<' '<<y<<endl;
        auto t=Prev[x][y];
        x=t.first,y=t.second;
    }
    return d[n-1][m-1];
}


int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&g[i][j]);
        }
    }

    cout<<bfs()<<endl;
    return 0;
}


/*
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0

8
 */
