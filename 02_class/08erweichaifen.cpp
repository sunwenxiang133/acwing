//
// Created by sun on 2022/3/14.
//

#include <iostream>
using namespace std;
int n,m,h;
const int N=1010;
int h[N][N],tmp[N][N];

void insert(int x1,int y1,int x2,int y2,int c){
    tmp[x1][y1]+=c;
    tmp[x2 + 1][y1]-=c;
    tmp[x1][y2 + 1]-=c;
    tmp[x2 + 1][y2 + 1]+=c;
}

int main(){
    scanf("%d%d%d",&n,&m,&h);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <=m; ++j) {
            scanf("%d",&h[i][j]);
        }
    }
    for (int i = 1; i <=n ; ++i) {
        for (int j =  1; j <=m; ++j) {
            insert(i, j, i, j, h[i][j]);
        }
    }
    while(h--){
        int x1,y1,x2,y2,c;
        cin>>x1>>y1>>x2>>y2>>c;
        insert(x1,y1,x2,y2,c);
    }
    for (int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            tmp[i][j]+= tmp[i - 1][j] + tmp[i][j - 1] - tmp[i - 1][j - 1];
        }
    }
    for (int i =1; i <=n; ++i) {
        for (int j=1;j<=m;++j){
            printf("%d ", tmp[i][j]);
            puts("");  //输出自动换行的字符串
            //和 printf("%s\n","") 是等价的(puts 更快)
        }
    }
    return 0;
}



/*
3 4 3
1 2 2 1
3 2 2 1
1 1 1 1
1 1 2 2 1
1 3 2 3 2
3 1 3 4 1
 */

/*
2 3 4 1
4 3 4 1
2 2 2 2
 */
