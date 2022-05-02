//
// Created by sun on 2022/3/16.
//

#include<iostream>
using namespace std;

const int N=100010;
int h[N],hh,tt=-1;

//插入
void en_Queue(int x){
    h[++tt]=x;
}

//弹出
void del_Queue(){
    tt++;
}
//判断是否为空
bool isNUll(){
    return hh<=tt;
}


int main(){
    return 0;
}