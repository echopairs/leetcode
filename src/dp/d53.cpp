//
// Created by pairs on 11/27/19.
//
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /* 因为求连续的子序列
         * 状态: dp[i]: 以第i个元素为结尾的最大sum值
         * 状态转移方程:
         *  if (dp[i-1] > 0) {
         *      dp[i] = dp[i-1] + nums[i];
         *  } else {
         *      dp[i] = nums[i];
         *  }
         *
        */
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int res = max(0, dp[0]);
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = nums[i];
            if (dp[i-1] > 0) {
                dp[i] += dp[i-1];
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> t = {-2,1,-3,4,-1,2,1,-5,4};
    cout << s.maxSubArray(t) << endl;
}