//
// Created by pairs on 12/13/19.
//
#include <iostream>
#include <vector>
using namespace std;

/*
    状态定义:
    firstBuy[i]: 第i天处于第一次买入的状态最大值
    firstSell[i]: 第i天处于第一次卖出的状态最大值
    secondBuy[i]: 第i天处于第二次买入的状态最大值
    secondSell[i]: 第i天处于第二次卖出的状态最大值

    状态转移方程:
    firstBuy[i] = max(firstBuy[i-1], -prices[i]);
    firstSell[i] = max(firstSell[i-1], firstBuy[i-1]+prices[i])
    secondBuy[i] = max(secondBuy[i-1], firstSell[i-1]-prices[i])
    secondSell[i] = max(secondSell[i-1], secondBuy[i-1]+prices[i])
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        vector<int> firstBuy(prices.size()), firstSell(prices.size()), secondBuy(prices.size()), secondSell(prices.size());
        firstBuy[0] = -prices[0];
        firstSell[0] = 0;
        secondBuy[0] = -99999;
        secondSell[0] = 0;

        for (int i = 1; i < prices.size(); i++) {
            firstBuy[i] = max(firstBuy[i-1], -prices[i]);
            firstSell[i] = max(firstSell[i-1], firstBuy[i-1] + prices[i]);
            secondBuy[i] = max(secondBuy[i-1], firstSell[i-1] - prices[i]);
            secondSell[i] = max(secondSell[i-1], secondBuy[i-1] + prices[i]);
        }
        return max(firstSell[prices.size()-1], secondSell[prices.size()-1]);
    }
    /* 优化从状态转移方程可以得知第i天只跟第i-1天的结果,所以空间上还可以再次优化
     * */
    int maxProfitPlus(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        // firstBuy,firstSell,secondBuy,secondSell
        int help[4] = {-prices[0], 0, -prices[0], 0};
        int temp[4] = {0, 0, 0, 0};

        for (int i = 1; i < prices.size(); i++) {
            temp[0] = max(help[0], -prices[i]);
            temp[1] = max(help[1], help[0] + prices[i]);
            temp[2] = max(help[2], help[1] - prices[i]);
            temp[3] = max(help[3], help[2] + prices[i]);

            help[0] = temp[0];
            help[1] = temp[1];
            help[2] = temp[2];
            help[3] = temp[3];
        }
        return max(help[1], help[3]);
    }
};

int main() {
    Solution s;
    std::vector<int> t = {3,3,5,0,0,3,1,4};
//    cout << s.maxProfit(t) << endl;
    cout << s.maxProfitPlus(t) << endl;

    std::vector<int> t2 = {1, 2, 3, 4, 5};
//    cout << s.maxProfit(t2) << endl;
    cout << s.maxProfitPlus(t2) << endl;
}
