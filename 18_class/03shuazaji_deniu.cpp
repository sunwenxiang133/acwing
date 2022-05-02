//
// Created by sun on 2022/3/31.
//
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1e5+10;
typedef pair<int,int> PII;
PII cow[N];

int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int w,s;
        scanf("%d%d",&w,&s);
        cow[i]={w+s,w};
    }
    sort(cow,cow+n);
    int res=-2e9,sum=0;
    for(int i=0;i<n;i++){
        int w=cow[i].second;
        int s=cow[i].first-w;
        res=max(res,sum-s);
        sum+=w;
    }
    printf("%d",res);

    return 0;
}

/*3
10 3
2 5
3 3

 2
 */
