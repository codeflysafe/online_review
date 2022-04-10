//
// Created by sjhuang on 2022/4/10.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;


// bfs
int steps(vector<vector<char>> &tables, int n, int m, int xi, int yi){
    // n 行
    // m 列
    queue<int> q;
    q.push(xi*m + yi);
    unordered_set<int> vis;
    vis.insert(xi*m + yi);
    int sz = 0, step = 0;
    while (!q.empty()){
        sz = q.size();
        for(int i = 0; i < sz; i++){
            int idx = q.front();
            q.pop();
            int x = idx/m, y = idx%m;
            // 上下、前后
            // 上
            if(x-1 >= 0 && tables[x-1][y] != '0'){
                if(x-2 >= 0 && y - 1 >= 0){
                    if(tables[x-2][y-1] == 'T'){
                        return step+1;
                    }else if(tables[x-2][y-1] == '1' && vis.count((x-2)*m + y-1) == 0){
                        vis.insert((x-2)*m + y-1);
                        q.push((x-2)*m + y-1);
                    }
                }

                if(x-2 >= 0 && y + 1 < m){
                    if(tables[x-2][y + 1 ] == 'T'){
                        return step+1;
                    }else if(tables[x-2][y + 1 ] == '1' && vis.count((x-2)*m + y+ 1) == 0){
                        vis.insert((x-2)*m + y + 1 );
                        q.push((x-2)*m + y+ 1);
                    }
                }
            }
            // 下
            if(x + 1 < n && tables[x+1][y] != '0'){
                if(x + 2 < n  && y - 1 >= 0){
                    if(tables[x+ 2][y-1] == 'T'){
                        return step+1;
                    }else if(tables[x+ 2][y-1] == '1' && vis.count((x+ 2)*m + y-1) == 0){
                        vis.insert((x+ 2)*m + y-1);
                        q.push((x+ 2)*m + y-1);
                    }
                }
                if(x + 2 < n && y + 1 < m){
                    if(tables[x+2][y + 1 ] == 'T'){
                        return step+1;
                    }else if(tables[x+2][y + 1 ] == '1' && vis.count((x+2)*m + y+ 1) == 0){
                        vis.insert((x+2)*m + y + 1 );
                        q.push((x+2)*m + y+ 1);
                    }
                }


            }

            // 左
            if(y-1 >= 0 && tables[x][y-1] != '0'){
                if(y- 2 >= 0 && x -1 >= 0){
                    if(tables[x -1][y-2] == 'T'){
                        return step+1;
                    }else if(tables[x-1][y-2] == '1' && vis.count((x-1)*m + y-2) == 0){
                        vis.insert((x-1)*m + y-2);
                        q.push((x-1)*m + y-2);
                    }
                }

                if(y- 2 >= 0 && x  + 1 <n ){
                    if(tables[x+1][y-2] == 'T'){
                        return step+1;
                    }else if(tables[x+1][y-2] ==  '1' && vis.count((x+1)*m + y-2) == 0){
                        vis.insert((x+1)*m + y-2);
                        q.push((x+1)*m + y-2);
                    }
                }
             }

                // 右
                if(y + 1 < m && tables[x][y+1] != '0'){
                    if(y + 2 < m && x -1 >= 0){
                        if(tables[x -1][y + 2] == 'T'){
                            return step+1;
                        }else if(tables[x-1][y + 2] == '1' && vis.count((x-1)*m + y+ 2) == 0){
                            vis.insert((x-1)*m + y+ 2);
                            q.push((x-1)*m + y+2);
                        }
                    }

                    if(y + 2 < m && x + 1 < n){
                        if(tables[x + 1][y + 2] == 'T'){
                            return step+1;
                        }else if(tables[x+1][y + 2] == '1' && vis.count((x+1)*m + y+ 2) == 0){
                            vis.insert((x+1)*m + y+ 2);
                            q.push((x+1)*m + y+2);
                        }
                    }

                }
        }
        step++;
    }
    return -1;
}




int main(){
    int t;
    int n, m;
    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> n >> m;
        vector<vector<char>> tables(n, vector<char>(m,' '));
        int x = -1, y = -1;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                cin >> tables[j][k];
                if(tables[j][k] == 'K'){
                    x = j, y = k;
                }
            }
        }
        cout << steps(tables,n,m, x, y) << endl;
    }
    return 0;
}