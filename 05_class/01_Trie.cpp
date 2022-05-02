//
// Created by sun on 2022/3/18.
//

#include<iostream>
using namespace std;

const int N=100010;
//son代表的是一个一个的字母，son
int son[N][26],cnt[N],idx;
char str[N];


void insert(char str[]){
    int p=0;  //每次的时候都是从0开始
    for(int i=0;str[i];i++)   //因为字符串最后一位是\0可以用来判断是否结束
    {
        int u=str[i]-'a';
        //相当与每个数都有单独的index,用来标记是否有这个数
        if(!son[p][u]) son[p][u]=++idx;
        p=son[p][u];
    }
    cnt[p]++;
}

int query(char str[]){
    int p=0;
    for(int i=0;str[i];i++){
        int u=str[i]-'a';
        if(!son[p][u]) return 0;
        p=son[p][u];
    }
    return cnt[p];
}

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        char op[2];
        scanf("%s%s",op,str);
        if(op[0]=='I'){
            insert(str);
        }else if(op[0]=='Q'){
            printf("%d\n", query(str));
        }
    }
    return 0;
}


/*
 * 5
I abc
Q abc
Q ab
I ab
Q ab
 */


/*
1
0
1
*/
