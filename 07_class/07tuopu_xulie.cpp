//
// Created by sun on 2022/4/3.
//
#include<iostream>
#include<cstring>
using namespace std;
int n,m;
const int N=1e5+10;
int e[N],ne[N],h[N],idx=0;
int d[N],q[N];

void insert(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

bool topsort(){
    int hh=0,tt=-1;
    for (int i = 1; i <= n; ++i){  //把入度为0的先扔进去
        if(d[i]==0){
            q[++tt]=i;
        }
    }
    while(hh<=tt){
        int t=q[hh++];
        for(int i=h[t];i!=-1;i=ne[i]){  //挨个读队列里面的数进行扩展和相关操作（入度-1）
            int j=e[i];
            d[j]--;  //这个数是因为和在队列里面的数相连才访问到的，而那个数已经进队列里面了，所以减1
            if(d[j]==0)
                q[++tt]=j;
        }
    }
    return tt==n-1;
}

int main() {
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin>>a>>b;
        insert(a,b);
        d[b]++;
    }
    if(topsort()){
        for (int i = 0; i < n; ++i) {
            cout<<q[i]<<" ";
        }
    }else{
        cout<<-1;
    }
    return 0;
}

/*
3 3
1 2
2 3
1 3


 1 2 3
 */
