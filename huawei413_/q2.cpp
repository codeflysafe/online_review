//
// Created by sjhuang on 2022/4/13.
//


// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace  std;

// 时间优先、 奖金优先
bool cmp(vector<int> task1, vector<int> task2){
    if(task1[0] != task2[0]) return task1[0] < task2[0];
    else return task1[1] > task2[1];
}

int main()
{
    // please define the C++ input here. For example: int a,b; cin>>a>>b;;
    // please finish the function body here.
    // please define the C++ output here. For example:cout<<____<<endl;
    int N;
    cin >> N;
    // 所有的任务
    vector<vector<int>> tasks(N, vector<int>(2,0));
    int sla = 0;
    for(int i =0 ;i < N; i++){
        cin >> tasks[i][0] >> tasks[i][1];
        sla = max(sla, tasks[i][0]);
    }
    // 暴力的方法
    int cur = 0, ans = 0,sz = 0;
    queue<vector<int>> q;
    for(int i = 0; i < N; i++){
        if(tasks[i][1] > cur){
            // idx, score
            ans = max(ans, tasks[i][1]);
            q.push({i, tasks[i][1]});
        }
    }
    while(cur < sla){
        sz = q.size();
        for(int i =0; i < sz; i++){
            vector<int> node = q.front();
            q.pop();
            int idx = node[0], score = node[1];
            for(int j = idx + 1; j < N; j++){
                if(tasks[j][1] > cur){
                    ans = max(ans, score + tasks[j][1]);
                    q.push({j, score + tasks[j][1]});
                }
            }
        }
        cur ++;
    }

    cout << cur << endl;

    return 0;
}

//
////
//// Created by sjhuang on 2022/4/13.
////
//
//
//// we have defined the necessary header files here for this problem.
//// If additional header files are needed in your program, please import here.
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//
//using namespace  std;
//
//// 时间优先、 奖金优先
//bool cmp(vector<int> task1, vector<int> task2){
//    if(task1[0] != task2[0]) return task1[0] < task2[0];
//    else return task1[1] > task2[1];
//}
//
//int main()
//{
//    // please define the C++ input here. For example: int a,b; cin>>a>>b;;
//    // please finish the function body here.
//    // please define the C++ output here. For example:cout<<____<<endl;
//    int N;
//    cin >> N;
//    // 所有的任务
//    vector<vector<int>> tasks(N, vector<int>(2,0));
//    int sla = 0;
//    for(int i =0 ;i < N; i++){
//        cin >> tasks[i][0] >> tasks[i][1];
//        sla = max(sla, tasks[i][0]);
//    }
//    sort(tasks.begin(), tasks.end(), cmp);
//    int scores = 0;
//    int prev = -1;
//    for(int i = 0; i < N; i++){
//        if(tasks[i][0] != prev){
//            scores += tasks[i][1];
//        }
//        prev = tasks[i][0];
//    }
//
//    cout << scores << endl;
//    return 0;
//}
