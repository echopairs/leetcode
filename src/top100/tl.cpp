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
	vector<int> dp(amount + 1, -1);
	/*
	    装入大小为0的容器则为0
	*/
	dp[0] = 0;
	for (int i = 0; i < coins.size(); i++) {
	    for (int j = coins[i]; j <= amount; j++) {	
		if (dp[j-coins[i]] != -1) {
		    if (dp[j] == -1) {
			dp[j] = dp[j-coins[i]] + 1;
		    }else {
			dp[j] = min(dp[j], dp[j-coins[i]] + 1);
		    }
		}
	    }
	}
	return dp[amount];
    }
};

int main() {
    Solution slu;
    vector<int> coins = {1, 2, 5};
    cout << slu.coinChange(coins, 11) << endl;
}
