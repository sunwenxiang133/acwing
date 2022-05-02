//
// Created by sun on 2022/3/19.
//

#include<iostream>
using namespace std;
const int N=100010;
int h[N];
int n,m;

int find(int x){   //找到父集，路定压缩
    if(h[x] != x){
        h[x]= find(h[x]);  //让这条路径上面的p[n]都指向最终的p[n]所指向的节点
    }
    return h[x];
}



int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        h[i]=i;
    }
    while(m--){
        char op[2];  //为啥op[2]因为有时候题目会有一些回车，下面的scanf用s来读会吧回车，空格乱七八糟的东西默认去掉，省事
        int a,b;
        scanf("%s%d%d",&op,&a,&b);
        if(op[0]=='M'){
            h[find(a)] = find(b);
        }else{
            if(h[find(a)] == h[find(b)]){
                puts("yes");
            }else{
                puts("no");
            }
        }
    }
    return 0;
}




/*4 5
M 1 2
M 3 4
Q 1 2
Q 1 3
Q 3 4*/

/*
yes
no
yes*/
