//
// Created by sun on 2022/3/16.
//

#include<iostream>

using namespace std;
const int N=100010;
int n,k;
int h[N],h[N];

int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&h[i]);
    }
    int hh=0,tt=-1;  //这一步一定要有
    for(int i=0;i<n;i++){
        //判断队头是否已划出窗口
        if(hh<=tt && i-k+1 > h[hh]) hh++;
        //如果新加入的数比这个数小，那就把之前的那个数扔掉
        while(hh<=tt && h[h[tt]] >= h[i]) tt--;
        //当i读取超过k个数之后，就要每次都输出一次单调队列的最小值了

        //不管这个数是比之前的数是大是小，大了需要放进去，小了会把之前的扔了，
        // 但是这个要放进去，所以最终都会放进去
        //这个操作要放在输出前
        h[++tt]=i;

        if(i>=k-1)printf("%d   ", h[h[hh]]);
    }
    puts("");


    hh=0,tt=-1;
    for(int i=0;i<n;i++){
        //判断队头是否已划出窗口
        if(hh<=tt && i-k+1 > h[hh]) hh++;
        //如果新加入的数比这个数大，那就把之前的那个数扔掉
        while(hh<=tt && h[h[tt]] <= h[i]) tt--;

        //雷打不动
        h[++tt]=i;

        if(i>=k-1)printf("%d   ", h[h[hh]]);

    }
    puts("");
    return 0;
}

/*
8 3
1 3 -1 -3 5 3 6 7
*/

/*
-1 -3 -3 -3 3 3
3 3 5 5 6 7
 */


