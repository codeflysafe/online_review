//
// Created by sjhuang on 2022/4/7.
//
#include <iostream>
#include <queue>
#include <vector>
using  namespace  std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param a int整型vector
     * @param k int整型
     * @param x int整型
     * @return int整型
     */
    int minMax(vector<int>& a, int k, int x) {
        // write code here
        priority_queue<int, vector<int>, less<int>> q;
        for(int i: a){
            q.push(i);
        }
        for(int i =0; i < k; i++){
            int num = q.top();
            q.pop();
            q.push(num - x);
        }
        return q.top();
    }
};

int main(){
    Solution sc;
    vector<int> a = {7,2,1};
    cout << sc.minMax(a, 3,2);
    return 0;
}