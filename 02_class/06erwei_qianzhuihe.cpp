//
// Created by sun on 2022/3/14.
//

#include<iostream>
#include<string>

using namespace std;

int n,m,h;
const int N=1010;
int h[N][N],s[N][N];

int main(){

    scanf("%d%d%d",&n,&m,&h);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d",&h[i][j]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            s[i][j]= s[i][j-1] + s[i-1][j] - s[i-1][j-1] + h[i][j]; //求前缀和
        }
    }

    while(h--){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%d\n",s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1]);

        //算部分和
    }
    return 0;
}

/*
3 4 3
1 7 2 4
3 6 2 8
2 1 2 3
1 1 2 2

2 1 3 4

1 3 3 4

 输出 17 27 21
*/
