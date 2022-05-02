//
// Created by sun on 2022/3/16.
//

#include<iostream>

using namespace std;

const int N=100010;

int n;
int skt[N],tt;


int main(){
    cin>>n;
    for(int i=0;i<=n;i++){
        int x;
        cin>>x;
        while(tt&&skt[tt]>=x){   //别忘判断栈是否为空
            tt--;
        }
        if(tt) cout<<skt[tt]<<' ';
        else cout<<-1<<' ';
        skt[++tt]=x;    //如果符合条件，把数存入栈
    }
    return 0;
}

/*
5
3 4 2 7 5

-1 3 -1 2 2
 */
