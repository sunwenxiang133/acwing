//
// Created by sun on 2022/3/31.
//

#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int t[N];
int n;

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t[i]);
    }
    sort(t,t+n);
    int sum=0;
    for(int i=0;i<n;i++){
        sum+= abs(t[i]-t[n/2]);
    }
    cout<<sum;
    return 0;
}


/*
 *4
 * 6 2 9 1
 *
 * 12
 */
