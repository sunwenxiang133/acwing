//
// Created by sun on 2022/3/31.
//

#include<iostream>
#include<algorithm>
using namespace std;
const int N=100010;
typedef long long LL;
int t[N];

int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t[i]);
    }
    sort(t,t+n);
    LL res=0;
    for(int i=0;i<n;i++){
        printf("%d   ",t[i]);
        printf("%d\n",res);
        res+=t[i]*(n-i-1);
    }
    printf("%lld\n",res);
    return 0;
}

/*7
3 6 1 4 2 5 7
56*/

