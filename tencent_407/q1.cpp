//
// Created by sjhuang on 2022/4/7.
//

//todo 整数分配题目

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @param k int整型
     * @return int整型
     */
    int numsOfStrings(int n, int k) {
        // write code here
        long long ans = 26,mod = 1000000;
        int free = n - k*2;
        for(int i =0; i < k-1; i++){
            ans = (ans * 25)%mod;
        }
        if(free > 0){
            ans = (((ans * free)%mod)* k)%mod;
        }
        return ans;
    }
};