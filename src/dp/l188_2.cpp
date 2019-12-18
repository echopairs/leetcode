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

        if (k > prices.size() / 2) {
            k = prices.size() / 2;
        }

        vector <vector<int>> sell(prices.size() + 1, vector<int>(k + 1));
        vector <vector<int>> buy(prices.size() + 1, vector<int>(k + 1));

        /*  状态:
         *  sell[i][j]  第i天,进行第j次卖出时的最大值
         *  buy[i][j]   第i天,进行第j次买入时的最大值
         *  状态转移方程:
         *  sell[i][j] = max(sell[i-1][j], buy[i-1][j] + prices[i-1]);  第i-1天已经卖出j次,或者第i天卖出第j次
         *  buy[i][j] = max(buy[i-1][j], sell[i-1][j-1] - prices[i-1]); 第i-1天已经买入j次,或者第i天买入第j次
         */
        // 初始化,第一天
        for (int j = 1; j <= k; j++) {
            buy[1][j] = -prices[0];
        }

        for (int i = 2; i <= prices.size(); i++) {
            buy[i][1] = max(buy[i-1][1], -prices[i-1]);
            sell[i][1] = max(sell[i-1][1], buy[i-1][1] + prices[i-1]);
            for (int j = 1; j <= k; j++) {
                sell[i][j] = max(sell[i-1][j], buy[i-1][j] + prices[i-1]);
                buy[i][j] = max(buy[i-1][j], sell[i-1][j-1] - prices[i-1]);
            }
        }

        int res = 0;
        for (int i = 0; i <= k; i++) {
            res = max(res, sell[prices.size()][i]);
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
    cout << slu.maxProfit(1, t1) << endl;   // 1
    cout << slu.maxProfit(2, t2) << endl;   // 3
    cout << slu.maxProfit(2, t3) << endl;   // 6
    cout << slu.maxProfit(2, t4) << endl;   // 7
}
