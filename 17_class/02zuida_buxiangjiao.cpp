//
// Created by sun on 2022/3/29.
//

#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int n;

struct Range{
    int l,r;
    bool operator < (const Range &W) const{
        return r<W.r;
    }
}range[N];


int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int m,n;
        scanf("%d%d",&m,&n);
        range[i]={m,n};
    }
    sort(range,range+n);
    int res=0,end=-2e9;
    for(int i=0;i<n;i++){
        if(end<range[i].l){
            res++;
            end=range[i].r;
        }
    }
    cout<<res;
    return 0;
}

/*
 * 3
-1 1
2 4
3 5
 */
