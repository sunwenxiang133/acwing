//
// Created by sun on 2022/3/14.
//

//前缀和
//设立一个a[0]=0，因为加入求1到10的数用a[10]-h[0]即可，为了保证一致性
//从1开始设立数组

#include<iostream>

using namespace std;

const int N=100010;

int n,m;
int h[N],s[N];

int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <=n; ++i) {  //读取数从1开始
        scanf("%d",&h[i]);
    }
    for(int i=1;i<=n;++i){
        s[i]= s[i-1] + h[i];
    }

    while(m--){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",s[r]-s[l-1]);
    }
    return 0;
}