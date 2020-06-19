//
// Created by pairs on 12/18/19.
//
#include <vector>
#include <iostream>
using namespace std;

/*
小偷深夜潜入一家珠宝店，店里有5类宝物，体积分别为W{1,3,2,4,5}，对应的价值为V{200,100,300,150,350 }，
对应各类宝物的数量分别为N{2,1,3,4,2}。小偷随身只携带了一个容量为5的背包，问小偷应如何选择才能使偷得宝物的价值最大？
*/

int mbackpack(vector<int> &price, vector<int> &volume, vector<int> &num, int target) {
    vector<int> dp(target + 1);
    for (int i = 1; i <= price.size(); i++) {
        for (int j = 0; j <= target; j++) {
            // 取和不取两种情况
            // dp[j] = max(dp[j], dp[j - volume[i-1]] + price[i-1];
            if (j >= volume[i-1] && num[i-1] > 0) {
                if (dp[j] < (dp[j-volume[i-1]] + price[i-1])) {
                    dp[j] = dp[j-volume[i-1]] + price[i-1];
                    num[i-1] -= 1;
                }
            }
        }
    }
    return dp[target];
}

int KBackPack(vector<int> &price, vector<int> &volume, vector<int> &num, int target) {
    vector<int> dp (target + 1);
    for (int i = 1; i <= price.size(); i++) {
        for (int j = 1; j <= target; j++) {
            if (j >= volume[i-1] && num[i-1] > 0) {
                if (dp[j] < (dp[j-volume[i-1]] + price[i-1])) {
                    dp[j] = dp[j-volume[i-1]] + price[i-1];
                    num[i-1] -= 1;
                }
            }
        }
    }
    return dp[target];
}


int main() {
    vector<int> price = {200, 100, 300, 150, 350};
    vector<int> volume = {1, 3, 2, 4, 5};
    vector<int> num = {2, 1, 3, 4 , 2};
//    cout << mbackpack(price, volume, num, 5) << endl;   // 800
    cout << KBackPack(price, volume, num, 5) << endl;   // 800
}
