//
// Created by sjhuang on 2022/4/10.
//

#include <vector>
#include <iostream>

using  namespace std;

// 采用线段树,cur 处增加1
void add(vector<int> &tree, int l, int r, int index, int cur){
    if(l == r){
        tree[index] ++;
        return;
    }
    int m = l + ((r-l) >> 1);
    if(cur <= m){
        add(tree,l,m, index*2+1, cur);
    }else{
        add(tree, m+1,r, index*2+2, cur);
    }
    tree[index] = tree[index * 2 + 1] +  tree[index * 2 + 2];
}

int range(vector<int> &tree, int l, int r, int index, int left, int right){
    if(l == left && right == r){
        return tree[index];
    }
    int m = l + ((r-l) >> 1);
    if(left <= m && right > m){
        return range(tree, l, m, index*2+1, left, m) + range(tree, m+1, r, index*2+2, m+1, right);
    }else if(left > m){
        return range(tree, m+1, r, index*2+2, left, right);
    }else{
        return range(tree, l, m, index*2+1, left, right);
    }
}


int main(){
    int n, m, q, site;
    cin >> n >> m;
    // 树状数组
    int N = 4*m+1;
    vector<int> tree(N,0);
    // n 个 已经被选中的座位
    for(int i =0 ;i < n; i++){
        cin >> site;
        add(tree,1, m,0,site);
    }
    cin >> q;
    int l, r;
    for(int i =0 ;i < q; i++){
        cin >> l >> r;
        if(range(tree,1,m,0,l,r) > 0){
            cout << -1 << endl;
        }else{
            cout << l << endl;
            add(tree,1,m,0,l);
        }
    }

    return 0;
}