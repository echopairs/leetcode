//
// Created by pairs on 11/27/19.
//

#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    /*
     * dp[i][j] 到 i, j的路径
     * dp[i][j] = dp[i-1][j] + dp[i][j-1]
     * */
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i - 1 >= 0) {
                    dp[i][j] += dp[i-1][j];
                }
                if (j - 1 >= 0) {
                    dp[i][j] += dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    Solution s;
    cout << s.uniquePaths(3, 2) << endl;
}