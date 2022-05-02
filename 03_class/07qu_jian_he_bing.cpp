//
// Created by sun on 2022/3/15.
//

#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int,int> PII;
const int N=100010;
vector<PII> segs;
int n;

void merge(vector<PII> &segs){
    vector<PII> res;     //建立一个新数组用来存放合并后的区间
    sort(segs.begin(),segs.end());  //这个会优先以左端点排序，然后以右端点排序
    int st=-2e9,ed=-2e9;
    for(auto seg: segs){
        if(ed<seg.first){         //当尾巴比下一个的开头小的时候，上一个区间差不多合并完成
            if(st!=-2e9) res.push_back({st,ed});   //不是第一个数的时候才把区间存进去
            st=seg.first;    //更新新的st和ed
            ed=seg.second;
        }else{
            ed=max(ed,seg.second);   //有重合的部分，更新尾巴
        }
    }
    if(st!=-2e9){   //处理最后一段的情况，st!=-2e9为了防止一个数都没有
        res.push_back({st,ed});
    }
    segs=res;
}

int main(){

    cin>>n;

    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        segs.push_back({l,r});
    }
    merge(segs);
    cout<<segs.size()<<endl;

    return 0;
}


/*5
1 2
2 4
5 6
7 8
7 9
*/

/*
3*/
