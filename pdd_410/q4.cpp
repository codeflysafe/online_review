    //
    // Created by sjhuang on 2022/4/10.
    //

    #include <vector>
    #include <iostream>
    #include <algorithm>

    using  namespace  std;
    int main(){
        int m, n, x;
        cin >> m >> n >> x;
        vector<int> intervals(m,0);
        for(int i = 0; i < m; i++){
            cin >> intervals[i];
        }
        if(m == 0){
            cout << 0 << endl;
            return 0;
        }
        // 从小到达排序
        sort(intervals.begin(), intervals.end());
        int k = intervals[m-1];
        int i = m - n - 1;
        int ans = k + x;
        while(i >= 0){
            ans += max(0, 2*x + intervals[i] - k);
            k = intervals[i];
            i -= n;
        }
        cout << ans << endl;
        // do something
        return 0;
    }
