//
// Created by sun on 2022/3/30.
//
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1e5+10;
struct Range{
    int l,r;
    bool operator < (const Range &W) const{
        return l<W.l;
    }
}range[N];

int main() {
    int st,ed;
    scanf("%d%d",&st,&ed);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int l,r;
        scanf("%d%d", &l, &r);
        range[i]={l,r};
    }

    sort(range,range+n);

    int res=0;
    bool success=false;
    for(int i=0;i<n;i++){
        int j=i,r=-2e9;
        while(j<n && range[j].l<=st){   //双指针算法
            r=max(r,range[j].r);
            j++;
        }
        if(r<st){
            res=-1;  //双指针算法的作用在这里，如果r<st说明之后的j都不能满足要求，i就没必要增加成j的大小了，
            //j相当与探路的
            break;
        }
        res++;
        if(r>=ed){
            success=true;
            break;
        }
        st=r;
        i=j-1;  //i=j-1 ,然后执行的是for循环，i++,i就等于j了，然后从下面一个位置开始看大小
    }
    if(!success) res=-1;
    printf("%d\n",res);
    return 0;
}


/*
1 5
3
-1 3
2 4
3 5

2
 */
