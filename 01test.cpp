#include<iostream>
#include <cstring>

using namespace std;
int n;
const int N=1e5;
int a[N],f[N];

int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>a[i];
    }
//    memset(f,1,sizeof f);
    for(int i=0;i<n;i++){
        f[i]=1;
    }
    for(int i=n-1;i>0;i--){
        for(int j=i;j<n;j++){
            if(a[i]<a[i+1]){
                f[i]= max(f[j]+1,f[i]);
            }
        }
    }
    for(int i=1;i<n;i++){
        cout<<f[i]<<" ";
    }
    return 0;
}