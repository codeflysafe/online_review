//
// Created by sjhuang on 2022/4/13.
//

#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;
// we have defined the necessary header files here FOR this problem.
// IF additional header files are needed IN your program, please IMPORT here.
int main()
{
    // please define the C input here. FOR EXAMPLE: int n; scanf("%d",&n);
    // please finish the FUNCTION body here.
    // please define the C output here. FOR EXAMPLE: printf("%d",a);
    int n;
    cin >> n;
    vector<int> items(n,0);
    int sum = 0;
    for(int i =0 ;i < n; i++){
        cin >> items[i];
        sum += items[i];
    }

    if(sum % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }
    int target = sum/2;
//    vector<vector<bool>> dp(n+1, vector<bool>(target+1,false));
    vector<bool> dp(target + 1, false);
    vector<vector<int>> path(target+1, vector<int>());
    dp[0] = true;
    for(int i =0; i <= target; i++){
        path[i] = {};
    }
    for(int i = 1; i <= n; i++){
        for(int j = target; j >= items[i-1]; j--){
            if(dp[j]) continue;
            if(dp[j - items[i-1]]){
                vector<int> tmp = path[j-items[i-1]];
                tmp.push_back(i-1);
                path[j] = tmp;
            }
            dp[j] = dp[j-items[i-1]];
        }
//        for(int j = items[i]; j<= target; j++){
//            // 选了和没选
//            dp[i][j] = dp[i-1][j-items[i]] | dp[i-1][j];
//        }
    }

    if(dp[target]){
        cout << target << endl;
        vector<int> curPath = path[target];
        unordered_set<int> vis;
        int k = curPath.size();
        cout << items[curPath[0]];
        vis.insert(curPath[0]);
        for(int t= 1; t < k; t++){
            vis.insert(curPath[t]);
            cout << " " << items[curPath[t]];
        }
        cout << endl;
        bool first = true;
        for(int i =0 ; i < n; i++){
            if(vis.count(i) == 0){
                if(first) {
                    cout << items[i];
                    first = false;
                }
                else cout << " " << items[i];
            }
        }
        cout << endl;
    }else cout << -1 << endl;

    return 0;
}
