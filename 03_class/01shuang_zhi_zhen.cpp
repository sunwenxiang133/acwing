//
// Created by sun on 2022/3/15.
//

//用空格分割输入单词，把单词输出出来，每个单词占一行

#include<iostream>
#include<string.h>

using namespace std;


int main(){
    char str[1000];
    gets(str);
    int n= strlen(str);
    for (int i = 0; i<n; ++i) {   //判断条件str[i]
        int j=i;
        while(j<n && str[j]!=' '){  //j<n且j没有指向空格
            j++;
        }
        for(int k=i;k<j;k++){
            cout<<str[k];
        }
        cout<<endl;
        i=j;
    }
    return 0;
}