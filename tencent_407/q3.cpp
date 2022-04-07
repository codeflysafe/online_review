class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串
     * @return int整型
     */
    int minCnt(string s) {
        // write code here
        int n = s.size();
        vector<int> ones(n,0);
        int one = s[n-1] == '1' ? 1:0;
        for(int i = n-2; i >= 0; i--){
            ones[i] = one;
            one += s[i] == '1'?1:0;
        }
        int ans = n;
        for(int i = 0; i < n; i++){
            ans = min(ans, i + ones[i]);
        }
        return ans;
    }
};