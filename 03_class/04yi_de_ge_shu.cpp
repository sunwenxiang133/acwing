//
// Created by sun on 2022/3/15.
//

#include<iostream>

using namespace std;

int lowbit(int x){
    return x&-x;
}

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int x;
        cin>>x;
        int res=0;
        while(x){
            x-= lowbit(x);    //lowbit返回的是第一个1和后面的一串0
            res++;
        }
        cout<<res<<endl;
    }
}

/*
5
1 2 3 4 5
 */

/*
1 1 2 1 2
 */
