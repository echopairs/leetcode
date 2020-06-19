// Created by pairs on 12/3/19.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }

        int hold = -prices[0];
        int cooldown = 0;
        int free = 0;

        for (int i = 1; i < prices.size(); i++) {
            int nh = max(hold, free - prices[i]);
            int nc = hold + prices[i];
            int nf = max(free, cooldown);
	    hold = nh;
	    cooldown = nc;
	    free = nf;
        }
        return max(free, cooldown);
    }
};

int main() {
    Solution s;
    vector<int> t = {1, 2, 3, 0, 2};
    cout << s.maxProfit(t) << endl;
}
