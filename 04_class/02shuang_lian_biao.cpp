//
// Created by sun on 2022/3/16.
//

#include<iostream>

using namespace std;

const int N=100010;

int m;
//e存数据，l左指针，r右指针，idx当前的操作数
int e[N],l[N],r[N],idx;

void init(){
    r[0]=1,l[1]=0;
    idx=2;
}

//在第k的位置后面插入一个数x
void add(int k,int x){   //先把新加进来的那个数的指向设置正确(先设置不会产生改变的数据)
    e[idx]=x;
    l[idx]=k;
    r[idx]=r[k];
    l[r[k]]=idx;
    r[k]=idx;
    idx++;
}

//如果想在k的左边插入x   这样调用add(l[k],n) 即可

void remove(int k){
    r[l[k]]=r[k];
    l[r[k]]=l[k];
}


int main(){

    return 0;
}