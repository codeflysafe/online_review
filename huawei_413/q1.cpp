//
// Created by sjhuang on 2022/4/13.
//


#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    getline(cin, str);
    int i = 0, n = str.size();
//    cout << str << endl;
    int cur = 0;
    while(i < n){
        if(str[i] != ' '){
            cur ++;
        }else{
            cur = 0;
        }
        i++;
    }

    cout << cur << endl;
    return 0;
}
