//
// Created by pairs on 12/18/19.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int n, int m) {
        vector<vector<int>> dp(n + 1, vector<int>(m+1, 0));
        for (int i = 0; i < strs.size(); i++) {
            int cntZero = 0;
            int cntOne = 0;
            for (auto c : strs[i]) {
                if (c == '0') {
                    cntZero++;
                } else {
                    cntOne++;
                }
            }
            // 滚动数组
            for (int j = n; j >= cntZero; j--) {
                for (int k = m; k >= cntOne; k--) {
                    dp[j][k] = max(dp[j][k], dp[j-cntZero][k-cntOne] + 1);
                }
            }
        }
        return dp[n][m];
    }
};


int main() {
    Solution slu;
    vector<string> v = {"10", "0001", "111001", "1", "0"};
    cout << slu.findMaxForm(v, 5, 3) << endl;       // 4

    vector<string> v2 = {"10", "0", "1"};
    cout << slu.findMaxForm(v2, 1, 1) << endl;
}
