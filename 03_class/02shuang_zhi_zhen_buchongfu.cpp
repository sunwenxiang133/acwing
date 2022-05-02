//
// Created by sun on 2022/3/15.
//

#include<iostream>

using namespace std;

const int N=100010;
int n;
int h[N];
int s[N];  //当前j到i区间每个数出现的个数

int main(){
    cin>>n;
    for (int i=0;i<n;i++){
        scanf("%d",&h[i]);
    }
    int res=0;
    for (int i = 0,j=0; i < n; ++i) {   //外层的i在往前走，后面的j在往后面根据赶
        s[h[i]]++;   //这种记录方法就像桶排序一样
        while(s[h[i]] > 1){   //如果出现了俩个数
            s[h[j]]--;   //j就往后面扒拉，每次退掉一个数
            j++;
        }
        res= max(res,i-j+1);
    }
    cout<<res<<endl;
    return 0;
}

/*
5
1 2 2 3 5
 返回3
 */
