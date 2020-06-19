#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProtit(vector<int>& prices) {
	if (prices.size() <= 1) {
	    return 0;
	}
	int buy = -prices[0];
	int sell = 0;

	for (int i = 1; i < prices.size(); i++) {
	    sell = max(sell, buy + prices[i]);
	    buy = max(buy, -prices[i]);	 
	}
	return sell;
    }
};

int main() {
    Solution slu;
    vector<int> t1 = {7,1,5,3,6,4};
    cout << slu.maxProtit(t1) << endl;

    vector<int> t2 = {7,6,4,3,1};
    cout << slu.maxProtit(t2) << endl;
}
