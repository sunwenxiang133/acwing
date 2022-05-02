//
// Created by sun on 2022/4/2.
//
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int m,n;
const int N=1e5+10,M=N*2;
typedef pair<int,int> PII;
int h[N],e[N],ne[N],idx;   //邻接表，基本上所有的邻接表都会有这个条件
int d[N],q[N];  //d是距离，q是队列

void insert(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

int bfs(){
    int hh=0,tt=0;
    q[0]=1;   //队列的第一个点是1
    memset(d,-1,sizeof d);  //初始化所有的距离
    d[1]=0;   //1这个点的距离是1
    //现在这个时候q队列还是只有一个1的队列，下面就是通过遍历，把存在链表里面的点
    //放到队列里面去，直到不能放到为止
    while(hh<=tt){   //遍历队列，直到不能放到为止
        int t=q[hh++];  //读存在队列里面的每一个点
        for(int i=h[t];i!=-1;i=ne[i]){  //读邻接表
            int j=e[i];  //j是读数组里面和t相接的点
            if(d[j]==-1){   //通过距离判断这个点有没有被访问到
                d[j]=d[t]+1;  //没有被访问到，距离设置成上一个点的距离+1
                q[++t]=j;   //这个点没有被访问到，就把这个点扔到队列里面去
            }
        }
    }
    return d[n];
}

int main() {
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof e);//把所有的表头设置为-1
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        insert(a,b);
    }

    cout<<bfs()<<endl;
    return 0;
}


/*
4 5
1 2
2 3
3 4
1 3
1 4

 1
 */
