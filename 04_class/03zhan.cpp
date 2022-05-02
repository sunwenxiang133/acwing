//
// Created by sun on 2022/3/16.
//

#include<iostream>

using namespace std;
const int N=100010;
int skt[N],tt;

//插入
void push(int x){
    skt[++tt]=x;
}

//弹出
void pop( ){
    tt--;
}

//判断栈是否为空
bool notNull(){
    if(tt>0) return true;  //如果tt>0是不空的
    else return false;
}

//取出栈顶
int top_seq(){
    skt[tt];
}

int main(){
    return 0;
}