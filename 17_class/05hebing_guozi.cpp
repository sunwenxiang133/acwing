//
// Created by sun on 2022/3/31.
//
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    priority_queue<int,vector<int>,greater<int>> heap;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        heap.push(x);
    }
    int res=0;
    while(heap.size()>1){
        int a=heap.top();heap.pop();
        int b=heap.top();heap.pop();
        res+=a+b;
        heap.push(a+b);
    }
    printf("%d\n",res);
    return 0;
}

/*
3
1 2 9
15
 */
