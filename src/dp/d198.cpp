#include <iostream>
using namespace std;


class Solution {
public:
	/*
		状态: dp[i].第i家能抢到的最大值
		状态转移方程:
			第i家抢，此时第i-1家不能抢
			dp[i] = dp[i-2] + nums[i];
			第i家不抢，此时dp[i]
			dp[i] = dp[i-1];
	*/
	int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
		vector<int> dp(nums.size(), 0);
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		
		for (int i = 2; i < nums.size(); i++) {
			dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
		}
		return dp[nums.size()-1];
	}
};

int main() {
  Solution s;
  vector<int> t = {1,2,3,1};
  cout << s.rob(t) << endl;
}
