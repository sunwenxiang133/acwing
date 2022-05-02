//
// Created by sun on 2022/3/19.
//

#include<iostream>

using namespace std;
int m,n;
const int N=100010;
int h[N],size[N];

//路定压缩是这个函数的优化，但是这个函数的作用是找到这个的最终的父节点
//所以需要用父节点的时候用这个，其他的时候不用

int  find(int x){
    if(h[x] != x) h[x]=find(h[x]);
    return h[x];
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        h[i]=i;
        size[i]=1;
    }

    while(m--){
        char op[5];
        int a,b;
        scanf("%s",&op);
        if(op[0]=='C'){
            scanf("%d%d",&a,&b);
            if(find(a)== find(b)) continue;
            size[find(a)]+=size[find(b)];
            h[find(a)]=find(b);
        }else if(op[1]=='1'){
            scanf("%d%d",&a,&b);
            if( find(a)== find(b){
                puts("Yes");
            }else{
                puts("No");
            };
        }else{
            scanf("%d",&a);
            printf("%d\n",size[find(a)]);
        }
    }
    return 0;
}