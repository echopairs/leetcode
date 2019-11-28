//
// Created by pairs on 11/27/19.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /*
     * dp[n] 代表到n位置的方法
     * 最后一步时1 or 最后一步是 2
     * dp[n] = dp[n-1] + dp[n-2];
     * 空间优化
     * */
    int climbStairs(int n) {
        if (n <= 1) {
            return n;
        }
        int f1 = 1;
        int f2 = 2;
        for (int i = 3; i <= n; i++) {
            f2 += f1;
            f1 = f2 - f1;
        }
        return f2;
    }
};

int main() {
    Solution s;
    cout << s.climbStairs(1) << endl;
    cout << s.climbStairs(2)<< endl;
    cout << s.climbStairs(3) << endl;
    cout << s.climbStairs(4) << endl;
    cout << s.climbStairs(5) << endl;
 }