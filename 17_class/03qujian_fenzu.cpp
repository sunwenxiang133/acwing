//
// Created by sun on 2022/3/29.
//
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int N=1e6+10;
int n;

struct Range{
    int l,r;
    bool operator < (Range &W) const{
        return l<W.l;
    }
}range[N];

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        range[i]={l,r};
    }
    sort(range,range+n);  //排好序，按照左端点的顺序排序
    priority_queue<int,vector<int>,greater<int>> heap;
    for(int i=0;i<n;i++){
        auto r=range[i];
        if(heap.empty() || heap.top()>=r.l) heap.push(r.r);  //如果是空的，或者最小的都收不进去，只能再加一个
        else{
            heap.pop();   //把现在最小的合适的那个踢出去
            heap.push(r.r);  //把新加入的尾巴放进去 （这时候优先队列会进行相应排序了）
            //优先队列里面存的是每个组的最小值，也就代表着每一个组
        }
    }
    printf("%d\n",heap.size());
    return 0;
}



/*
3
-1 1
2 4
3 5

2*/
