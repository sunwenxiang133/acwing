//
// Created by sun on 2022/4/3.
//
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
const int N=510;
int g[N][N];  //数组存图
bool st[N];   //存这个点有没有被访问过
int dist[N];  //存每个点的距离

int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;  //第一个点设置好,第一个点千万别忘了
    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=1;j<=n;j++){
            if(!st[j] && (t==-1 || dist[t]>dist[j])){  //t=-1 肯定要给t赋值，然后这句话是为了找到最小的值
                t=j;
            }
        }
        st[t]=true;  //这个点已经是最小的值确定出来了
        for(int j=1;j<=n;j++){
            dist[j]= min(dist[j],dist[t]+g[t][j]);  //用新加入的最小的点，挨个更新最短距离
        }
    }
    if(dist[n]==0x3f3f3f3f){
        return -1;
    }
    return dist[n];
}

int main() {
    cin>>n>>m;
    memset(g,0x3f,sizeof g);
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]= min(g[a][b],c); //因为可能存在多个路和自环，所以存数的时候存最短的路即可
    }
    int t=dijkstra();
    cout<<t;
    return 0;
}

/*
3 3
1 2 2
2 3 1
1 3 4
 * 3*/