//
// Created by sun on 2022/3/11.
//

/*
 * 确定分界点
 * 递归排序左边和右边
 * 归并，和二为一 关键点在于如何合并  这个其实是拆成最碎的然后合并，拆递归到最
 * 后就是单独的数，然后合并成一个东西
 */

#include<iostream>
using namespace std;
const int N=1e6+10;
int n;
int h[N],tmp[N];

void merge_sort(int q[],int l,int r){
    if(l>=r) return;
    int mid=l+r>>1;
    merge_sort(q,l,mid),merge_sort(q,mid+1,r);
    int k=0,i=l,j=mid+1;  //这里的i是等于l不是等于i
    while(i<=mid&&j<=r){   //先对左右俩边进行比较，当都小于对于的大小的时候,这个肯定有等于号，要不这个数组都读不完了
        if(q[i]<=q[j]) tmp[k++]=q[i++];
        else tmp[k++]=q[j++];
    }
    while(i<=mid) tmp[k++]=q[i++];  //当只剩下一边的时候
    while(j<=r) tmp[k++]=q[j++];

    //这一步复制过去的操作非常重要，因为之后的递归计算计算的还是原来的数组，而不是临时的数组，所以只对临时的数组进行修改是不对的
    for(i=l,j=0;i<=r;i++,j++){  //把tmp里面的数复制到q里面去   这个是i等于l不是i等于1，别写顺手了
        q[i]=tmp[j];
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&h[i]);
    }
    merge_sort(h, 0, n - 1);
    for(int i=0;i<n;i++){
        printf("%d   ", h[i]);
    }
    return 0;
}
