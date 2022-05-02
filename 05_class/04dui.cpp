//
// Created by sun on 2022/3/19.
//

#include <iostream>
#include<algorithm>

const int N=100010;
int n,m;

using namespace std;
int h[N],size;

void down(int u){
    int t=u;   //t的作用是记录最大的数的下标
    if(u*2<=size && h[t]>h[2*u]) t=2*u;  //在这里赋值t之后的比较能比较出来三个数里面最小的一个放在上面
    if(u*2+1<=size && h[t]>h[2*u+1]) t=2*u+1;
    if(u!=t){
        swap(h[u],h[t]);
        down(t);//这步是为了让这个下去的数到达最终的位置
    }
}

void up(int u){
    while(u/2 && h[u/2]>h[u]){  //不用和兄弟比，只用和父亲比
        //u/2是为了保证这个数存在父亲节点
        swap(h[u/2],h[u]);  //交换
        u/=2;   //除2,进行接下来的判断
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&h[i]);
    }
    size=n;
    for(int i=n/2;i>0;i--){
        down(i);
    }

    while(m--){
        printf("%d",h[1]);
        h[1]=h[size];
        size--;
        down(1);
    }
    return 0;
}



/*
5 3
4 5 1 3 2
 */
