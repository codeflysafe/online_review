//
// Created by sjhuang on 2022/4/14.
//

#include <vector>
#include <iostream>
#include <climits>

using  namespace  std;

int main(){

    string str;
    cin >> str;
//    cout << str << endl;
    int n = str.size();
    vector<vector<int>> dp(n , vector<int>(2,INT_MAX));
    if(str[0] == '1'){
        dp[0][0] = 1;
        dp[0][1] = 0;
    }else{
        dp[0][0] = 0;
        dp[0][1] = 1;
    }
    for(int i = 1; i < n; i++){
        if(str[i] == '1'){
            dp[i][0] = dp[i-1][1] + 1;
            dp[i][1] = dp[i-1][0];
        }else{
            dp[i][0] = dp[i-1][1];
            dp[i][1] = dp[i-1][0] + 1;
        }
    }

    cout <<  min(dp[n-1][0], dp[n-1][1]) << endl;

    return 0;
}