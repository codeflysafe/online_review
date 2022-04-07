#include <iostream>
#include <vector>
#include <string>
using namespace  std;


int main() {
    string num;
    cin >> num;
    vector<int> dp = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
    int n = num.size();
    int ans = 0;
    for(int i = 2; i < n; i++){
        if(num[i] >= '0' && num[i] <= '9'){
            ans += dp[num[i] - '0'];
        }else {
            ans += dp[(num[i] - 'a') + 10];
        }
    }

    cout << ans << endl;

    return 0;
}
