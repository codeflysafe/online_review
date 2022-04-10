//
// Created by sjhuang on 2022/4/10.
//

//
// Created by sjhuang on 2022/4/10.
//

#include <vector>
#include <iostream>
#include <set>

using  namespace std;


int main(){
    long n, m, q, site;
    cin >> n >> m;
    set<long> vis;
    for(long i = 1; i <= m; i++){
        vis.insert(i);
    }
    // n 个 已经被选中的座位
    for(long i =0 ;i < n; i++){
        cin >> site;
        vis.erase(site);
    }
    cin >> q;
    vector<vector<int>> cmds(q,vector<int>(2,0));
    for(long i = 0; i < q; i++){
        cin >> cmds[i][0] >> cmds[i][1];
    }
    for(long i =0 ;i < q; i++){
        long l = cmds[i][0], r = cmds[i][1];
        auto p1 = vis.lower_bound(l);
        if(*p1 >= l && *p1 <= r){
            cout << *p1 << endl;
            vis.erase(p1);
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}