class Solution {
public:
    /*
      求最大连续子序列和。设状态dp[i]为以i为结尾的最大连续序列的和，
      状态转移方程:
        当dp[i-1] > 0 时 dp[i] = dp[i-1] + nums[i]
        否则: dp[i] = nums[i];
    */
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        vector<int> dp(nums.size());
        int maxS = dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = nums[i];
            if (dp[i-1] > 0) {
                dp[i] += dp[i-1];
            }
            maxS = max(maxS, dp[i]);
        }
        return maxS;
    }
};

int main() {
  // todo
}
