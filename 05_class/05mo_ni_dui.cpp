//
// Created by sun on 2022/3/19.
//

#include<iostream>
#include<algorithm>
#include<string.h>
const int N=100010;
int h[N],ph[N],hp[N],size=0;
using namespace std;

//增加的这玩意换掉swap就ok了
void heap_swap(int a,int b){
    //ph[k] 代表第k个数插入的数在堆里面的下标是什么，
    //hp[k] 堆里面的k是第几个插入的点
    swap(ph[hp[a]],ph[hp[b]]);  //这是ph,和hp自己玩自己的，和p没什么关系，只是下标的改变
    swap(hp[a],hp[b]);
    swap(h[a],h[b]);  //这交换的是数，不是下标
}

void down(int u){
    int t=u;
    if(2*u<=size && h[t] > h[2 * u]) t= 2 * u;
    if(2*u+1<=size && h[t] > h[2 * u + 1]) t= 2 * u + 1;
    if(u!=t){
        heap_swap(u, t);
        down(t);
    }
}

void up(int u){
    while(u/2 && h[u/2]>h[u]){
        heap_swap(h[u/2],h[u]);
        u/=2;
    }
}


int main(){
    int m,n;
    scanf("%d",&n);
    while(n--){
        char op[10];
        int k,x;
        scanf("%s",op);
        if(!strcmp(op,"I")){
            scanf("%d",&x);
            size++;
            m++;
            ph[m]=size,hp[size]=m;
            h[size]=x;
            up(size);
        }else if(!strcmp(op,"PM")){ printf("%d\n",h[1]);}
        else if(!strcmp(op,"DM")){
            heap_swap(1,size);
            size--;
            down(1);
        }else if(!strcmp(op,"D")){
            scanf("%d",&k);
            k=ph[k];
            heap_swap(k,size);
            size--;
            down(k), up(k);   //这俩个最终只会执行其中一个
        }else{
            scanf("%d%d",&k,&x);
            k=ph[k];
            h[k]=x;
            down(k), up(k);
        }

    }
    return 0;
}



/*
 * 10
I -10
PM
I -10
D 1
C 2 8
I 6
PM
DM
 */


/*
-10
6
*/

