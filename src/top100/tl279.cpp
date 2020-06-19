//
// Created by pairs on 12/18/19.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if (n == 1) {
            return 1;
        }
        vector<int> prices;
        int i = 1;
        while(i*i < n) {
            prices.emplace_back(i*i);
            i++;
            if (i*i == n) {
                return 1;
            }
        }
        // dp[i][j] 恰好放满, 代表前i个放入空间大小为j的最小数
	vector<int> dp(n+1, -1);
	dp[0] = 0;

	for (int i = 0; i < prices.size(); i++) {
	    for (int j = prices[i]; j <= n; j++) {
		if (dp[j-prices[i]] != -1) {
		    if (dp[j] == -1) {
			dp[j] = dp[j-prices[i]] + 1;
		    } else {
			dp[j] = min(dp[j], dp[j-prices[i]] + 1);
		    }
		}
	    } 
	}
	return dp[n];
    }

    int numSquaresPlus(int n) {
        // build vector
        vector<int> nums;
        for (int i = 1; i*i <= n; i++) {
            if (i * i == n) {
                return 1;
            } else {
                nums.emplace_back(i*i);
            }
        }

        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = nums[i-1]; j <= n; j++) {
                if (dp[j-nums[i-1]] != -1) {
                    if (dp[j] == -1) {
                        dp[j] = dp[j-nums[i-1]] + 1;
                    } else {
                        dp[j] = min(dp[j], dp[j-nums[i-1]] + 1);
                    }
                }
            }
        }
        return dp[n];
    }
};

int main() {
    Solution slu;
    cout << slu.numSquaresPlus(12) << endl;     // 4 + 4 + 4 = 12
    cout << slu.numSquaresPlus(13) << endl;     // 4 + 9 = 13
}
