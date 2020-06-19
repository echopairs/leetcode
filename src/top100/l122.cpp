#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
	    return 0;
	}
	vector<int> buy(prices.size()), sell(prices.size());
	buy[0] = -prices[0];
	sell[0] = 0;
	for (int i = 1; i < prices.size(); i++) {
	    buy[i] = max(buy[i-1], sell[i-1] - prices[i]); // 注意和只有一次交易的对比
	    sell[i] = max(sell[i-1], buy[i-1] + prices[i]);
	}
	return sell[prices.size()-1];
    }
};

int main() {
    Solution slu;
    vector<int> t = {1,2,3,4,5};
    cout << slu.maxProfit(t) << endl;
}
