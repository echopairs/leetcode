//
// Created by pairs on 11/27/19.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /*
     *状态： dp[i][j] 为到点(i, j)位置总共有多少条路径
     * 状态转移方程:
     *  if num[i][j] == 0
     *      dp[i][j] = dp[i-1][j] + dp[i][j-1]
     *  else:
     *      dp[i][j] = 0
     * */
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<double> > dp(obstacleGrid.size(), vector<double>(obstacleGrid[0].size(), 0));
        for (int i = 0; i < obstacleGrid.size(); i++) {
            for (int j = 0; j < obstacleGrid[0].size(); j++) {
                if (obstacleGrid[i][j] == 0) {
                    if (i == 0 && j == 0) {
                        dp[i][j] = 1;
                    }
                    if (i - 1 >= 0) {
                        dp[i][j] = dp[i-1][j];
                    }
                    if (j - 1 >= 0) {
                        dp[i][j] += dp[i][j-1];
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};

int main() {
    Solution s;
    vector<vector<int> > t = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
    };
    cout << s.uniquePathsWithObstacles(t) << endl;
}