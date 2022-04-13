//
// Created by sjhuang on 2022/4/13.
//

#include <vector>
#include <iostream>
using namespace std;

int main(){
    // 第一行输入一个由字母和数字以及空格组成的字符串，第二行输入一个字符。
    string str;
    getline(cin, str);
    char c;
    cin  >> c;
    int count = 0;
    for(char s: str){
        if(tolower(c) == tolower(s)) count ++;
    }
    cout << count << endl;
    return 0;
}