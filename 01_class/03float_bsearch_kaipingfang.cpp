//
// Created by sun on 2022/3/12.
//

//求一个数开方之后的结果

#include <iostream>
using namespace std;

int main(){
    double x;
    cin>>x;

    double l=0,r=x;
    while(r-l>1e-6){ //如果题目让保存的是4位小数，精度就提高2位变成6
        //浮点数判断精度还有一种写法，循环100次，for(int i=0;i<100;i++) 一定能算出来结果
        double mid=(l+r)/2;
        if(mid*mid>=x) r=mid;
        else l=mid;
    }
    printf("%.4lf",l); //这里输出l和输出r都是可以的
}