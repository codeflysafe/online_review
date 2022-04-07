//
// Created by sjhuang on 2022/3/14.
//

#include <vector>
#include <string>
#include <iostream>

using namespace  std;


// 去除连通的
int dfs(vector<vector<char>> &matrix, int x, int y, char c){
    if(x >= 8 || y >= 8 || x < 0 || y < 0 || matrix[x][y] != c) return 0;
    // 标记成 '*' 已经消除
    matrix[x][y] = '*';
    int top = dfs(matrix, x + 1, y, c);
    int down = dfs(matrix, x - 1, y, c);
    int left = dfs(matrix, x , y + 1, c);
    int right = dfs(matrix, x , y - 1, c);
    return top + down + left + right + 1;
}

// 填充 matrix
void full_fill(vector<vector<char>> &matrix, char direction, vector<string> &fill){
    // 上下落
    if(direction == 'w' || direction == 's') {
        // 向上
        if(direction == 'w'){
            for(int i = 0; i < 8; i++){
                int j = 0;
                while(j < 8){
                    if(matrix[j][i] == '*'){
                        // 需
                        int k = j + 1;
                        while(k < 8 && matrix[k][i] == '*'){
                            k++;
                        }
                        //
                        if(k < 8){
                            matrix[j][i] = matrix[k][i];
                            matrix[k][i] = '*';
                        }
                        j = k;
                    }else j ++;
                }
            }
        }else{
            for(int i = 0; i < 8; i++){
                int j = 7;
                while(j >= 0){
                    if(matrix[j][i] == '*'){
                        // 需要下落
                        int k = j - 1;
                        while(k >= 0 && matrix[k][i] == '*'){
                            k--;
                        }
                        //
                        if(k >= 0){
                            matrix[j][i] = matrix[k][i];
                            matrix[k][i] = '*';
                        }
                        j = k;
                    }else j --;
                }
            }
        }
        for(int i = 0; i < 8; i++){
            // 上下
            string str = fill[i];
            int k = 0;
            for(int j = 0; j < 8; j++) {
                if(matrix[j][i] == '*') {
                    matrix[j][i] = str[k++];
                }
            }
            fill[i] = str.substr(k,str.size() - k);
        }

    }else {
        if(direction == 'a') {
            // 左右落
            for (int i = 0; i < 8; i++) {
                int j = 0;
                while (j < 8) {
                    if (matrix[i][j] == '*') {
                        // 需要左落
                        int k = j + 1;
                        while (k < 8 && matrix[i][k] == '*') {
                            k++;
                        }
                        //
                        if (k < 8) {
                            matrix[i][j] = matrix[i][k];
                            matrix[i][k] = '*';
                        }
                        j = k;
                    } else j++;
                }
            }
        }else{
            for(int i = 0; i < 8; i++){
                int j = 7;
                while(j >= 0){
                    if(matrix[i][j] == '*'){
                        // 需要下落
                        int k = j - 1;
                        while(k >= 0 && matrix[i][k] == '*'){
                            k--;
                        }
                        //
                        if(k >= 0){
                            matrix[i][j] = matrix[i][k];
                            matrix[i][k] = '*';
                        }
                        j = k;
                    }else j --;
                }
            }
        }
        for(int i = 0; i < 8; i++){
            string str = fill[i];
            int k = 0;
            for(int j = 0; j < 8; j++) {
                if(matrix[i][j] == '*') {
                    matrix[i][j] = str[k++];
                }
            }
            fill[i] = str.substr(k,str.size() - k);
        }
    }
}

int main(){
    int n;
    cin >> n;
    // 游戏矩阵
    vector<vector<char>> matrix(8, vector<char>(8,'r'));
    // 待填充的字符串
    vector<string> fill(8,"");
    string str;
    for(int i = 0; i < 8; i++){
        cin >> str;
        for(int j = 0; j < 8; j++){
            matrix[i][j] = str[j];
        }
    }

    for(int i = 0; i < 8; i++){
        cin >> str;
        fill[i] = str;
    }

    int x, y;
    char op;
//    int ans = 0;
    for(int i= 0 ; i < n; i++){
        cin >> x >> y >> op;
        int ans = dfs(matrix, x-1, y-1, matrix[x][y]);
        cout << ans << endl;
        full_fill(matrix,op, fill);
    }

    return 0;
}