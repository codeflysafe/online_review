
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
// 策略1 cpu 优先
bool cmp1(vector<int> p1, vector<int> p2){
    if(p1[1] != p2[1]) return p1[1] < p2[1];
    else if(p1[2] != p2[2]) return p1[2] < p2[2];
    else return p1[0] < p2[0];
}

// 内存优先
bool cmp2(vector<int> p1, vector<int> p2){
    if(p1[2] != p2[2]) return p1[2] < p2[2];
    else if(p1[1] != p2[1]) return p1[1] < p2[1];
    else return p1[0] < p2[0];
}


int main()
{
    // please define the C++ input here. For example: int a,b; cin>>a>>b;;
    // please finish the function body here.
    // please define the C++ output here. For example:cout<<____<<endl;
    int m;
    cin >> m;
    string str;
    int n, strategy, cpuCount, memSize, cupArch, supportNP;
    vector<vector<int>> machines(m, vector<int>(5,0));
    for(int i = 0; i < m; i++){
        cin >> str;
        int prev = 0;
        int k = 0;
        for(int j = 0; j < str.size(); j++){
            if(str[j]==','){
                machines[i][k] = prev;
                prev = 0;
                k++;
            }else{
                prev = prev* 10 + (int)(str[j] - '0');
            }
        }
        machines[i][4] = prev;
        // 编号、cpu、内存、cpu架构、是否支持加速
        // cin >> machines[i][0] >> machines[i][1] >> machines[i][2] >> machines[i][3] >>  machines[i][4];
    }
    cin >> n >> strategy >>  cpuCount >>  memSize >> cupArch >> supportNP;
    if(strategy == 1){
        // 策略1
        sort(machines.begin(), machines.end(), cmp1);
    }else{
        // 策略2
        sort(machines.begin(), machines.end(), cmp2);
    }

    int cnt = 0;
    vector<int> res;
    // todo
    for(vector<int> machine: machines){
        // cout << machine[0] << machine[1] << machine[2] << machine[3] << machine[4] << endl;
        if(strategy == 1){
            if(machine[1] >=  cpuCount && machine[2] >= memSize && (machine[3] == cupArch || cupArch == 9) && (machine[4] == supportNP || supportNP == 2)){
                if(cnt < n){
                    res.push_back(machine[0]);
                    cnt++;
                }

            }
        }else {
            if(machine[1] >=  cpuCount && machine[2] >= memSize && (machine[3] == cupArch || cupArch == 9)&& (machine[4] == supportNP || supportNP == 2)){
                if(cnt < n){
                    res.push_back(machine[0]);
                    cnt++;
                }
            }
        }
    }

    cout << cnt;
    sort(res.begin(), res.end());
    for(int m: res){
        cout << " " << m;
    }
    cout << endl;

    return 0;
}
