# online_review

## 腾讯 4.07 笔试题
ac两道，开局出师不利

[我的code](tencent_407)
### 第一道
思路是组合数学分配

第一组可以选择有26种，其它组均为25种，这样就是
`26*25^{k-1}`
但是还有剩余的 free = n - k*2;

问题在于如何分配这些free的变量,这里就是我没想好，感觉是一个整数分配问题

```c++
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
```

`ac`了`40%`， 开门拉垮

### 第二道

模拟题
采用优先队列，每次将最大的减掉-x。

```c++
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
```

### 第三道

这道题就比较简单了，对于每一为`1`的字符，下标为i来说，它的更改代价为

`左边元素的个数i + 右边1的个数`

遍历的同时比较即可


```c++
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
```