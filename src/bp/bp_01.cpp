//
// Created by pairs on 12/17/19.
//
#include <iostream>
#include <vector>
using namespace std;

int backpack(std::vector<int> &price, std::vector<int> &volume, int tag) {
    vector<vector<int>> dp(price.size() + 1);
    for (int i = 0; i < dp.size(); i++) {
        dp[i].resize(tag + 1);
    }
    dp[0][0] = 0;
    // 第一行, 没有物品，容量为i
    for (int i = 1; i < tag + 1; i++) {
        dp[0][i] = 0;
    }

    // 第一列, 有物品，容量为0
    for (int j = 1; j < price.size() + 1; j++) {
        dp[j][0] = 0;
    }

    // i, j
    for (int i = 1; i < price.size() + 1; i++) {
        for (int j = 1; j < tag + 1; j++) {
            // 选择不放
            dp[i][j] = dp[i-1][j];
            if (j >= volume[i-1]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j - volume[i-1]] + price[i-1]);
            }
        }
    }
    return dp[price.size()][tag];
}

int zeroOneBp(std::vector<int>& price, std::vector<int>& volume, int tag) {
    /*
     * 状态:
     * dp[i][j] 到第i为止空间为j的最大值
     *
     * 状态转移方程:
     * 第i个不取: dp[i][j] = dp[i-1][j]
     * 第i个取: dp[i][j] = dp[i-1][j-volume[i]] + price[i]
     *
     * 初始化:
     * dp[i][0] = 0
     * dp[0][j] = price[0] if j >= volume[0]
     * */
    vector<vector<int> > dp(price.size(), vector<int>(tag + 1));

    for (int j = 0; j <= tag; j++) {
        if (j >= volume[0]) {
            dp[0][j] = price[0];
        }
    }

    for (int i = 1; i < price.size(); i++) {
        for (int j = 0; j <= tag; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= volume[i]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-volume[i]] + price[i]);
            }
        }
    }
    return dp[price.size()-1][tag];
}

int zeroOneBpPlus(std::vector<int>& price, std::vector<int>& volume, int tag) {
    /*
     * 状态:
     * dp[i][j] 到第i为止空间为j的最大值
     * 状态转移方程:
     * 第i个不取: dp[i][j] = dp[i-1][j]
     * 第i个取: dp[i][j] = dp[i-1][j-volume[i]] + price[i]
     *
     * 根据状态转移方程可知到第i个的最大值只和到第i-1个值相关,所有空间上可以优化(滚动数组)
    */
    vector<int> dp(tag + 1);

    // 初始化
    for (int j = 0; j <= tag; j++) {
        if (j >= volume[0]) {
            dp[j] = price[0];
        }
    }


    for (int i = 1; i < price.size(); i++) {
        /*
         * (i-1, j-volume[i]) (i-1, j),
         *                    (i, j)
         *  当计算(i,j)点值的时候,需要依赖上一次计算的(i-1, j-volume[i]) 和 (i-1, j),
         *  也就是说当计算(i,j)值时,(i-1, j-volume[i]) 值还未被(i, j-volume[i]覆盖，所以此时需要从后往前计算
        */
        for (int j = tag; j >= volume[i]; j--) {
            dp[j] = max(dp[j], dp[j-volume[i]] + price[i]);
        }
    }
    return dp[tag];
}

int main() {
    std::vector<int> volume = {2, 2, 6, 5, 4};	// 物品的重量
    std::vector<int> price = {6, 3, 5, 4, 6};	// 物品的价值

    cout << backpack(price, volume, 10) << endl;    // 15
    cout << zeroOneBp(price, volume, 10) << endl;
    cout << zeroOneBpPlus(price, volume, 10) << endl;
}