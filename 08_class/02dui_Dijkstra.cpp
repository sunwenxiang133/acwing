//
// Created by sun on 2022/4/3.
//
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int m,n;
const int N=510;
int dist[N];
int g[N][N];
bool st[N];


int Dijsktra(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=1;j<=n;j++){
            if( !st[j] && (t==-1 || dist[t]>dist[j])){
                t=j;
            }
        }
        st[t]=true;
        for(int j=1;j<=n;j++){
            dist[j]= min(dist[j],dist[t]+g[t][j]);
        }
    }
    if(dist[n]==0x3f3f3f3f){
        return -1;
    }
    return dist[n];
}

int main(){
    cin>>m>>n;
    memset(g,0x3f,sizeof g);
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]= min(g[a][b],c);
    }
    int t=Dijsktra();
    cout<<t;
    return 0;
}