//
// Created by sjhuang on 2022/4/13.
//

#include <iostream>
#include <vector>
#include <list>
#include <string>

using  namespace  std;


int main(){
    int n, m;
    cin >> n >> m;
    // 从第 2 行到第 m+1 行，第 j 行给出了编号为 j-1 的物品的基本数据，每行有 3 个非负整数 v p
    int v,p,q;
    // 他希望在花费不超过 N 元的前提下，使自己的满意度达到最大。
    // 满意度是指所购买的每件物品的价格与重要度的乘积的总和
    // pv 满意度 , p 是指花费
    vector<vector<int>> scores(m,vector<int>());
    vector<vector<int>> costs(m,vector<int>());
    for(int i = 0; i < m; i++){
        cin >> v >> p >> q;
        // 是主件
        if(q == 0){
            // 放到前面
            costs[i].insert(costs[i].begin(),v);
            scores[i].insert(scores[i].begin(),v*p);
        }else{
            // 是附件
            costs[q-1].push_back(v);
            scores[q-1].push_back(v*p);
        }
    }

    // 背包问题
    // dp[i][j] 代表
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 10; i <= n; i+=10){
        for(int j = 1; j <= m; j++){
            if(costs[j-1].empty()) continue;
            int curMax = 0;
            // 选了 dp[i[[j]
            if(i >= costs[j-1][0]){
                curMax = dp[i-costs[j-1][0]][j-1] + scores[j-1][0];
                int curSecond = 0;
                int t = i - costs[j-1][0];
                for(int k = 1; k < costs[j-1].size(); k++){
                    if(i-costs[j-1][0] - costs[j-1][k] >= 0){
                        curSecond = max(curSecond, dp[i-costs[j-1][0] - costs[j-1][k]][j-1] + scores[j-1][1]);
                    }
                }
            }
            dp[i][j] = max(curMax, dp[i][j-1]);
        }
    }

    cout << dp[n][m] << endl;


    return 0;
}