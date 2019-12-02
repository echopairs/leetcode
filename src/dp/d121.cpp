#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
  /*
    分析: 一次买卖求最大值，求第i天为卖出状态的最大值为prices[i] - 前i天最小值。所以需要保存更新前i-1天之前买入的最小值，同时保存和更新
    最大值。
  */
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        int least = prices[0];
        int maxP = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] >= least) {
                maxP = max(maxP, prices[i] - least);
            } else {
                least = prices[i];
            }
        }
        return maxP;
    }
};

int main() {
  Solution s;
  vector<int> t = {7, 1, 5, 3, 6, 4};
  cout << s.maxProfit(t) << endl;
}
