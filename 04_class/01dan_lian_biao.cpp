//
// Created by sun on 2022/3/16.
//

#include<iostream>
using namespace std;

const int N=100010;
//head 表示头接点的下标
//e表示节点i的值
//ne 表示节点i的next指针是多少
//idx 存储当前已经用到了哪个点
int head,e[N],ne[N],idx;

//初始化
void init(){
    head=-1;
    idx=0;
}

//将x插到头节点
void add_to_head(int x){
    e[idx]=x;
    ne[idx]=head;
    head=idx;
    idx++;   //当执行完所有的操作之后,idx自增用来下一步操作
}

void add(int k,int x) {   //把x插入到k后面
    e[idx]=x;
    ne[idx]=ne[k];
    ne[k]=idx;   //ne存的是位置，别晕了
    idx++;
}

//将下标是k的点后面的点删掉
void remove(int k){
    ne[k]=ne[ne[k]];
}

int main(){
    int m;
    cin>>m;

    init();

    while(m--){
        int k,x;
        char op;
        cin>>op;
        if(op=='H'){
            cin>>x;
            add_to_head(x);
        }else if(op=='D'){
            cin>>k;
            remove(k-1);
        }else{
            cin>>k>>x;
            add(k-1,x);
        }
    }
    for(int i=head;i!=-1;i=ne[i]) cout<<e[i]<<' ';
    cout<<endl;
    return 0;
}



/*
10
H 9
I 1 1
D 1
D 0
H 6
I 3 6
I 4 5
I 3 4
D 6
 */


/*
6 4 6 5
 */
