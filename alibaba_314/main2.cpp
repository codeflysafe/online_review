//
// Created by sjhuang on 2022/3/14.
//

#include <vector>
#include <iostream>

using  namespace  std;

int main(){
    int n, m;
    cin >> n >> m;
    // 输入矩阵
    vector<vector<int>> matrix(n, vector<int>(m,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m ;j++){
            cin >> matrix[i][j];
        }
    }

    int ans = 0;
    // 向左、右面照射
    for(int i = 0; i < n; i++){
        int left = 0, right = 0;
        for(int j = 0; j < m; j++){
            // 如果是电灯
            if(matrix[i][j] == 0){
                ans += left;
            }else{
                // 如果不是
                left = 1;
            }
        }

        for(int j = m - 1; j >= 0; j--){
            // 如果是电灯
            if(matrix[i][j] == 0){
                ans += right;
            }else{
                // 如果不是
                right = 1;
            }
        }
    }

    // 向前面照射
    for(int i = 0; i < m; i++){
        int top = 0, down = 0;
        for(int j = 0; j < n; j++){
            // 如果是电灯
            if(matrix[j][i] == 0){
                ans += top;
            }else{
                // 如果不是
                top = 1;
            }
        }

        for(int j = n - 1; j >= 0; j--){
            // 如果是电灯
            if(matrix[j][i] == 0){
                ans += down;
            }else{
                // 如果不是
                down = 1;
            }
        }
    }

    cout << ans << endl;
    return 0;

}
