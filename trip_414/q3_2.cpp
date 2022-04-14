//
// Created by sjhuang on 2022/4/14.
//

#include <vector>
#include <iostream>
#include <algorithm>

using  namespace  std;

int op(string &str, int n){
    int ans = 0;
    int l = 0, r = 0;
    char cur = str[0];
    while (r < n){
        int j = r;
        while( j < n && str[j] == cur){
            j ++;
        }
        r = j;
        if(r == n) break;
        // 修改结果
        // 1010
        if(r < n && r != l + 1){
            ans += r - l - 1;
            str[l+1] = str[r];
            str[r] = cur;
            l = l + 2;
        }else if(r < n && r == l + 1){
            cur = str[r];
            l = r;
        }else {
            break;
        }
    }
    return ans;
}


int main(){
    string str;
    cin >> str;
    int n = str.size();
    int ans = 0;
    ans += op(str,n);
    reverse(str.begin(), str.end());
    ans += op(str,n);
//    cout << str << endl;
    cout << ans << endl;

    return 0;
}