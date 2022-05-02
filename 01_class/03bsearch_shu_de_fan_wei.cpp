//
// Created by sun on 2022/3/12.
//

/*给定一个按照升序排列的长度为n的整数数组，以及q个查询
 * 对于每个查询返回一个元素k的起始位置和终止位置
 * 如果数组中不存在元素，返回-1,-1
 * （人话：找q这个数的起始坐标和终止坐标）*/

/*6 3
 * 1 2 2 3 3 4
 *
 * 3
 * 3 4
 * 3
 * 3 4
 * 5
 * -1 -1
 * */

#include<iostream>
using namespace std;

int m,n;
const int N=100010;
int h[N];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&h[i]);
    }
    while(m--){   //因为有m个询问，对每个询问分别去做
        int x;
        scanf("%d",&x);

        int l=0,r=n-1;
        while(l<r){
            int mid=l+r>>1;

            //要找到的不是满足条件的最右边的点（第一个在范围内的点），而是找满足条件的区间内最左边的一个点
            if(h[mid] >= x) r=mid;  //由这个来参照模板去写，关键在于想找的这个数是什么
            //这里找的是第一个大于等于x的数（即数的起点）
            else l=mid+1;
        }
        if(h[l] != x) cout << "-1" << "-1"; //如果这个数不存在，返回的是第一个大于x的数
        else{
            cout<<l<<"  "; //这里输出l和输出r是一样的，因为此步运行出来的结果是相等的
            //当找完左边开始找右边了
            int l=0,r=n-1;
            while(l<r){
                int mid=l+r+1>>1;
                if(h[mid] <= x) l=mid;
                else r=mid-1;
            }
//            if(h[r]!=n) cout<<"-1"<<"-1";
            cout<<l<<endl;
        }
    }
    return 0;
}