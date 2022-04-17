//
// Created by sjhuang on 2022/4/14.
//

#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using  namespace  std;

int mod = 1000000007;
vector<vector<int>> cnks(10,vector<int>(10, -1));

int power(int n, int t){
    if(n == 0) return 1;
    else if(n == 1) return t;
    else if( n % 2 == 0){
        int k = power(n/2, t) % mod;
        return (k * k)  % mod;
    }else return t * power(n-1,t);
}

// C^{k}_N 计算这个
int ckn(int n, int k){
    if(cnks[n][k] != -1){
        return cnks[n][k];
    }else{
        if(k == 1) {
            cnks[n][1] = cnks[n][n-1] = n;
            return cnks[n][1];
        }
        long long cur = n, next = 1;
        for(int i = 1; i <= k; i++){
            cur = (cur * (n-i))%mod ;
            next = (next * (i + 1))%mod;
            cnks[n][i] = cnks[n][n-i]  =  int(cur/next);
        }
        return cnks[n][k];
    }
}

int main(){

    string str;
    getline(cin, str);
    cout << str << endl;
    // 0,9,18,27,36,45,54,63,72,81
    // 组成的个数
    vector<int> counts(10,0);
    for(char c: str){
        counts[c-'0'] ++;
    }
    vector<int> sums (10,0);
    sums[0] = power(counts[0],2) - 1;
    sums[9] =  power(counts[9],2) - 1;
    long long ans = sums[0] + sums[9];
    for(int i = 1; i <= 4; i++){
        int j = 9 - i;
        // 计算个数 a,b
        int a = counts[i], b = counts[j];
        int ss = 0;
        for(int t = 1; t <= min(a,b); t++){
            ss = (ss +  (ckn(a,t) * ckn(b,t)) % mod) % mod;
        }
        sums[i] = ss;
        ans += sums[i];
    }

    long long  st = (sums[0] * sums[9]) % mod;
    for(int i = 1; i <= 4; i++){
       if(sums[i] > 0){
          st = ( st * sums[i]) %mod;
       }
    }

    cout <<  (ans + st ) %mod << endl;

}