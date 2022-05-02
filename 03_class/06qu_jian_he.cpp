//
// Created by sun on 2022/3/15.
//

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//把所有操作读进去
typedef pair<int,int> PII;
vector<PII> add,query;   //插入操作，求和操作 存进去


const int N=300010;   //插入里面有一个数，查找里面有俩个数，他们都是10万级的
int n,m;
int h[N],s[N];  //a是存的数，s是前缀和

vector<int> alls;  //存的所有要离散化的值

int find(int x){   //求离散化对应的数组下标    用的是之前将的二分的方法求解
    int l=0,r=alls.size()-1;
    while(l<r){
        int mid=l+r>>1;
        if(alls[mid]>=x){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    return r+1;
}

vector<int>::iterator unique(vector<int> &a){   //a是有序的
    int j=0;
    for(int i=0;i<a.size();i++){    //i遍历每一个数
        if(!i||a[i]!=a[i-1]){   //如果i不是第一个或者和前面一个不重复
            a[j++]=a[i];    //h[0]到a[j-1] 所有a中不重复的数
        }
    }
    return a.begin()+j;   //返回的是排序完数组的最后一个+1
}


int main(){
    cin>>n>>m;
    for (int i = 0; i < n; ++i) {   //先把插入操作读进去
        int x,c;
        cin>>x>>c;
        add.push_back({x,c});
        alls.push_back(x);   //把下标x加入到待离散化的数组里面去
    }

    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        query.push_back({l,r});  //把插入操作读进去

        alls.push_back(l);  //左右区间读入到待离散化数组里面
        alls.push_back(r);
    }

    //去重
    sort(alls.begin(),alls.end());
    //删掉重复的元素
    alls.erase(unique(alls),alls.end());

    //处理插入
    for(auto item:add){
        int x=find(item.first);
        h[x]+=item.second;
    }

    //预处理前缀和
    for (int i = 1; i <= alls.size(); ++i) {
         s[i]= s[i-1] + h[i];
    }
    //预处理询问
    for(auto item:query){
        int l=find(item.first),r=find(item.second);
        cout<<s[r]-s[l-1]<<endl;   //l-1
    }

    return 0;
}


/*
3 3
1 2
3 6
7 5
1 3
4 6
7 8
*/

/*
8
0
5
*/
