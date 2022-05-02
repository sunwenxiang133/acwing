//
// Created by sun on 2022/3/23.
//

#include<iostream>
#include<cstring>
const int N=100010,P=131;
int n,m;
using namespace std;
typedef unsigned long long ULL;
char str[N];
ULL h[N],p[N];   //p[N]用来存对应的位数的

ULL get(int l,int r){
    return h[r]-h[l-1]*p[r-l+1];
}

int main(){
    int n,m;
    scanf("%d%d%s",&n,&m,str+1); //从str[1]的位置开始存数
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]*P;      //存的是p的对应的i位是p
        h[i]=h[i-1]*P+str[i];   //存的是字符串对应的10进制数
    }
    while(m--){
        int l1,r1,l2,r2;
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        if(get(l1,r1)== get(l2,r2)){
            puts("Yes");
        }else{
            puts("No");
        }
    }
    return 0;
}


/*
8 3
aabbaabb
1 3 5 7
1 3 6 8
1 2 1 2

Yes
No
Yes*/
