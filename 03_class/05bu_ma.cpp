//
// Created by sun on 2022/3/15.
//

#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    unsigned int x=-n;
    for (int i = 31; i >=0; --i) {
        cout<<(x>>i&1);
    }
    return 0;
}

/*
10

11111111111111111111111111110110*/
