//
// Created by sjhuang on 2022/4/14.
//

#include <iostream>
using  namespace  std;

void printChar(const char *str, int m){
    for(int i = 0; i < m; i++){
        cout << str[i];
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    int m = 4*n;
    char str[m];
    for(int i = n; i < 3*n ;i ++){
        str[i] = '.';
    }
    for(int i =0 ;i < n; i++){
        str[i] = '*';
    }

    for(int i = 3*n; i < 4*n; i++){
        str[i] = '*';
    }

    // 最后 n行
    for(int i = 0; i < 3*n; i++){
        printChar(str, m);
    }
    for(int i = 0; i < n; i++){
        str[i] = str[4*n-1-i] = '.';
        str[n + i] = str[4*n-1-n-i] = '*';
        printChar(str, m);
    }

    return 0;
}