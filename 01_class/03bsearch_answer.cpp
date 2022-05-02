//
// Created by sun on 2022/3/12.
//

//区间l,r被划分成[l,mid],[mid+1,r]时使用
int bsearch_1(int l,int r){
    while(l<r){ //二分的时候确定答案在区间内，当这个区间左右相等的时候，这个数一定在这个区间上
        int mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    return l;
}
//区间l,r被划分成[l,mid-1][mid,r]时使用
int bsearch_2(int l,int r){
   while(l<r){
       int mid=l+r+1>>1;  //这里如果不补上+1,l=mid如果左右都是l就死循环了
       if(check(mid)) l=mid;
       else r=mid-1;
   }
   return l;
}

//什么时候使用这俩个板子，看更新区间是l=mid还是r=mid