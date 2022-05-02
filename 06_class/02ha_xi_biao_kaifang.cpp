//
// Created by sun on 2022/3/22.
//
#include<iostream>
#include<cstring>

using namespace std;
const int N=200003,null=0x3f3f3f;
int h[N];

int find(int x){    //这个是和拉链法不一样的地方，如果找得到返回的是下标，如果找不到返回的是第一个空的位置的下标
    int k= (x % N + N) % N;
    while(h[k] != null && h[k] != x){
        k++;
//        if(k>=sizeof h){
//            k=0;
//        }

        if(k == N){ //size of a本身就是N
            k=0;
        }
    }
    return k;
}


int main(){
    int n;
    scanf("%d",&n);
    memset(h, 0x3f, sizeof h);
    while(n--){
        char op[2];
        int x;
        scanf("%s%d",op,&x);
        int k= find(x);
        if(*op=='I'){
            h[k]=x;
        }else{
            if(h[k] != null) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}