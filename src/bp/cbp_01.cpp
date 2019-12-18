//
// Created by pairs on 12/18/19.
//
#include <vector>
#include <iostream>
using namespace std;

int cbackpack(std::vector<int> &price, std::vector<int> &volume, int tag) {
    vector<int> dp(tag + 1, 0);
    for(int i = 1; i < price.size() + 1; i++) {
        for (int j = 0; j <= tag; j++) {
            if (j >= volume[i-1]) {
                dp[j] = max(dp[j], dp[j - volume[i-1]] + price[i-1]);
            }
        }
    }
    return dp[tag];
}

int CBackPack(vector<int>&prices, vector<int> &volume, int tag) {
    vector<vector<int>> dp(prices.size() + 1, vector<int>(tag+1));
    for (int i = 1; i <= prices.size(); i++) {
        for (int j = 1; j <= tag; j++) {
            for (int k = 0; k * volume[i-1] <= j; k++) {
                dp[i][j] = max(dp[i][j], dp[i-1][j- k*volume[i-1]] + k *prices[i-1]);
            }
        }
    }
    return dp[prices.size()][tag];
}

/*利用滚动数组优化*/
int CBackPackPlus(std::vector<int> &price, std::vector<int> &volume, int tag) {
    vector<int> dp(tag + 1);
    for (int i = 1; i <= price.size(); i++) {
        for (int j = tag; j >= 1; j--) {
            for (int k = 0; k * volume[i-1] <= j; k++) {
                dp[j] = max(dp[j], dp[j-k*volume[i-1]] + k * price[i-1]);
            }
        }
    }
    return dp[tag];
}

/*
 * 从01背包从后往前运算优化而来
 * 滚动数组中之所以需要从后往前计算是因为如果从前往后计算此时dp[k]的值已经是包含该次物品的最大值,这恰恰是i可以取无数次
 * */
int CBackPackPlusFromZeroOne(std::vector<int> &price, std::vector<int> &volume, int tag) {
    vector<int> dp(tag + 1);
    for (int i = 1; i <= price.size(); i++) {
        for (int j = 1; j <= tag; j++) {
            if (j >= volume[i-1]) {
                dp[j] = max(dp[j], dp[j - volume[i-1]] + price[i-1]);
            }
        }
    }
    return dp[tag];
}

int main() {
    std::vector<int> volume = {2, 2, 6, 5, 4};  // 物品的重量
    std::vector<int> price = {6, 3, 5, 4, 6};   // 物品的价值

    cout << cbackpack(price, volume, 10) << endl;   // 30

    cout << CBackPack(price, volume, 10) << endl;   // 30

    cout << CBackPackPlus(price, volume, 10) << endl;   // 30

    cout << CBackPackPlusFromZeroOne(price, volume, 10) << endl;   // 30
}