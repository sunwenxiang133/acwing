//
// Created by sun on 2022/3/14.
//

#include<iostream>
using namespace std;
const int N=100010;
int h[N],tmp[N];
int n,m;

void insert(int l,int r,int c){
    tmp[l]+=c;
    tmp[r + 1]-=c;
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&h[i]);
    }
    for(int i=1;i<=n;++i){
        insert(i, i, h[i]);
    }
    while(m--){
        int l,r,c;
        scanf("%d%d%d",&l,&r,&c);
        insert(l,r,c);
    }
    for(int i=1;i<=n;++i){  //把a从差分变成前缀和
        tmp[i]+=tmp[i - 1];
    }
    for(int i=1;i<=n;++i){
        printf("%d", tmp[i]);
    }

    return 0;
}

/*
6 3
1 2 2 1 2 1
1 3 1
3 5 1
1 6 1
*/
//345342
