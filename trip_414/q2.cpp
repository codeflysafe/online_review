//
// Created by sjhuang on 2022/4/14.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using  namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n,0);
    for(int i =0; i < n; i++){
        cin >> nums[i];
    }
    string colors;
    cin >> colors;
    unordered_map<int, int> rcounts, bcounts;
    for(int i = 0; i < n; i++){
        if(colors[i] == 'R'){
            rcounts[nums[i]] ++;
        }else{
            bcounts[nums[i]] ++;
        }
    }
    long long ans = 0;
    for(auto p: rcounts){
        if(bcounts.count(p.first) > 0){
            ans += p.second * bcounts[p.first];
        }
    }

    cout << ans << endl;

    return 0;
}