//
// Created by pairs on 12/18/19.
//
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

class Solution {
public:
    /*
     *
     *  dp[i][j]; 前i个元素，是否能装载到大小为j的空间内
     *  dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]
     */
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) {
            return false;
        }
        int middle = sum / 2;
        vector<vector<bool>> dp(nums.size(), vector<bool>(middle+1, false));
        for (int j = 0; j <= middle; j++) {
            // 第一个数字是否能装入大小为j的容器中
            if (nums[0] == j) {
                dp[0][j] = true;
            }
        }

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j <= middle ; j++) {
                dp[i][j] = dp[i-1][j];
                if (j >= nums[i]) {
                    dp[i][j] = dp[i][j] | dp[i-1][j-nums[i]];
                }
            }
        }
        return dp[nums.size()-1][middle];
    }

    bool canPartitionP(vector<int>& nums) {
        /*
         *  dp[i][j] 到第i个元素为止,是否能装入到j大小的容器中
         *  dp[i][j] = dp[i-1][j] | dp[i-1][j-nums[i-1]](if j >= nums[i-1])
         *  初始化: dp[0][0] = true    // 没有元素,大小容器为0则为true
         */
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) {
            return false;
        }
        int middle = sum / 2;
        std::vector<vector<bool> > dp(nums.size() + 1, vector<bool>(middle + 1, false));
        dp[0][0] = true;

        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 0; j <= middle; j++) {
                dp[i][j] = dp[i-1][j];
                if (j >= nums[i-1]) {
                    dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[nums.size()][middle];
    }

    /*
     * 滚动数组应用, 根据上述可知道第i层元素dp[i][j] 只依赖于 dp[i-1][k]层,
     * 所以在空间上可以优化只需要一个数组, 因为dp[i][j], 依赖于第i-1层j之前
     * 的元素，所以在计算dp[i][j]时, dp[i-1][k] 不能被覆盖，所以需要从后往前
     * 计算
     */
    bool canPartitionPlus(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) {
            return false;
        }
        int middle = sum / 2 ;
        std::vector<bool>dp(middle + 1, false);
        dp[0] = true;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = middle; j >= nums[i-1]; j--) {
                // 当j < nums[i-1], 此时不需要更新
                dp[j] = dp[j] || dp[j-nums[i-1]];
            }
        }
        return dp[middle];
    }
};

int main() {
    vector<int> t1 = {1, 5, 11, 5}; // true
    vector<int> t2 = {1, 2, 3, 5};  // false

    Solution slu;
    cout << slu.canPartitionP(t1) << endl;
    cout << slu.canPartitionP(t2) << endl;

    cout << slu.canPartitionPlus(t1) << endl;
    cout << slu.canPartitionPlus(t2) << endl;
}