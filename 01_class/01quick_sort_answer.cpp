//
// Created by sun on 2022/3/11.
//
#include <iostream>

using namespace std;

const int N = 1e6+10;
int h[N];
int n;

void quick_sort(int q[],int l,int r){
    if(l>=r) return;
    int x=q[l];
    int i=l-1,j=r+1;  //先往左边右边去一格，为了方便之后的do while操作
    while(i<j){
        do i++; while(q[i]<x);  //往后面移动，当到达一个数的时候停止
        do j--; while(q[j]>x);   //不能是大于等于，如果1 3 2 x x x 基准是3的时候，等于3因为不会被暂停，就不能保证左边的都是小于3的了，而是左边的都是小于等于3的了,j--不是j++每次顺手都写错了位置bro
        if(i<j) swap(q[i],q[j]); //俩个都听了，进行下一次操作，操作完进行下一次循环
    }
    quick_sort(q,l,j);  //对二分完成的俩个部分继续二分直到有序
    //如果这个是j变成i-1 ,则上面定位的数就不能是i了,例子 对 0，1 这俩个数进行排序，死循环了
    quick_sort(q,j+1,r);
}

int main(){
    scanf("%d",&n);
    for (int k = 0; k <n; ++k) {
        scanf("%d",&h[k]);
    }
    quick_sort(h, 0, n - 1);
    for (int k = 0; k < n; ++k) {
        printf("%d  ", h[k]);
    }
    return 0;
}
/*
本质是二分，就是把数组先分成俩个部分，大于一个数和小于一个数两部分
之后对每个部分进行同样的操作
*/