//
// Created by sun on 2022/4/2.
//
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
const int N=1e5+10,M=N*2;
int h[N],e[M],ne[M],idx;  //用数组模拟单链表
bool st[N];  //判断这个点有没有被访问过

int ans=N;

void add(int a, int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}


int dfs(int u)  //代表搜索到了第x个点
{
    st[u]=true;

    int sum=1;  //自己这个点连通块的个数（自己这个点的存在所以先置设成1了）
    int res=0;  //每一个连通块的大小最大值
    for(int i=h[u];i!=-1;i=ne[i]){  //这是数组型链表的遍历过程
        int j=e[i];
        if(!st[j]) {
            int s=dfs(j);  //用s来表示当前子树的大小（因为深搜就是在遍历他的子节点）
            res= max(res,s); //由上面返回到的子树的节点个数留下来一个最大的（这求的是子树里面最大的连通块）
            sum+=s;  //这个是求的是现在这个点所在连通块的点的个数（由各个子树相加）
        }
    }
    res=max(res,n-sum); //去掉这个点和这个点的子树剩下的点也是一个联通的，找这俩个的大小
    ans= min(ans,res);  //res就是这个点的最大连通块的大小，ans存的就是每次遍历出来的最大连通块的最小值
    return sum;
}

int main() {
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        add(a, b), add(b, a);
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}


/*
9
1 2
1 7
1 4
2 8
2 5
4 3
3 9
4 6

 4
 */
