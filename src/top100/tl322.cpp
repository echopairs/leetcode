#include <iostream>
#include <vector>
using namespace std;

/*
    // 不选的场景
    dp[i][j] = dp[i-1][j];
    // 选的场景
    dp[i][j] = dp[i-1][j-coins[i]) + 1;
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<std::vector<int> > dp(coins.size() + 1, std::vector<int>(amount+1, -1));
	dp[0][0] = 0;
	for (int i = 1; i <= coins.size(); i++) {
	    dp[i][0] = 0;
	    for (int j = 0; j <= amount; j++) {
		if (j- coins[i-1] >= 0 && dp[i][j - coins[i-1]] != -1) {
		    if (dp[i-1][j] == -1) {
			dp[i][j] = dp[i][j-coins[i-1]] + 1;
		    } else {
			dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]] + 1);
		    }
		} else {
		    dp[i][j] = dp[i-1][j];
		}

		cout << "dp[" << i << "][" << j << "]:" << dp[i][j] << endl;
	    }
	}
	return dp[coins.size()][amount];
    }
};

int main() {
    Solution slu;
    vector<int> coins = {1, 2, 5};
    cout << slu.coinChange(coins, 11) << endl;
}
