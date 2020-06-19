//
// Created by pairs on 12/19/19.
//

/*
小偷深夜潜入一家珠宝店，店里有5类宝物，体积分别为W{1,3,2,4,5}，对应的价值为V{200,100,300,150,350 }，
对应各类宝物的数量分别为N{2,1,3,4,2}。小偷随身只携带了一个容量为5的背包，问小偷应如何选择才能使偷得宝物的价值最大？
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int ZeroOneBackPack(vector<int>&dp, int volume, int price, int target) {
        /*
	 *  01背包,需要target->k
         */
	 for (int j = target; j >= volume; j--) {
	    dp[j] = max(dp[j], dp[j-volume] + price);
	 }
    }

    int CompleteBackPack(vector<int>&dp, int volume, int price, int target) {
        /*
	 *  完全背包,需要1->target
         */
	 for (int j = volume; j <= target; j++) {
	    dp[j] = max(dp[j], dp[j-volume] + price);
	 }
    }

    int MultipleBackPack(vector<int> &price, vector<int> &volume, vector<int> &num, int target) {
        vector<int> dp(target + 1);
	/*
	    通过二进制优化-> num[i]个元素可以优化为 1 2 4 ... 2^k-1, num[i] - 2^k+1
	*/
	for (int i = 1; i <= price.size(); i++) {
	    if (target <= num[i-1] * volume[i-1]) {
		// 能装下所有
		CompleteBackPack(dp, volume[i-1], price[i-1], target);
	    } else {
		// 否则将多重背包转化为01背包
		int k = 1;
		while (k < num[i-1]) {
		    ZeroOneBackPack(dp, k*volume[i-1], k*price[i-1], target);
		    k = 2*k;
		}
		int last = num[i-1] - k + 1;
		ZeroOneBackPack(dp, last*volume[i-1], last*price[i-1], target);
	    }
	}
	return dp[target];
    }
};

int main() {
    vector<int> price = {200, 100, 300, 150, 350};
    vector<int> volume = {1, 3, 2, 4, 5};
    vector<int> num = {2, 1, 3, 4 , 2};
    //    cout << mbackpack(price, volume, num, 5) << endl;   // 800
    Solution slu;
    cout << slu.MultipleBackPack(price, volume, num, 5) << endl;
}

