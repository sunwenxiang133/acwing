//
// Created by sun on 2022/3/22.
//

#include<iostream>
#include <cstring>
using namespace std;
const int N=100010;
int h[N],n[N],ne[N],idx;
void insert(int x){
    int k=(x%N+N)%N;
    n[idx]=x;
    ne[idx]=h[k];
    h[k]=idx++;
}
bool find(int x){
    int k=(x%N+N)%N;
    for (int i = h[k]; i!=-1 ; i=ne[i]) {
        if (n[i]==x)
            return true;
    }
    return false;
}
int main() {
    int n;
    scanf("%d",&n);
    memset(h,-1,sizeof h);
    //作用：memset() 的作用是在一段内存块中填充某个给定的值
    while(n--){
        char op[2];
        int x;
        scanf("%s%d",op,&x);
        if(*op=='I'){
            insert(x);
        }else if(*op=='Q'){
            if(find(x)){
                puts("Yes");
            }else{
                puts("No");
            }
        }
    }
    return 0;
}


/*5
I 1
I 2
I 3
Q 2
Q 5*/