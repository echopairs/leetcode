
//
// Created by pairs on 11/27/19.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /*
     * 状态: dp[i][j] 为从(0, 0)第i行第j列最小路径和
     * 状态转移方程: dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + num[i][j]
     *
     * */
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        vector<vector<int> > dp(grid.size(), vector<int>(grid[0].size()));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                dp[i][j] = grid[i][j];
                if (i == 0 && j == 0) {
                    continue;
                }
                int help = 9999999;
                if (i-1 >= 0) {
                    help = dp[i-1][j];
                }
                if (j-1 >= 0) {
                    help = min(help, dp[i][j-1]);
                }
                dp[i][j] += help;
                cout << dp[i][j] << " " ;
             }
            cout << endl;
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};

int main() {
    Solution s;
    vector<vector<int> > t = {
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}
    };
    cout << s.minPathSum(t) << endl;
}