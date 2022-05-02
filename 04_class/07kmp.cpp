//
// Created by sun on 2022/3/17.
//

#include<iostream>
using namespace std;

const int N=10010,M=10010;
int n,m;
char h[N],s[M];
int ne[N];  //c++里面有时候next数组会报错（有的头文件用了），所以名字为ne好点

int main(){

    cin >> n >> h + 1 >> m >> s + 1;

    //求next的过程
    for(int i=2,j=0;i<=n;i++){
        //为什么从i=2开始，因为i=1的时候就算是p[1]=h[0],也是从0开始省略了 i=1的情况
        //当j不为0,且后面的匹配不上的时候，j只能退成前面一个的next再开始匹配
        while(j && h[i] != h[j + 1]) j=ne[j];
        //如果相同的时候j自增，因为每个i在for里面都会自增，所以都增加
        if(h[i] == h[j + 1]) j++;
        //给当前的next[i]记录现在的j
        ne[i]=j;
    }

    //kmp匹配过程
    for(int i=1,j=0;i<=m;i++){
        //如果没有匹配上，就用next数组
        //为什么i比j大了1,因为比较的时候j先自增，如果相同，j就自增，如果不同，j不自增
        //切回j+1前面一个最大字符位置，也就是ne[j]
        while(j&& s[i] != h[j + 1]) j=ne[j];
        if(s[i] == h[j + 1]) j++;
        if(j==n){
            //匹配成功，输出，记录
            printf("%d ",i-m+1);
            j=ne[j];
        }
    }
    return 0;
}


/*3
aba
5
ababa
 */

/*
0 2
 */
