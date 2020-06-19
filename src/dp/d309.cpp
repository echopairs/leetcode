//
// Created by pairs on 12/3/19.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            sell[i] <- 第i天为卖出状态最大值
            buy[i] <- 第i天为持有股票最大值
            cooldown[i] <- 第i天为冷静状态的最大值

            // 第i天为卖出状态，则第i-1天必须是持有股票的状态
            sell[i] = buy[i-1] + prices[i];

            // 第i天为持有股票状态，则第i-1天可以为买入状态,或者第i-1天为cooldown,第i天为买入
            buy[i] = max(buy[i-1], cooldown[i-1]-prices[i])

            // 第i天为cooldown, 则第i-1天可以为cooldown或者第i-1天为sell
            cooldown[i] = max(cooldown[i-1], sell[i-1]);

            初始值：
            buy[0] = -prices[0];
            sell[0] = 0;
            cooldown[0] = 0;
        */
        vector<int> sell(prices.size());
        vector<int> buy(prices.size());
        vector<int> cooldown(prices.size());
        buy[0] = -prices[0];
        sell[0] = 0;
        cooldown[0] = 0;

        for (int i = 1; i < prices.size(); i++) {
            sell[i] = buy[i-1] + prices[i];
            buy[i] = max(buy[i-1], cooldown[i-1]-prices[i]);
            cooldown[i] = max(cooldown[i-1], sell[i-1]);
	    //cout << "i: " << i << " sell " << sell[i] << " buy " << buy[i] << " cooldown " << cooldown[i] << endl;
        }
        return max(sell[prices.size()-1], cooldown[prices.size()-1]);
    }
};


int main() {
    Solution s;
    vector<int> t = {1, 2, 3, 0, 2};
    cout << s.maxProfit(t) << endl;
}
