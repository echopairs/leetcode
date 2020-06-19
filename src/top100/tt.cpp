//
// Created by pairs on 12/16/19.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        if (prices.size() <= 1 || k == 0) {
            return 0;
        }

        if (k > prices.size()/2) {
            k = prices.size()/2;
        }

        vector<vector<int> > sell(prices.size(), vector<int>(k+1));
        vector<vector<int> > buy(prices.size(), vector<int>(k+1));

        // 第一天初始化
        // buy[i][j]: 第i天第j次买入最大值
        // sell[i][j]: 第i天第j次卖出最大值
        for (int j = 0; j <= k; j++) {
            buy[0][j] = -prices[0];
            sell[0][j] = 0;
        }
        for (int i = 1; i < prices.size(); i++) {
            buy[i][1] = -prices[i];	// 第一次买
            sell[i][1] = max(sell[i-1][1], buy[i-1][1] + prices[i]);
            for (int j = 1; j <= k; j++) {
                buy[i][j] = max(buy[i-1][j], sell[i-1][j-1] - prices[i]);
                sell[i][j] = max(sell[i-1][j], buy[i-1][j] + prices[i]);
//                cout <<"sell[" << i << "][" << j << "]:" << sell[i][j] << endl;
//                cout << "buy[" << i << "][" << j << "]:"<< buy[i][j] << endl;
            }
        }

        int res = 0;
        for (int i = 0; i <= k; i++) {
            res = max(res, sell[prices.size()-1][i]);
        }
        return res;
    }
};
int main() {
    Solution slu;
    std::vector<int> t1 = {1, 2};
    std::vector<int> t2 = {1, 2, 4};
    std::vector<int> t3 = {4,4,6,1,1,4,2,5};
    std::vector<int> t4 = {3,2,6,5,0,3};
//    cout << slu.maxProfit(1, t1) << endl;   // 1
//    cout << slu.maxProfit(2, t2) << endl;   // 3
//    cout << slu.maxProfit(2, t3) << endl;   // 6
//    cout << slu.maxProfit(2, t4) << endl;   // 7
    std::vector<int> t5 = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
    cout << slu.maxProfit(4, t5) << endl;
}


