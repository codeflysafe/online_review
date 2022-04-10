#include <iostream>
#include <vector>
#include <map>
using namespace  std;

int main(){
    int n;
    cin >> n;
    map<int, vector<int>> colors;
    int a;
    for(int i = 0;i < n; i++){
        cin >> a;
        if(colors.count(a) == 0){
            colors[a] = {i};
        }else{
            colors[a].push_back(i);
        }
    }
    vector<int> ans;
    for(auto p: colors){
        if(p.second.size() == 1){
            ans.push_back(p.first);
        }else{
            int offset = p.second[1] - p.second[0];
            int prev =  p.second[1];
            bool ok = true;
            for(int i = 2; i < p.second.size(); i++){
                if(p.second[i] - prev != offset){
                    ok = false;
                    break;
                }
                prev = p.second[i];
            }
            if(ok) ans.push_back(p.first);
        }
    }

    int t = ans.size();
    cout << t << endl;
    for(int idx : ans){
        if(colors[idx].size() > 1){
            cout << idx << " "<< colors[idx][1] - colors[idx][0]<< endl;
        }else{
            cout <<  idx << " " << 0 << endl;
        }
    }
    return 0;
}