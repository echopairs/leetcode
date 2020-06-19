//
// Created by pairs on 12/18/19.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        for (auto it = coins.begin(); it != coins.end();) {
            if (*it > amount) {
                it = coins.erase(it);
            } else if (*it == amount) {
                return 1;
            } else {
                ++it;
            }
        }
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= coins.size(); i++) {
            for (int j = coins[i-1]; j <= amount; j++) {
                if (dp[j - coins[i-1]] != -1) {
                    if (dp[j] == -1) {
                        dp[j] = dp[j - coins[i-1]] + 1;
                    } else {
                        dp[j] = min(dp[j], dp[j - coins[i-1]] + 1);
                    }
                }
            }
        }
        return dp[amount];
    }
    int coinChangePlus(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);     // -1 代表不可用
        dp[0] = 0;  // 当j为0时, 不需要任何硬币

        for (int i = 1; i <= coins.size(); i++) {
            for (int j = coins[i-1]; j <= amount; j++) {
                /*
                 *  不取: dp[j] = dp[j]
                 */
                if (dp[j-coins[i-1]] != -1) {
                    // means ok
                    if (dp[j] == -1) {
                        dp[j] = dp[j - coins[i-1]] + 1;
                    } else {
                        dp[j] = min(dp[j], dp[j - coins[i-1]] + 1);
                    }
                }
            }
        }
        return dp[amount];
    }
};

int main() {
    Solution slu;
    vector<int> t1 = {1, 2, 5};
    vector<int> t2 = {2};
    cout << slu.coinChange(t1, 11) << endl;     // 3
    cout << slu.coinChange(t2, 3)  << endl;     // -1

    cout << slu.coinChangePlus(t1, 11) << endl;     // 3
    cout << slu.coinChangePlus(t2, 3)  << endl;     // -1
}
